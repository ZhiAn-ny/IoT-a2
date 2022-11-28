#include "Lcd.h"

void LCD::init()
{
    this->lcd->begin(n_cols, n_rows);
    
    this->lcd->setCursor(0, 0);
    this->lcd->print("Welcome to");
    this->lcd->setCursor(0, 1);
    this->lcd->print("Smart Bridge");

}

void LCD::print(int n)
{
    this->lcd->print(n);
}

void LCD::clear()
{
    this->lcd->clear();
}
