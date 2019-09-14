# ESP32-with-Alexa
This is a code to connect ESP32 boards to Alexa using sinric.com.
I have only tested this code with a WEMOS LOLIN32 board I got from Aliexpress, and it worked well.
Huge credits go to kakopappa for his repository here https://github.com/kakopappa/sinric. Without his guide, I would be lost.
I surfed the web for code examples to connect ESP32 boards to Alexa via sinric.com and I couldn't find any, so I wrote this piece by reading another guide on https://randomnerdtutorials.com/alexa-echo-with-esp32-and-esp8266/ , and I was able to pick a few things I needed.
I am not a guru, I'm a total beginner, but I'm very sure this code works pretty well.

Requirements
1. Arduino IDE
2. Required libraries
  1. Arduino.h
  2. WiFi.h
  3. WebSocketsClient.h Installation guide here---> https://github.com/kakopappa/sinric/wiki/How-to-add-dependency-libraries
  4. ArduinoJson.h Installation guide here---> https://github.com/kakopappa/sinric/wiki/How-to-add-dependency-libraries
  5. StreamString.h
3. ESP32 boards (I'll update this list after achieving success with other boards)
   1. WEMOS LOLIN32
   
Notes
I initially had issues with the code initially, in the sense that, once it loses connection with the WiFi signal, it didn't reconnect, it just kept displaying "Web Service disconnected from sinric.com!". I sorted this out by calling the conn() function which was where I wrote the WiFi connection code.
