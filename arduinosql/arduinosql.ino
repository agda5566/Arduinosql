#include <Ethernet.h>
#include <SPI.h>

byte mac[] = {0x00, 0xAA, 0xBB, 0xCC, 0xDE, 0x02}; // 乙太網路
IPAddress ip(10,21,10,87);
EthernetClient client;
char serverName[] = "10.21.10.113"; 


    void setup() {
       Serial.begin(9600);
       while (!Serial) {
        ; // wait for serial port to connect. Needed for Leonardo only
      }

      Serial.println("Attempting to get an IP address using DHCP:");
      if (!Ethernet.begin(mac)) {
        Serial.println("failed to get an IP address using DHCP, trying manually");
        Ethernet.begin(mac, ip);
      }
      Serial.print("My address:");
      Serial.println(Ethernet.localIP());
      connectToServer();
    }

    void loop()
    {
      if (client.connected()) {
        if (client.available()) {
          char inChar = client.read();
          Serial.print(inChar);
        }
    }
    }

    void connectToServer() {
      Serial.println("connecting to server…");
      if (client.connect(serverName, 80)) {
        Serial.println("making HTTP request…");
       String Requesting;
       String sensor="d大人";//传感器的名称
        int sdata=957;//传感器的数值
        
        Requesting= "GET /sqlservertest.php?name="+sensor+"&age="+sdata+" HTTP/1.1";   
        client.println(Requesting); 
        client.println("HOST: 10.21.10.113");
        client.println();
      }
    }  
