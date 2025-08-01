#pragma once

#include <Arduino.h>
#include <SPI.h>
#include <U8g2lib.h>

#include "pinout.h"


static U8G2_ST7920_128X64_1_SW_SPI display(U8G2_R0, PIN_LCD_D4, PIN_LCD_ENB, PIN_LCD_RS);


void displayInit() {
  pinMode(PIN_LCD_D4, OUTPUT);
  pinMode(PIN_LCD_ENB, OUTPUT);
  pinMode(PIN_LCD_RS, OUTPUT);

  display.begin();
  display.setFont(u8g2_font_5x8_mf);
}

U8G2_ST7920_128X64_1_SW_SPI displayGet() {
  return display;
}
