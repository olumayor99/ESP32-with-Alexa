#include <Arduino.h>
#include <WiFi.h>;
#include <WebSocketsClient.h> //  https://github.com/kakopappa/sinric/wiki/How-to-add-dependency-libraries
#include <ArduinoJson.h> // https://github.com/kakopappa/sinric/wiki/How-to-add-dependency-libraries
#include <StreamString.h>

WebSocketsClient webSocket;
WiFiClient client;

// Wifi details
const char* WIFI_SSID = "b3c0b6";
const char* WIFI_PASS = "330166541";

#define MyApiKey "d458754a-6470-45fe-acb8-ca9028f500b0" // TODO: Change to your sinric API Key. Your API Key is displayed on sinric.com dashboard
#define HEARTBEAT_INTERVAL 300000 // 5 Minutes 

// Relay pins
#define relayPin_1 16
#define relayPin_2 17
#define relayPin_3 18
#define relayPin_4 19
#define relayPin_5 21
#define relayPin_6 22
#define relayPin_7 23
#define relayPin_8 25

#define SERIAL_BAUDRATE 115200

uint64_t heartbeatTimestamp = 0;
bool isConnected = false;

void setPowerStateOnServer(String deviceId, String value);
void setTargetTemperatureOnServer(String deviceId, String value, String scale);

void conn() {
  // WiFi connection
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  Serial.print("Connecting to sinric.com");
  
  // to check wifi status, whether connected or not
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);                                  //prints "." every 1000ms while attepting to connect
  }

  // server address, port and URL
  webSocket.begin("iot.sinric.com", 80, "/");

  // event handler
  webSocket.onEvent(webSocketEvent);
  webSocket.setAuthorization("apikey", MyApiKey);
  
  // try again every 5000ms if connection has failed
  webSocket.setReconnectInterval(5000);   // If you see 'class WebSocketsClient' has no member named 'setReconnectInterval' error update arduinoWebSockets
}

// deviceId is the ID assgined to your smart-home-device in sinric.com dashboard. Copy it from dashboard and paste it here

// Switch device on
void turnOff(String deviceId) {
  if (deviceId == "5d7d0ebbf1dce8012dfee6a6") // Device ID of first device
  {  
    Serial.print("Turn off device id: ");
    Serial.println(deviceId);
    
     digitalWrite(relayPin_1, HIGH); // turn on relay with voltage HIGH
  }
  else if (deviceId == "5d7d0ec9f1dce8012dfee6ae") // Device ID of second device
  {  
    Serial.print("Turn off device id: ");
    Serial.println(deviceId);
    
     digitalWrite(relayPin_2, HIGH); // turn on relay with voltage HIGH
  }
  else if (deviceId == "5d7d0ed2f1dce8012dfee6b3") // Device ID of third device
  {  
    Serial.print("Turn off device id: ");
    Serial.println(deviceId);
    
     digitalWrite(relayPin_3, HIGH); // turn on relay with voltage HIGH
  }
  else if (deviceId == "5d7d0ee4f1dce8012dfee6b8") // Device ID of fourth device
  {  
    Serial.print("Turn off device id: ");
    Serial.println(deviceId);
    
     digitalWrite(relayPin_4, HIGH); // turn on relay with voltage HIGH
  }
  else if (deviceId == "5d7d0eeef1dce8012dfee6bd") // Device ID of fifth device
  {  
    Serial.print("Turn off device id: ");
    Serial.println(deviceId);
    
     digitalWrite(relayPin_5, HIGH); // turn on relay with voltage HIGH
  }
  else if (deviceId == "5d7d0ef6f1dce8012dfee6c2") // Device ID of sixth device
  {  
    Serial.print("Turn off device id: ");
    Serial.println(deviceId);
    
     digitalWrite(relayPin_6, HIGH); // turn on relay with voltage HIGH
  }
  else if (deviceId == "5d7d0f00f1dce8012dfee6c7") // Device ID of seventh device
  {  
    Serial.print("Turn off device id: ");
    Serial.println(deviceId);
    
     digitalWrite(relayPin_7, HIGH); // turn on relay with voltage HIGH
  }
  else if (deviceId == "5d7d0f09f1dce8012dfee6cc") // Device ID of eight device
  {  
    Serial.print("Turn off device id: ");
    Serial.println(deviceId);
    
     digitalWrite(relayPin_8, HIGH); // turn on relay with voltage HIGH
  }
  else {
    Serial.print("Turn off for unknown device id: ");
    Serial.println(deviceId);    
  }     
}

// Switch device on
void turnOn(String deviceId) {
   if (deviceId == "5d7d0ebbf1dce8012dfee6a6") // Device ID of first device
   {  
     Serial.print("Turn on Device ID: ");
     Serial.println(deviceId);
     
     digitalWrite(relayPin_1, LOW);  // turn off relay with voltage LOW
   }
   else if (deviceId == "5d7d0ec9f1dce8012dfee6ae") // Device ID of second device
   {  
     Serial.print("Turn on Device ID: ");
     Serial.println(deviceId);
     
     digitalWrite(relayPin_2, LOW);  // turn off relay with voltage LOW
   }
   else if (deviceId == "5d7d0ed2f1dce8012dfee6b3") // Device ID of third device
   {  
     Serial.print("Turn on Device ID: ");
     Serial.println(deviceId);
     
     digitalWrite(relayPin_3, LOW);  // turn off relay with voltage LOW
   }
   else if (deviceId == "5d7d0ee4f1dce8012dfee6b8") // Device ID of fourth device
   {  
     Serial.print("Turn on Device ID: ");
     Serial.println(deviceId);
     
     digitalWrite(relayPin_4, LOW);  // turn off relay with voltage LOW
   }
   else if (deviceId == "5d7d0eeef1dce8012dfee6bd") // Device ID of fifth device
   {  
     Serial.print("Turn on Device ID: ");
     Serial.println(deviceId);
     
     digitalWrite(relayPin_5, LOW);  // turn off relay with voltage LOW
   }
   else if (deviceId == "5d7d0ef6f1dce8012dfee6c2") // Device ID of sixth device
   {  
     Serial.print("Turn on Device ID: ");
     Serial.println(deviceId);
     
     digitalWrite(relayPin_6, LOW);  // turn off relay with voltage LOW
   }
   else if (deviceId == "5d7d0f00f1dce8012dfee6c7") // Device ID of seventh device
   {  
     Serial.print("Turn on Device ID: ");
     Serial.println(deviceId);
     
     digitalWrite(relayPin_7, LOW);  // turn off relay with voltage LOW
   }
   else if (deviceId == "5d7d0f09f1dce8012dfee6cc") // Device ID of eight device
   {  
     Serial.print("Turn on Device ID: ");
     Serial.println(deviceId);
     
     digitalWrite(relayPin_8, LOW);  // turn off relay with voltage LOW
   }
   else {
     Serial.print("Turn on for unknown device id: ");
     Serial.println(deviceId);    
  }
}

void webSocketEvent(WStype_t type, uint8_t * payload, size_t length) {
  switch(type) {
    case WStype_DISCONNECTED:
      isConnected = false;    
      Serial.printf("Web Service disconnected from sinric.com!\n");
      conn();
      break;
    case WStype_CONNECTED: {
      isConnected = true;
      Serial.printf("\n"); 
      Serial.printf("Web Service connected to sinric.com at url: %s\n", payload);
      Serial.printf("Waiting for commands from sinric.com ...\n");        
      }
      break;
    case WStype_TEXT: {
        Serial.printf("[WSc] get text: %s\n", payload);
        // Example payloads

        // For Switch or Light device types
        // {"deviceId": xxxx, "action": "setPowerState", value: "ON"} // https://developer.amazon.com/docs/device-apis/alexa-powercontroller.html

        // For Light device type
        // Look at the light example in github
          
        DynamicJsonBuffer jsonBuffer;
        JsonObject& json = jsonBuffer.parseObject((char*)payload); 
        String deviceId = json ["deviceId"];     
        String action = json ["action"];
        
        if(action == "setPowerState") { // Switch or Light
            String value = json ["value"];
            if(value == "ON") {
                turnOn(deviceId);
            } else {
                turnOff(deviceId);
            }
        }
        else if (action == "SetTargetTemperature") {
            String deviceId = json ["deviceId"];     
            String action = json ["action"];
            String value = json ["value"];
        }
        else if (action == "test") {
            Serial.println("[WSc] received test command from sinric.com");
        }
      }
      break;
    case WStype_BIN:
      Serial.printf("[WSc] get binary length: %u\n", length);
      break;
  }
}

void setup() {
  // put your setup code here, to run once:
  
  // Initialize serial port
  Serial.begin(SERIAL_BAUDRATE);

  // Relay PIN eg: https://github.com/wemos/D1_mini_Examples/blob/master/examples/04.Shields/Relay_Shield/Blink/Blink.ino
  pinMode(relayPin_1, OUTPUT);
  pinMode(relayPin_2, OUTPUT);
  pinMode(relayPin_3, OUTPUT);
  pinMode(relayPin_4, OUTPUT);
  pinMode(relayPin_5, OUTPUT);
  pinMode(relayPin_6, OUTPUT);
  pinMode(relayPin_7, OUTPUT);
  pinMode(relayPin_8, OUTPUT);

  //WiFi connection
  conn();
  }

void loop() {
  // put your main code here, to run repeatedly:
  
  webSocket.loop();
  
  if(isConnected) {
      uint64_t now = millis();
      
      // Send heartbeat in order to avoid disconnections during ISP resetting IPs over night. Thanks @MacSass
      if((now - heartbeatTimestamp) > HEARTBEAT_INTERVAL) {
          heartbeatTimestamp = now;
          webSocket.sendTXT("H");          
      }
  }   
}

// If you are going to use a push button to on/off the switch manually, use this function to update the status on the server
// so it will reflect on Alexa app.
// eg: setPowerStateOnServer("deviceid", "ON")

// Call ONLY If status changed. DO NOT CALL THIS IN loop() and overload the server. 
void setPowerStateOnServer(String deviceId, String value) {
  DynamicJsonBuffer jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
  root["deviceId"] = deviceId;
  root["action"] = "setPowerState";
  root["value"] = value;
  StreamString databuf;
  root.printTo(databuf);
  
  webSocket.sendTXT(databuf);
}

//eg: setPowerStateOnServer("deviceid", "CELSIUS", "25.0")

// Call ONLY If status changed. DO NOT CALL THIS IN loop() and overload the server. 
void setTargetTemperatureOnServer(String deviceId, String value, String scale) {
  DynamicJsonBuffer jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
  root["action"] = "SetTargetTemperature";
  root["deviceId"] = deviceId;
  
  JsonObject& valueObj = root.createNestedObject("value");
  JsonObject& targetSetpoint = valueObj.createNestedObject("targetSetpoint");
  targetSetpoint["value"] = value;
  targetSetpoint["scale"] = scale;
   
  StreamString databuf;
  root.printTo(databuf);
  
  webSocket.sendTXT(databuf);
}
