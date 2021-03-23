#include "LCD.h"

int main()
{
    LCD_init();
    display_to_LCD(0x48);
    display_to_LCD(0x45);
    display_to_LCD(0x4C);
    display_to_LCD(0x4C);
    display_to_LCD(0x4F);
    for (char i = 0x30; i <= 0x39; i++) {
        display_to_LCD(x);
    }
}