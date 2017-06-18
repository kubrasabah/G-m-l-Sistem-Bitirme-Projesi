/**
 * BasicHTTPClient.ino
 *
 *  
 *
 */

#include <Arduino.h>
#include <Servo.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>

#include <ESP8266HTTPClient.h>

#define USE_SERIAL Serial

ESP8266WiFiMulti WiFiMulti;
Servo servoNesnesiUst; 
Servo servoNesnesiAlt; 

void setup() {

    USE_SERIAL.begin(115200);
   // USE_SERIAL.setDebugOutput(true);
   servoNesnesiUst.attach(D1);
   servoNesnesiAlt.attach(D2);

    USE_SERIAL.println();
    USE_SERIAL.println();
    USE_SERIAL.println();
    servoNesnesiAlt.write(27);
    servoNesnesiUst.write(38);
    for(uint8_t t = 4; t > 0; t--) {
        USE_SERIAL.printf("[SETUP] WAIT %d...\n", t);
        USE_SERIAL.flush();
    }

    WiFiMulti.addAP("AndroidAP", "usgc5238");
  
}

void loop() {
    // wait for WiFi connection
    if((WiFiMulti.run() == WL_CONNECTED)) {

        HTTPClient http;

        USE_SERIAL.print("[HTTP] begin...\n");
        // configure traged server and url
        //http.begin("http://192.168.43.165/gomulu/index.php?mode=get"); //HTTP
        http.begin("http://kubrasabah.com/gomulu/index.php?mode=get"); //HTTP
        delay(1000);
        USE_SERIAL.print("[HTTP] GET...\n");
        // start connection and send HTTP header
        int httpCode = http.GET();

        // httpCode will be negative on error
        if(httpCode > 0) {
            // HTTP header has been send and Server response header has been handled
            USE_SERIAL.printf("[HTTP] GET... code: %d\n", httpCode);
            
            // file found at server
            if(httpCode == HTTP_CODE_OK) {
                String payload = http.getString();
                USE_SERIAL.println(payload);
                if(payload == "2")//Sol
                {
                  servoNesnesiAlt.write(10);  /* Motorun mili 100. dereceye donuyor */
                }
                else if(payload == "3")//Sağ
                {
                  servoNesnesiAlt.write(40);  /* Motorun mili 100. dereceye donuyor */
                }else if(payload == "1")//ileri
                {
                  servoNesnesiUst.write(27);
                }else if(payload == "0")//Geri
                {
                  servoNesnesiUst.write(55);
                }else if(payload == "8")//Sabit
                {
                  servoNesnesiAlt.write(27);
                  servoNesnesiUst.write(38);
                }
            }
        } else {
            USE_SERIAL.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
        }

        http.end();
    }

}
