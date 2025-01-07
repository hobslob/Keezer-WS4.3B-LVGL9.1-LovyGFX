/*
#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include <WS43B_CHG422G.h>
#include <TAMC_GT911.h>

#include <Arduino_GFX_Library.h>
#include <lvgl.h>
#include <demos/lv_demos.h>
*/
#include "includes.h"

// Waveshare Pin Defines
#define GPIO_INPUT_IO_4    4
#define WS_SDA  8
#define WS_SCL  9


// TAMC GT911 Defines
#define TOUCH_SDA WS_SDA
#define TOUCH_SCL WS_SCL
#define TOUCH_INT 0
#define TOUCH_RST 0
#define TOUCH_WIDTH 800
#define TOUCH_HEIGHT 480


TAMC_GT911 tp = TAMC_GT911(WS_SDA, WS_SCL, TOUCH_INT, TOUCH_RST, TOUCH_WIDTH, TOUCH_HEIGHT);


// Define a class named LGFX, inheriting from the LGFX_Device class.
#define LGFX_USE_V1
class LGFX : public lgfx::LGFX_Device {
public:
  // Instances for the RGB bus and panel.
  lgfx::Bus_RGB     _bus_instance;
  lgfx::Panel_RGB   _panel_instance;


  // Constructor for the LGFX class.
  LGFX(void) {
    // Configure the RGB bus.
    {
      auto cfg = _bus_instance.config();
      cfg.panel = &_panel_instance;


      // Configure data pins.
      cfg.pin_d0  = 14; // B0
      cfg.pin_d1  = 38;  // B1
      cfg.pin_d2  = 18;  // B2
      cfg.pin_d3  = 17;  // B3
      cfg.pin_d4  = 10;  // B4
      
      cfg.pin_d5  = 39;  // G0
      cfg.pin_d6  = 0; // G1
      cfg.pin_d7  = 45;  // G2
      cfg.pin_d8  = 48;  // G3
      cfg.pin_d9  = 47; // G4
      cfg.pin_d10 = 21;  // G5
      
      cfg.pin_d11 = 1; // R0
      cfg.pin_d12 = 2; // R1
      cfg.pin_d13 = 42; // R2
      cfg.pin_d14 = 41; // R3
      cfg.pin_d15 = 40; // R4


      // Configure sync and clock pins.
      cfg.pin_henable = 5;
      cfg.pin_vsync   = 3;
      cfg.pin_hsync   = 46;
      cfg.pin_pclk    = 7;
      cfg.freq_write  = 15000000;


      // Configure timing parameters for horizontal and vertical sync.
      cfg.hsync_polarity    = 0;
      cfg.hsync_front_porch = 8;
      cfg.hsync_pulse_width = 4;
      cfg.hsync_back_porch  = 8;
      
      cfg.vsync_polarity    = 0;
      cfg.vsync_front_porch = 8;
      cfg.vsync_pulse_width = 4;
      cfg.vsync_back_porch  = 8;


      // Configure polarity for clock and data transmission.
      cfg.pclk_active_neg   = 1;
      cfg.de_idle_high      = 0;
      cfg.pclk_idle_high    = 1;


      // Apply configuration to the RGB bus instance.
      _bus_instance.config(cfg);
    }

    {
      auto cfg = _panel_instance.config_detail();

      cfg.use_psram = 1;

      _panel_instance.config_detail(cfg);
    }

    // Configure the panel.
    {
      auto cfg = _panel_instance.config();
      cfg.memory_width  = 800;
      cfg.memory_height = 480;
      cfg.panel_width   = 800;
      cfg.panel_height  = 480;
      cfg.offset_x      = 0;
      cfg.offset_y      = 0;


      // Apply configuration to the panel instance.
      _panel_instance.config(cfg);
    }


    // Set the RGB bus and panel instances.
    _panel_instance.setBus(&_bus_instance);
    setPanel(&_panel_instance);
  }
};
LGFX lcd;

/*
static BmpClass bmpClass;

//#if 1 //for Arduino_GFX_Library v1.4.7
#define GFX_DEV_DEVICE ESP32_4827S043
#define RGB_PANEL

Arduino_ESP32RGBPanel *rgbpanel = new Arduino_ESP32RGBPanel(
    //  5, // DE
    //  3 ,// VSYNC 
    //  46, // HSYNC 
    //  7, // PCLK
    //  1, // R0 = R3 = 1 .d0 
    //  2, // R1 = R4 = 2 .d1 
    //  42, // R2 = R5 = 42 .d2 
    //  41, // R3 = R6 = 41 .d3 
    //  40, // R4 = R7 = 40 .d4
    //  39, // G0 = G2 = 39 .d5 
    //  0 , // G1 = G3 = 0 .d6 
    //  45, // G2 = G4 = 45 .d7 
    //  48, // G3 = G5 = 48 .d8 
    //  47, // G4  = G6 = 47 .d9 
    //  21, // G5 = G7 = 21 .d10
    //  14, // B0 = B3 = 14 .d11 
    //  38, // B1 = B4 = 38 .d12 
    //  18, // B2 = B5 = 18 .d13 
    //  17, // B3 = B6 = 17 .d14 
    //  10, // B4 = B7 = 10 .d15
    //  0, // hsync_polarity 
    //  8, // hsync_front_porch 
    //  4, // hsync_pulse_width 
    //  8, // hsync_back_porch
    //  0, // vsync_polarity
    //  8, // vsync_front_porch 
    //  4, // vsync_pulse_width 
    //  8, // vsync_back_porch

    //  1, // pclk_active_neg 
    //  16000000 // prefer_speeed


//#endif   //End of for Arduino_GFX_Library v1.4.7

*/

int32_t testFillScreen();
static inline uint32_t micros_start() __attribute__((always_inline));

int32_t w, h, n, n1, cx, cy, cx1, cy1, cn, cn1;
uint8_t tsa, tsb, tsc, ds;

// Timer variables
unsigned long lastTime = 0;
unsigned long timerDelay = 5000;// 10000
unsigned long main_loop_millis = 0;
unsigned long temperature_check_millis = 0;
unsigned long scale_read_millis = 0;
uint8_t loopCnt = 0;
float mytemp = 0;


// LVGL Stuff
uint32_t screenWidth;
uint32_t screenHeight;
uint32_t bufSize;

lv_display_t *disp;
lv_color_t *disp_draw_buf;
lv_color_t *disp_draw_buf2;


void my_touchpad_read(lv_indev_t *indev, lv_indev_data_t *data);
void my_disp_flush( lv_display_t *disp, const lv_area_t *area, uint8_t * px_map);
//void my_disp_flush( lv_display_t *disp, const lv_area_t *area, lv_color_t *color_p);
uint32_t millis_cb ( void );

/*
// can probably remove this bmp stuff, was test of ArduinoGFX BMP load from littlefs
static void bmpDrawCallback(int16_t x, int16_t y, uint16_t *bitmap, int16_t w, int16_t h);

// bmp drawing callback
static void bmpDrawCallback(int16_t x, int16_t y, uint16_t *bitmap, int16_t w, int16_t h)
{
  // Serial.printf("Draw pos = %d, %d. size = %d x %d\n", x, y, w, h);
  gfx->draw16bitRGBBitmap(x, y, bitmap, w, h);
}
*/


/* Display flushing */
void my_disp_flush( lv_display_t *disp, const lv_area_t *area, uint8_t * px_map)
//void my_disp_flush( lv_display_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
    if (lcd.getStartCount() == 0)
    {   // Processing if not yet started
        lcd.startWrite();
    }

  uint32_t w = lv_area_get_width(area);
  uint32_t h = lv_area_get_height(area);

  //gfx->draw16bitRGBBitmap(area->x1, area->y1, (uint16_t *)px_map, w, h);  
  //lcd.pushImageDMA(area->x1, area->y1, w, h,(lgfx::rgb565_t*)&color_p->full);//
  lcd.pushImageDMA(area->x1, area->y1, w, h,(lgfx::rgb565_t*)px_map);//
  
  /*Call it to tell LVGL you are ready*/
  lv_disp_flush_ready(disp);
}


//Read the touchpad
void my_touchpad_read(lv_indev_t *indev, lv_indev_data_t *data)
{
  tp.read();
  if (tp.isTouched)
    {
    // Retrieve the points, up to 5!   
    for (int i=0; i<tp.touches; i++) 
      {
      data->point.x = tp.points[i].x;
      data->point.y = tp.points[i].y;

      //Serial.printf("x:%d, y:%d\r\n", data->point.x, data->point.y);
      data->state = LV_INDEV_STATE_PRESSED;
      }
    } 
  else 
    {
      data->state = LV_INDEV_STATE_RELEASED;
    }

}


uint32_t millis_cb(void)
{
  return millis();
}


void setup() {

  // Drive the ESP32 IO Pin attached to the TP_IRQ Low for some reason, maybe so it ignores the interrupt signal???
  pinMode(GPIO_INPUT_IO_4, OUTPUT);
  digitalWrite(GPIO_INPUT_IO_4, LOW);
  delay(100);

  Serial.begin(115200);
    //while(!Serial);

  Serial.println("TAMC_GT911 Example: Ready");

  // Start I2C using Waveshare board specific I2C pins
  Wire.begin( WS_SDA, WS_SCL, 400000);

  init_CHG422G();
  
  tp.begin();
  tp.setRotation(ROTATION_INVERTED);



  if (!lcd.begin())
    {
    Serial.println("gfx->begin() failed!");
    }
  else
      Serial.println("gfx->begin() Success!");

  lcd.setColorDepth(16);
  lcd.fillScreen(lcd.color565(0,0,0));



  // Initialize LittleFS
  if(!LittleFS.begin() )
    {
    Serial.println("An Error has occurred while mounting LittleFS");
    //return;
    }
  else
    {
    Serial.println("LittleFS mounted successfully");
    }


  lv_init();

  //Set a tick source so that LVGL will know how much time elapsed.
  lv_tick_set_cb(millis_cb);

  screenWidth = lcd.width();
  screenHeight = lcd.height();

  //bufSize = screenWidth * 60;
  //bufSize = screenWidth * 12;
  //bufSize = screenWidth * 10;
  bufSize = screenWidth * 20;


  disp_draw_buf  = (lv_color_t *)heap_caps_malloc(bufSize * 2, MALLOC_CAP_INTERNAL | MALLOC_CAP_8BIT | MALLOC_CAP_DMA);
  disp_draw_buf2 = (lv_color_t *)heap_caps_malloc(bufSize * 2, MALLOC_CAP_INTERNAL | MALLOC_CAP_8BIT | MALLOC_CAP_DMA);
  // disp_draw_buf  = (lv_color_t *)heap_caps_malloc(bufSize * 2, MALLOC_CAP_8BIT | MALLOC_CAP_DMA);
  // disp_draw_buf2 = (lv_color_t *)heap_caps_malloc(bufSize * 2, MALLOC_CAP_8BIT | MALLOC_CAP_DMA);
  
  if (!disp_draw_buf)
    {
    // remove MALLOC_CAP_INTERNAL flag try again
    disp_draw_buf  = (lv_color_t *)heap_caps_malloc(bufSize * 2, MALLOC_CAP_8BIT);
    disp_draw_buf2 = (lv_color_t *)heap_caps_malloc(bufSize * 2, MALLOC_CAP_8BIT);
    }

  if (!disp_draw_buf)
    {
    Serial.println("LVGL disp_draw_buf allocate failed!");
  }
  else
  {
    disp = lv_display_create(screenWidth, screenHeight);
    lv_display_set_flush_cb(disp, my_disp_flush);
    lv_display_set_buffers(disp, disp_draw_buf, disp_draw_buf2, bufSize * 2, LV_DISPLAY_RENDER_MODE_PARTIAL);
    //lv_display_set_buffers(disp, disp_draw_buf, NULL, bufSize * 2, LV_DISPLAY_RENDER_MODE_PARTIAL);


    // Initialize the (dummy) input device driver
    lv_indev_t *indev = lv_indev_create();
    lv_indev_set_type(indev, LV_INDEV_TYPE_POINTER); /*Touchpad should have POINTER type*/
    lv_indev_set_read_cb(indev, my_touchpad_read);

    /* Option 3: Or try out a demo. Don't forget to enable the demos in lv_conf.h. E.g. LV_USE_DEMOS_WIDGETS*/
    //lv_demo_widgets();
    //lv_demo_benchmark();

  }

  // Initialize and start GUI
  ui_init();

  ui_tick();

  hardware_initialized = false;

  update_temperature_info();

}



void loop() {

  if (!firmware_update_inprogress)
    {
    lv_task_handler(); /* let the GUI do its work */
    ui_tick();    
    }

  // Handle any OTA Updater Events
  if (MyKeezer.isWiFiConnected)
    {
    ElegantOTA.loop();

    if (firmware_update_start)
      {
      lcd.fillScreen(lcd.color565(0,0,0));
      //lcd.drawString("Updating Firmware", 10, 10);
      firmware_update_start = false;
      //lv_display_delete_refr_timer(disp);
      }

    }

  if ((millis() - lastTime) > timerDelay) {
    // Send Events to the client with the Sensor Readings Every 10 seconds
    send_enet_client_events();
    lastTime = millis();
  }


  // Do something once every 1000mS
  if (millis() - main_loop_millis > 1000) 
    {
    main_loop_millis = millis();

    if (!hardware_initialized)
      init_keezer();

	  // Read from Scales
    for (uint8_t scalenum=0; scalenum<4; scalenum++)
      {
      if (NewScaleData[scalenum].isPresent)
        {
        Get_Keg_Weight(scalenum);
        Update_MainScreen_Kegdata(scalenum);
        Update_pnl_keg_Info();
        Serial.println( String(KegData[scalenum].CurrentWeight,2) );
        }
      }

/*
    // test set the keg1 remaining bar
    lv_bar_set_value(objects.bar_keg_remain1, (int32_t)mytemp, LV_ANIM_OFF);
    //Serial.println(mytemp);
    lv_color_t my_red = lv_color_hex(0xFF0000);
    lv_color_t my_yellow = lv_color_hex(0xE0FF00);
    lv_color_t my_std_border = lv_color_hex(0x414141);
    lv_color_t border_color;
    border_color = lv_obj_get_style_border_color(objects.pnl_keg_container1,LV_PART_MAIN);

    if ( mytemp < 15)
    	{
      lv_obj_set_style_bg_color(objects.bar_keg_remain1, lv_color_hex(0xFF0000), LV_PART_INDICATOR);
      lv_obj_set_style_bg_opa(objects.bar_keg_remain1, 255, LV_PART_INDICATOR);
      lv_obj_set_style_text_color(objects.lbl_keg_pct_remain1, lv_color_hex(0xFF0000), LV_PART_MAIN);

      if ( lv_color_to_u16(border_color) != lv_color_to_u16(my_red) )
        lv_obj_set_style_border_color(objects.pnl_keg_container1, lv_color_hex(0xFF0000), LV_PART_MAIN);
      }
    else if ( mytemp < 25)
    	{
      lv_obj_set_style_bg_color(objects.bar_keg_remain1, lv_color_hex(0xE0FF00), LV_PART_INDICATOR);
      lv_obj_set_style_bg_opa(objects.bar_keg_remain1, 255, LV_PART_INDICATOR);
      lv_obj_set_style_text_color(objects.lbl_keg_pct_remain1, lv_color_hex(0xE0FF00), LV_PART_MAIN);

      if ( lv_color_to_u16(border_color) != lv_color_to_u16(my_yellow) )
        lv_obj_set_style_border_color(objects.pnl_keg_container1, lv_color_hex(0xE0FF00), LV_PART_MAIN);
      }
    else
    	{

      lv_obj_set_style_bg_color(objects.bar_keg_remain1, lv_color_hex(0x2095f6), LV_PART_INDICATOR);
      lv_obj_set_style_bg_opa(objects.bar_keg_remain1, 255, LV_PART_INDICATOR);
      lv_obj_set_style_text_color(objects.lbl_keg_pct_remain1, lv_color_hex(0xFFFFFF), LV_PART_MAIN);

      if ( lv_color_to_u16(border_color) != lv_color_to_u16(my_std_border) )
        lv_obj_set_style_border_color(objects.pnl_keg_container1, lv_color_hex(0x414141), LV_PART_MAIN);
      }
*/

    if (++mytemp > 99)
        mytemp = 0;

    }


  // Do something once every 5000mS
  if (millis() - temperature_check_millis > 5000) 
    {
    temperature_check_millis = millis();

    read_DHT_temperature_humidity();
    update_temperature_info();

    // Update the Time Display
    if (MyKeezer.isWiFiConnected)
      display_localtime();
    }

  //delay(10);

}



static inline uint32_t micros_start()
{
  uint8_t oms = millis();
  while ((uint8_t)millis() == oms)
    ;
  return micros();
}


int32_t testFillScreen()
{
  uint32_t start = micros_start();
/*  
  // Shortened this tedious test!
  gfx->fillScreen(BLACK);
  delay(1000);
  gfx->fillScreen(WHITE);
  delay(1000);
  gfx->fillScreen(RED);
  delay(1000);
  gfx->fillScreen(GREEN);
  delay(1000);
  gfx->fillScreen(BLUE);
*/
  return micros() - start;
}
