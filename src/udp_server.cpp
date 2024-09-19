#include "udp_server.h"

#include <WiFi.h>
#include <WiFiUdp.h>

// global
void udp_server_open(void);
void udp_server_receive_data(void);

WiFiUDP udp;

st_udp_server g_udp_server;
 
// static
static void server_setup(void);
static void udp_server_setup_wifi_udp_server(void);
static void reset_all_udp(void);

static const char *ssid_ = USER_SSID;
static const char *pass_ = PASSWORD; 
   
static const char *toUdpAddr = "192.168.4.2";     // 送信先IP
   
static const int toUdpPort = 55556;               // 送信先ポート番号
static const int myUdpPort = 55555;               // 自ポート番号
 

typedef struct{
  bool isSetReciveUdpPrev;
}st_prv;
st_prv prv;


// function
 
void udp_server_receive_data(void){
  int packetSize = udp.parsePacket();
  st_udp_server *p_udp_server = &g_udp_server;

  if (packetSize > 0){
    p_udp_server->receiveData = udp.read();
  }
}

void udp_server_open(void){
  st_udp_server *p_udp_server = &g_udp_server;

  server_setup();
  delay(1000);
}

static void server_setup(void){
  Serial.begin(115200);
  
  // 変数初期化
  reset_all_udp();
  delay(1000);
  udp_server_setup_wifi_udp_server();

}

static void udp_server_setup_wifi_udp_server(){
  Serial.println("Connecting to WiFi network: " + String(USER_SSID));
  WiFi.disconnect(true, true); //WiFi config設定リセット
  WiFi.softAP(USER_SSID, PASSWORD);
  IPAddress myIP = WiFi.softAPIP();

  Serial.println("WiFi connected!");
  Serial.print("My IP address: ");
  Serial.println(myIP);

  udp.begin(myIP, myUdpPort);

  delay(1000);
}

static void reset_all_udp(void){
  st_udp_server *p_udp_server = &g_udp_server;

  p_udp_server->connected = false;
  p_udp_server->isSetReciveUdp = false;
  p_udp_server->receiveData = 0;
}