# libcurl-websocket-example-basic
Basic example of using libcurl to use a websocket connection


# Output from this code:
```
*   Trying 3.212.19.188:443...
* Connected to ws.postman-echo.com (3.212.19.188) port 443 (#0)
*  CAfile: /etc/ssl/certs/ca-certificates.crt
*  CApath: none
* SSL connection using TLSv1.2 / ECDHE-RSA-AES128-GCM-SHA256
* Server certificate:
*  subject: CN=postman-echo.com
*  start date: Jul 14 00:00:00 2022 GMT
*  expire date: Aug 12 23:59:59 2023 GMT
*  subjectAltName: host "ws.postman-echo.com" matched cert's "*.postman-echo.com"
*  issuer: C=US; O=Amazon; OU=Server CA 1B; CN=Amazon
*  SSL certificate verify ok.
> GET /raw HTTP/1.1
Host: ws.postman-echo.com
User-Agent: wss://ws.postman-echo.com/raw
Accept: */*
Upgrade: websocket
Connection: Upgrade
Sec-WebSocket-Version: 13
Sec-WebSocket-Key: UXisLdwsdUHzKKhhZuBD2A==

< HTTP/1.1 101 Switching Protocols
< Date: Tue, 28 Feb 2023 13:26:27 GMT
< Connection: upgrade
< Server: nginx
< Upgrade: websocket
< Sec-WebSocket-Accept: mqbnNgDUprDim1qI/G1JFLILTOA=
* Received 101, switch to WebSocket; mask 9418e1f7
< 
* Connection #0 to host ws.postman-echo.com left intact
* WS: send OPCODE TEXT
* WS: set FIN
* WS: send FIN bit 1 (byte 81)
* WS: send payload len 7
* WS: wanted to send 13 bytes, sent 13 bytes

curl_easy_perform() returned 0


----------------

ws: curl_ws_send returned 0, sent 7
* reached easy.c:1231
* WS: 9 bytes left to decode
* WS:235 received FIN bit 1
* WS: received OPCODE TEXT
* WS: received 7 bytes payload (0 left, buflen was 9)

curl_ws_recv received data: testMsg
0: nread 7 Age 0 Flags 1 Offset 0 Bytesleft 0
* WS: send OPCODE TEXT
* WS: set FIN
* WS: send FIN bit 1 (byte 81)
* WS: send payload len 7
* WS: wanted to send 13 bytes, sent 13 bytes


----------------

ws: curl_ws_send returned 0, sent 7
* reached easy.c:1231
* WS: 9 bytes left to decode
* WS:235 received FIN bit 1
* WS: received OPCODE TEXT
* WS: received 7 bytes payload (0 left, buflen was 9)

curl_ws_recv received data: testMsg
7: nread 7 Age 0 Flags 1 Offset 0 Bytesleft 0
* WS: send OPCODE TEXT
* WS: set FIN
* WS: send FIN bit 1 (byte 81)
* WS: send payload len 7
* WS: wanted to send 13 bytes, sent 13 bytes


----------------

ws: curl_ws_send returned 0, sent 7
* reached easy.c:1231
* WS: 9 bytes left to decode
* WS:235 received FIN bit 1
* WS: received OPCODE TEXT
* WS: received 7 bytes payload (0 left, buflen was 9)

curl_ws_recv received data: testMsg
14: nread 7 Age 0 Flags 1 Offset 0 Bytesleft 0
* WS: send OPCODE CLOSE
* WS: set FIN
* WS: send FIN bit 1 (byte 88)
* WS: send payload len 0
* WS: wanted to send 6 bytes, sent 6 bytes
ws: curl_ws_send(close) returned 0, sent 0
[Finished in 553ms]

```
