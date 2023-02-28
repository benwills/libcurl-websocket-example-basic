#include <stdio.h>
#include <curl/curl.h>

#define URL "wss://ws.postman-echo.com/raw"

static void websocket_close(CURL *curl)
{
  size_t sent;
  CURLcode result = curl_ws_send(curl, "", 0, &sent, 0, CURLWS_CLOSE);
  printf("ws: curl_ws_send(close) returned %u, sent %u\n",
                  (int)result, (int)sent);
  fflush(stdout);
}

static void websocket(CURL *curl)
{
  char buffer[256] = {0};
  struct curl_ws_frame *meta = NULL;
  size_t nread = 0;
  size_t i = 0;
  FILE *save = fopen("./wstest.out.txt", "w");
  if (!save) {
  	printf("ERR: could not open output file");
    return;
  }

  CURLcode res = CURLE_OK;
  size_t sent = 0;
  for (int iter = 0; iter < 3; iter++)
  {
  	printf("\n\n----------------\n");
	  res = curl_ws_send(curl, "testMsg", 7, &sent, 0, CURLWS_TEXT);
	  printf("\nws: curl_ws_send returned %u, sent %u\n", (int)res, (int)sent);
    fflush(stdout);

    res = curl_ws_recv(curl, buffer, sizeof(buffer), &nread, &meta);
    if (res) {
      printf("\ncurl_ws_recv returned %d\n", (int)res);
      return;
    }
    printf("\ncurl_ws_recv received data: %.*s\n", (int)nread, buffer);
    printf("%d: nread %d Age %d Flags %d "
           "Offset %d "
           "Bytesleft %d\n",
           (int)i, (int)nread, (int)meta->age, (int)meta->flags,
           (int)meta->offset, (int)meta->bytesleft);
    fflush(stdout);
    i += meta->len;
    fwrite(buffer, 1, nread, save);
	}

	fclose(save);

  websocket_close(curl);
}

int main()
{
  CURL *curl = NULL;
  CURLcode res = CURLE_OK;

  curl_global_init(CURL_GLOBAL_ALL);

  curl = curl_easy_init();
  if (curl) {
    curl_easy_setopt(curl, CURLOPT_URL, URL);
    // use the callback style
    curl_easy_setopt(curl, CURLOPT_USERAGENT, URL);
    curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L); // debugging
    curl_easy_setopt(curl, CURLOPT_CONNECT_ONLY, 2L); // websocket style
    res = curl_easy_perform(curl);
    printf("\ncurl_easy_perform() returned %u\n", (int)res);
    if (res == CURLE_OK) {
      websocket(curl);
    }

    curl_easy_cleanup(curl);
  }

  curl_global_cleanup();
  return (int)res;
}
