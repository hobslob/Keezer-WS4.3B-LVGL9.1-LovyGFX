#include "includes.h"

#include "./ui/images.h"

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);

// Create an Event Source on /events
AsyncEventSource events("/events");



void WiFi_Setup ( void )
{
  // Populate SSID and Password textboxes in GUI
  lv_textarea_set_text(objects.txt_wifi_ssid, MyKeezer.WiFiSSID.c_str() );
  lv_textarea_set_text(objects.txt_wifi_password, MyKeezer.WiFiPWD.c_str() );

  WiFi.mode(WIFI_STA);
  //WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  WiFi.begin(MyKeezer.WiFiSSID, MyKeezer.WiFiPWD);
  Serial.print("Connecting to WiFi");


  // Wait for connection, timeout after 10 seconds
  uint8_t timeout =0;
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    if (timeout++ > 20)
      break;
  }

  Serial.println("");

  if (timeout <20)
    {
    MyKeezer.isWiFiConnected = true;
    Serial.println("");
    Serial.print("WiFi Connected to ");
    Serial.println(WIFI_SSID);
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());

    // Display IP Address in GUI
    lv_textarea_set_text(objects.txt_wifi_ip_addr, WiFi.localIP().toString().c_str() );
    lv_label_set_text(objects.lbl_connected,"Connected");
    lv_led_set_color(objects.led_connected,lv_color_hex(0x00FF00));

    // Set Wifi Image on Home screen
    lv_img_set_src(objects.img_wifi_home, &img_wifi);

    }
  else
    {  
    MyKeezer.isWiFiConnected = false;
    Serial.println("Could not connect to WiFi!");  
    lv_label_set_text(objects.lbl_connected,"Not Connected");
    lv_led_set_color(objects.led_connected,lv_color_hex(0xFF0000));

    // Set Wifi Image on Home screen
    lv_img_set_src(objects.img_wifi_home, &img_no_wifi);
    }
}

void MDNS_Setup ( void )
{
  if (!MyKeezer.isWiFiConnected)
    return;

  // Initialize mDNS
  if (!MDNS.begin(MDNS_HOSTNAME)) {   // Set the hostname to "esp32.local"
    Serial.println("Error setting up MDNS responder!");
  }
  else
  {
  MDNS.addService("http", "tcp", 80);  
  Serial.println("mDNS responder started");
  }

}



void send_enet_client_events( void )
{    
    events.send("ping",NULL,millis());
    events.send(getSensorReadingsJSON().c_str(),"new_readings" ,millis());
}

void Setup_OTA_Updater ( void )
{
  ElegantOTA.begin(&server);    // Start ElegantOTA

  // ElegantOTA callbacks
  ElegantOTA.onStart(onOTAStart);
  ElegantOTA.onProgress(onOTAProgress);
  ElegantOTA.onEnd(onOTAEnd);

}

void onOTAStart() {
  // Log when OTA has started
  Serial.println("OTA update started!");
  // <Add your own code here>
  firmware_update_start = true;
  firmware_update_inprogress = true;
  firmware_update_done = false;

}

void onOTAProgress(size_t current, size_t final) {
  // Log every 1 second
  if (millis() - ota_progress_millis > 1000) {
    ota_progress_millis = millis();
    Serial.printf("OTA Progress Current: %u bytes, Final: %u bytes\n", current, final);
  }
}

void onOTAEnd(bool success) {
  // Log when OTA has finished
  if (success) {
    Serial.println("OTA update finished successfully!");
  } else {
    Serial.println("There was an error during OTA update!");
  }
  // <Add your own code here>
  firmware_update_start = false;
  firmware_update_inprogress = false;
  firmware_update_done = true;
}




void notFound(AsyncWebServerRequest *request) 
{
  request->send(404, "text/plain", "Not found, you're drunk!");
}

void Setup_Async_Webserver ( void )
{

  // Web Server Root URL
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(LittleFS, "/index.html", "text/html");
  });

  server.serveStatic("/", LittleFS, "/");


  // Request for the latest sensor readings
  server.on("/readings", HTTP_GET, [](AsyncWebServerRequest *request){
    String json = getSensorReadingsJSON();
    request->send(200, "application/json", json);
    json = String();
  });

  events.onConnect([](AsyncEventSourceClient *client){
    if(client->lastId()){
      Serial.printf("Client reconnected! Last message ID that it got is: %u\n", client->lastId());
    }
    // send event with message "hello!", id current millis
    // and set reconnect delay to 1 second
    client->send("hello!", NULL, millis(), 10000);
  });
  
  AsyncCallbackJsonWebHandler* handler = new AsyncCallbackJsonWebHandler("/setkeg", [](AsyncWebServerRequest *request, JsonVariant &json) 
  {
  const JsonObject& jsonObj = json.as<JsonObject>();
  
  Serial.println("Got data from the webpage"); 

  const char* beername1 = jsonObj["Keg1BeerName"];
  const char* beername2 = jsonObj["Keg2BeerName"];
  const char* beername3 = jsonObj["Keg3BeerName"];
  const char* beername4 = jsonObj["Keg4BeerName"];
  
  if (beername1)
    {
    Serial.print("The Keg1 Beer Name is: ");
    Serial.println(beername1);
    KegData[KEG1].ContentName = beername1;
    // Save to NV Storage
    Save_Kegname_To_NVStorage (KEG1);
    }
  else
    Serial.println("Beer 1 Name Not Specified or NULL");

  if (beername2)
    {
    Serial.print("The Keg2 Beer Name is: ");
    Serial.println(beername2);
    KegData[KEG2].ContentName = beername2;
    // Save to NV Storage
    Save_Kegname_To_NVStorage (KEG2);
    }
  else
    Serial.println("Beer 2 Name Not Specified or NULL");

  if (beername3)
    {
    Serial.print("The Keg3 Beer Name is: ");
    Serial.println(beername3);
    KegData[KEG3].ContentName = beername3;
    // Save to NV Storage
    Save_Kegname_To_NVStorage (KEG3);
    }
  else
    Serial.println("Beer 3 Name Not Specified or NULL");

  if (beername4)
    {
    Serial.print("The Keg4 Beer Name is: ");
    Serial.println(beername4);
    KegData[KEG4].ContentName = beername4;
    // Save to NV Storage
    Save_Kegname_To_NVStorage (KEG4);
   }
  else
    Serial.println("Beer 4 Name Not Specified or NULL");


  // HTML POST Expects a reply. Return the JSON back. Could also do a text/plain "Success"
  String rtnJson;
  serializeJson(jsonObj, rtnJson);
  request->send(200, "application/json", rtnJson);
  rtnJson = String();

  // Update beer names in GUI
  update_all_kegnames();

  });


  server.addHandler(handler);
  server.addHandler(&events);

  server.onNotFound(notFound);
  server.begin();
  Serial.println("HTTP server started");

}
