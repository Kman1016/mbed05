#include "mbed.h"
#include "TextLCD.h"

TextLCD lcd(D2, D3, D4, D5, D6, D7);    // RS, E, DB4-DB7


int main()
{
    lcd.printf("108061173\n");
    
    for (char x = 0x00; x <= 0x1E; x++) {
        lcd.locate(1,1);
        lcd.printf("%u", x);
        ThisThread::sleep_for(1s);
    }
}