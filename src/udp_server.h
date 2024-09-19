#ifndef _UDP_SERVER_H_
#define _UDP_SERVER_H_

// Macro define
#define USER_SSID "aaatamadic"
#define PASSWORD "aaatamadic"

// Global variables
typedef struct
{
    bool connected;
    bool isSetReciveUdp;
    
    int receiveData;

}st_udp_server;
extern st_udp_server g_udp_server;

// Global functions
extern void udp_server_open(void);
extern void udp_server_receive_data(void);


#endif // _UDP_SERVER_H_
