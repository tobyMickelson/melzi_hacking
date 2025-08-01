#pragma once

#include <Arduino.h>

#include "pinout.h"


void ioInit() {
  pinMode(PIN_FAN, OUTPUT);
  pinMode(PIN_NOZ_HEAT, OUTPUT);
  pinMode(PIN_NOZ_TEMP, INPUT);
  pinMode(PIN_BED_HEAT, OUTPUT);
  pinMode(PIN_BED_TEMP, INPUT);
}
