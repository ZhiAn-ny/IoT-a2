#include "Lcd.h"

void LCD::init()
{
    this->lcd->begin(n_cols, n_rows);
    
    // this->lcd->setCursor(0, 0);
    // this->lcd->print("Welcome to");
    // this->lcd->setCursor(0, 1);
    // this->lcd->print("Smart Bridge");
}

void LCD::print_pre_alarm()
{
    this->lcd->clear();
    this->lcd->setCursor(0, 0);
    this->lcd->print("PRE-ALARM STATE");
}

void LCD::print_normal()
{
    this->lcd->clear();
    this->lcd->setCursor(0, 0);
    this->lcd->print("BACK TO NORMAL");
}

void LCD::print_alarm()
{
    this->lcd->clear();
    this->lcd->setCursor(0, 0);
    this->lcd->print("ALARM STATE");
}

void LCD::print_water_distance(float n)
{
    this->lcd->clear();

    this->lcd->setCursor(0, 0);
    this->lcd->print("Water Level:");
    this->lcd->setCursor(0, 1);
    this->lcd->print(n);
}

void LCD::clear()
{
    this->lcd->clear();
}
