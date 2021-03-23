#include "LCD.h"

DigitalOut RS(D2);
DigitalOut E(D3);
BusOut data(D4, D5, D6, D7);

void toggle_enable(void)
{
    E = 1;
    ThisThread::sleep_for(1ms);
    E = 0;
    ThisThread::sleep_for(1ms);
}

//initialise LCD function
void LCD_int(void)
{
    ThisThread::sleep_for(20ms);
    RS = 0;
    E = 0;

    //function mode
    data = 0x2;
    toggle_enable();
    data = 0x8;
    toggle_enable();
    //display mode
    data=0x0;               // 4 bit mode (data packet 1, DB4-DB7)
    toggle_enable();
    data=0xF;               // display on, cursor on, blink on
    toggle_enable();

    //clear display
    data=0x0;
    toggle_enable();
    data=0x1;               // clear
    toggle_enable();
}
//display function
void display_to_LCD(char value)
{
    RS = 1;
    data = value>>4;
    toggle_enable();
    data = value;
    toggle_enable();
}

void set_location(char location)
{
    RS = 0;
    data = (location | 0x80)>>4;
    toggle_enable();
    data = location & 0x0F;
    toggle_enable();
}