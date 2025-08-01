#include <Arduino.h>

#include "display.h"
#include "encoder.h"
#include "io.h"
#include "stepper.h"


void setup() {
  Serial.begin(115200);
  
  displayInit();
  encoderInit();
  ioInit();
  stepperInit();
}

void loop() {
  static char buffer[256];

  if (encoderGetSwitch()) {
    encoderSetPosition(0);
    encoderSetIsClockwise(true);
  }

  snprintf(buffer, 255, "Encoder: %-3ld  %s", encoderGetPosition(), encoderIsClockwise() ? " CW" : "CCW");
  buffer[255] = '\0';

  display.firstPage();
  do {
    display.drawStr(0, 8, buffer);
  } while (display.nextPage());

  delay(1000 / 15
  );
}
