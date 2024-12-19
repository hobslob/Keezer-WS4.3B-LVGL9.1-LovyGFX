#include "includes.h"

void time_canvas_init( void)
{
    // time_canvas.createSprite(TIME_CANVAS_SIZEX, TIME_CANVAS_SIZEY);
    // time_canvas.loadFont(Calibri18b);
    // time_canvas.fillSprite(TFT_BLACK);
    // time_canvas.setTextColor(TFT_WHITE);
}


void display_localtime ( void )
{
  
 lv_label_set_text(objects.lbl_home_cur_time, getCurrentTimeStr().c_str() );

}


void setTimezone(String timezone){
  Serial.printf("  Setting Timezone to %s\n",timezone.c_str());
  setenv("TZ",timezone.c_str(),1);  //  Now adjust the TZ.  Clock settings are adjusted to show the new local time
  tzset();
}

void initTime(String timezone){
  struct tm timeinfo;

  Serial.println("Setting up time");
  configTime(0, 0, "pool.ntp.org");    // First connect to NTP server, with 0 TZ offset
  if(!getLocalTime(&timeinfo)){
    Serial.println("  Failed to obtain time");
    return;
  }
  Serial.println("  Got the time from NTP");
  // Now we can set the real timezone
  setTimezone(timezone);
}

String getCurrentTimeStr(){
  struct tm timeinfo;
  char timestr[24];
  if(!getLocalTime(&timeinfo)){
    Serial.println("Failed to obtain time 1");
    return("NULL");
  }
  //Serial.println(&timeinfo, "%a, %b %d %I:%M %p");
  strftime(timestr,24, "%a, %b %d %I:%M %p", &timeinfo);
  return (timestr);
}


void printLocalTime(){
  struct tm timeinfo;
  if(!getLocalTime(&timeinfo)){
    Serial.println("Failed to obtain time 1");
    return;
  }
  Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S zone %Z %z ");
  Serial.println(&timeinfo, "%a, %b %d %I:%M %p");
}

void setTime(int yr, int month, int mday, int hr, int minute, int sec, int isDst){
  struct tm tm;

  tm.tm_year = yr - 1900;   // Set date
  tm.tm_mon = month-1;
  tm.tm_mday = mday;
  tm.tm_hour = hr;      // Set time
  tm.tm_min = minute;
  tm.tm_sec = sec;
  tm.tm_isdst = isDst;  // 1 or 0
  time_t t = mktime(&tm);
  Serial.printf("Setting time: %s", asctime(&tm));
  struct timeval now = { .tv_sec = t };
  settimeofday(&now, NULL);
}

