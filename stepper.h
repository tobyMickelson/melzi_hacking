#pragma once

#include <Arduino.h>

#include "pinout.h"


void stepperInit() {
  pinMode(PIN_X_STEP, OUTPUT);
  pinMode(PIN_X_DIR, OUTPUT);
  pinMode(PIN_X_SW, INPUT_PULLUP);
  pinMode(PIN_Y_STEP, OUTPUT);
  pinMode(PIN_Y_DIR, OUTPUT);
  pinMode(PIN_Y_SW, INPUT_PULLUP);
  pinMode(PIN_E_STEP, OUTPUT);
  pinMode(PIN_E_DIR, OUTPUT);
  pinMode(PIN_XYE_ENB, OUTPUT);
  pinMode(PIN_Z_STEP, OUTPUT);
  pinMode(PIN_Z_DIR, OUTPUT);
  pinMode(PIN_Z_ENB, OUTPUT);
  pinMode(PIN_X_SW, INPUT_PULLUP);
}
