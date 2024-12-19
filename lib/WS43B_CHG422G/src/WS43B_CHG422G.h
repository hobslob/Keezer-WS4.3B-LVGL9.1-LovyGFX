
#include <Arduino.h>
#include <Wire.h>


// CHG422G Extend IO Pin define
#define DIO0    0
#define TP_RST  1
#define LCD_BL  2
#define LCD_RST 3
#define SD_CS   4
#define DIO1    5

#define ASSERT_TP_RST_LCD_RST   (0x35)  // (0b0011_0101)
#define DEASSERT_TP_RST_LCD_RST (0x3F)  // (0b0011_1111)


#define CH422G_I2C_ADDRESS      (0x24)
/* Register address. Actually Addresses, not registers. CHG uses multiple I2C addresses, kinda shitty */
#define CH422G_REG_WR_SET       (0x48 >> 1)
#define CH422G_REG_WR_OC        (0x46 >> 1)
#define CH422G_REG_WR_IO        (0x70 >> 1)
#define CH422G_REG_RD_IO        (0x4D >> 1)

/* Default register value on power-up */
//#define DIR_REG_DEFAULT_VAL     (0xff)
#define DIR_REG_DEFAULT_VAL     (0x01)
#define OUT_REG_DEFAULT_VAL     (0xdf)
#define OD_OUT_REG_DEFAULT_VAL  (0x03)


extern void init_CHG422G( void );