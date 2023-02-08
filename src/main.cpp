#include <Arduino.h>
#include "ssd1306.h"


SSD1306 oled;


void splash() {
 
  oled.fill(0);
  oled.set_pos(0,0);
  oled.print("M7STZ QRP RF Power Meter");

}


void setup() {
  TinyWireM.begin();
  oled.begin();
  splash(); 
}

float adc = 0;
float vpk = 0;
float rms = 0;
float pwr = 0;
float dbm = 0;


void loop() {

  adc = analogRead(A2);
  vpk = ((5.0 / 1023.0) * adc) + 0.3; // germanium diode drop
  rms = vpk * 0.707;
  pwr = (rms * rms) / 50;
  dbm = 10 * log10( pwr / 0.001 );


  oled.set_pos(0,10);
  oled.print("Vpk -> ");
  oled.print_float(vpk,5);

  oled.set_pos(0,12);
  oled.print("P   -> ");
  oled.print_float(pwr,5);

  oled.set_pos(0,14);
  oled.print("dBm -> ");
  oled.print_float(dbm,5);
}