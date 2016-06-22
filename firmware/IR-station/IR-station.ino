/*
   IR-station Ver.1.0.0
   Infrared Remote Controller with ESP8266 WiFi Module

   Author:  kerikun11 (Github: kerikun11)
   Date:    2016.01.22
*/

#include <ESP8266WiFi.h>
#include <FS.h>
#include "config.h"
#include "IR_op.h"
#include "OTA_op.h"
#include "server_op.h"

void setup() {
  // Prepare Serial debug
  Serial.begin(115200);
  println_dbg("");
  println_dbg("Hello, I'm ESP-WROOM-02");

  // prepare GPIO
  pinMode(PIN_INDICATOR, OUTPUT);
  pinMode(PIN_IR_IN, INPUT);
  pinMode(PIN_IR_OUT, OUTPUT);
  pinMode(PIN_BUTTON, INPUT_PULLUP);
  digitalWrite(PIN_IR_OUT, LOW);

  // Setup Start
  digitalWrite(PIN_INDICATOR, HIGH);

  // WiFi setup
  modeSetup();

  // Setup Completed
  digitalWrite(PIN_INDICATOR, LOW);
  println_dbg("Setup Completed");
}

void loop() {
  OTATask();
  serverTask();
}

