#ifndef LCD_H
#ifndef LCD_H

#include "mbed.h"

void toggle_enable(void);
void LCD_init(void);
void display_to_LCD(char value);
void set_location(char location);

#endif