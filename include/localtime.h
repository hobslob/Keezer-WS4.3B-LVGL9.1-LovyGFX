#ifndef INC_LOCALTIME_H_
#define INC_LOCALTIME_H_


// Public Function Prototypes
void time_canvas_init( void);
void display_localtime ( void );
void setTimezone(String timezone);
void initTime(String timezone);
String getCurrentTimeStr();
void printLocalTime();
void setTime(int yr, int month, int mday, int hr, int minute, int sec, int isDst);


#endif /* INC_LOCALTIME_H_ */