#include <Ethernet.h>
#include <SPI.h>

    byte mac[] = {0x00, 0xAA, 0xBB, 0xCC, 0xDE, 0x02}; // 乙太網路
    IPAddress ip(10,21,10,87); //arduino板子所用網路IP
    EthernetClient client; //建立一個連結到客戶端的端口
    char serverName[] = "10.21.10.113";  //伺服器所在ip


    void setup() {
       Serial.begin(9600); //初始化鮑率，用來在監控視窗看到訊息
       while (!Serial) {
        ; // wait for serial port to connect. Needed for Leonardo only
      }

      Serial.println("Attempting to get an IP address using DHCP:");
      //初始化乙太網路並設定
      if (!Ethernet.begin(mac)) {
        Serial.println("failed to get an IP address using DHCP, trying manually");
        Ethernet.begin(mac, ip);
      }
      Serial.print("My address:");
      Serial.println(Ethernet.localIP());//取得IP
      connectToServer();//使用自訂函式
    }

    void loop()
    {
      if (client.connected()) {
          //檢查是否連結
        if (client.available()) {
            //available連結客戶端
          //char inChar = client.read();
          //Serial.print(inChar);
        }
    }
    }

    void connectToServer() {
      Serial.println("connecting to server…");
      if (client.connect(serverName, 80)) {
        //連接server位址+prot
        Serial.println("making HTTP request…");
        String Requesting;
        String temperature="46";
        String humidity="95";
        //int sdata=3333;

        Requesting="GET /sqlservertest.php?temperature="+temperature+"&humidity="+humidity+" HTTP/1.1";
        client.println(Requesting);
        client.println("HOST: 10.21.10.113");
        client.println();
      }
      else{
          Serial.println("connection failed");
      }
    }
