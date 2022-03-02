#include <Arduino.h>
#include <LED.h>
#include <button.h>
#define LED_1_PIN 13
#define BUTTON_PIN 5 



Led led1(LED_1_PIN); 
Button button1(BUTTON_PIN);


void setup() {
  // put your setup code here, to run once:
}

void loop() {
  if (button1.isPressed()) {
    led1.on();
   // led2.off();
   // led3.on();
   // led4.off();
  }
  else {
    led1.off();
   // led2.on();
   // led3.off();
   // led4.on();
  }
}