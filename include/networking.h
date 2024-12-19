#ifndef INC_NETWORKING_H_
#define INC_NETWORKING_H_


// Public Function Prototypes
void WiFi_Setup ( void );
void MDNS_Setup ( void );
void Setup_OTA_Updater ( void );
void onOTAStart();
void onOTAProgress(size_t current, size_t final);
void onOTAEnd(bool success);
void notFound(AsyncWebServerRequest *request);
void Setup_Async_Webserver ( void );
void send_enet_client_events ( void );


#endif /* INC_NETWORKING_H_ */