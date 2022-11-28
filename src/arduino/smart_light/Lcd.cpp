#include "Lcd.h"

void LCD::init()
{
    this->lcd->begin(N_COLS, N_ROWS);
    
    this->lcd->setCursor(0, 0);
    this->lcd->print("Hello World!");
}

void LCD::print(int n)
{
    this->lcd->print(n);
}
