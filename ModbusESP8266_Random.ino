/**
*
*    More information about projects PDAControl
*    Mas informacion sobre proyectos PDAControl
*    Blog PDAControl English   http://pdacontrolenglish.blogspot.com.co/   
*    Blog PDAControl Espanol   http://pdacontrol.blogspot.com.co/
*    Channel  Youtube          https://www.youtube.com/c/JhonValenciaPDAcontrol/videos   
*
*/
#include <ESP8266WiFi.h>
#include <ModbusTCPSlave.h>
#include <Ticker.h>

//WIFI Settings
//byte ip[]      = { 192, 168, 1, 126};
//byte gateway[] = { 192, 168, 1, 1 };
//byte subnet[]  = { 255, 255, 255, 0 };

Ticker Parada;
ModbusTCPSlave Mb;


void valor() {

      /// Send random - envio random
      Mb.MBHoldingRegister[0] = random(0,51); 

      /// read - lectura   MBHoldingRegister[0]    
      Serial.print("MBHoldingRegister[0]");
      Serial.println(Mb.MBHoldingRegister[0]);
      
     /// read - lectura   MBHoldingRegister[1]
     Serial.print("MBHoldingRegister[1]");
     Serial.println(Mb.MBHoldingRegister[1]);

  }

void setup()
{

    Serial.begin(115200);  
    Mb.begin("SSID", "PASSWORD");
//  Mb.begin("SSID", "PASSWORD", ip, gateway, subnet);

  delay(100);

}

void loop()
{
  Mb.Run();
  delay(10);

 ////Ticker Function
 Parada.attach_ms(25,valor);

  
}

