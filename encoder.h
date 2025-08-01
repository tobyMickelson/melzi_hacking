#pragma once

#include <Arduino.h>

#include "pinout.h"


static volatile long position = 0;
static volatile bool isClockwise = true;
static volatile bool prevA;
static volatile bool prevB;

static void encoderUpdate();


void encoderInit() {
  pinMode(PIN_ENC_SW, INPUT_PULLUP);
  pinMode(PIN_ENC_A, INPUT_PULLUP);
  pinMode(PIN_ENC_B, INPUT_PULLUP);

  prevA = digitalRead(PIN_ENC_A);
  prevB = digitalRead(PIN_ENC_B);

  noInterrupts();
  attachInterrupt(digitalPinToInterrupt(PIN_ENC_A), &encoderUpdate, CHANGE);
  attachInterrupt(digitalPinToInterrupt(PIN_ENC_B), &encoderUpdate, CHANGE);
  interrupts();
}

bool encoderGetSwitch() {
  return !digitalRead(PIN_ENC_SW);
}

bool encoderIsClockwise() {
  return isClockwise;
}

void encoderSetIsClockwise(bool isClockwise_) {
  isClockwise = isClockwise_;
}

long encoderGetPosition() {
  return position;
}

void encoderSetPosition(long position_) {
  position = position_;
}

static void encoderUpdate() {
  // static int lookup[4][4] = {
  //   {0, -1, 1, 0},
  //   {1, 0, 0, -1},
  //   {-1, 0, 0, 1},
  //   {0, 1, -1, 0}
  // };
  static int lookup[4][4] = {
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 1, -1, 0}
  };

  bool nowA = digitalRead(PIN_ENC_A);
  bool nowB = digitalRead(PIN_ENC_B);

  switch (lookup[prevB * 2 + prevA][nowB * 2 + nowA]) {
    case 1:
      position += 1;
      isClockwise = true;
      break;
    case -1:
      position -= 1;
      isClockwise = false;
      break;
    case 0:
    default:
      break;
  }

  prevA = nowA;
  prevB = nowB;
}
