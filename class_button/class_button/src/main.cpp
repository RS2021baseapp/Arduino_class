#include <Arduino.h>
#include <EEPROM.h>
#include <LED.h>
#include <button.h>


#define LED_1_PIN 13
#define LED_2_PIN 12
#define LED_3_PIN 11
#define LED_4_PIN 10

#define BUTTON_PIN 5 
#define EEPROM_ADDRESS 20


Led led1(LED_1_PIN); 
Led led2(LED_1_PIN); 
Led led3(LED_1_PIN); 
Led led4(LED_1_PIN); 


void writeStringToEEPROM(int addrOffset, const String &strToWrite);
String readStringFromEEPROM(int addrOffset);



Button button1(BUTTON_PIN);
//int k;
String retrievedString;

void setup() {
  Serial.begin(9600);
  
  writeStringToEEPROM(0, "Hello Arduino");
  
  retrievedString = readStringFromEEPROM(0);
 // Serial.print("The String we read from EEPROM: ");
  //Serial.println(retrievedString);



  // put your setup code here, to run once:
  //EEPROM.write(EEPROM_ADDRESS,11);
  //delay(10);
  // k=EEPROM.read(EEPROM_ADDRESS);
  //Serial.print("data stored at eeprom address");
  //Serial.print("");
  //Serial.print(k);
}

void loop() {
  //Serial.print("data stored at eeprom address");
  //Serial.print(" ");
  //Serial.print(k);
 // Serial.print("\n");
   delay(1000);
   Serial.print("The String we read from EEPROM: ");

   Serial.println(retrievedString);
  if (button1.isPressed()) {
    led1.on();
    led2.off();
    led3.on();
    led4.off();
  }
  else {
    led1.off();
    led2.on();
    led3.off();
    led4.on();
  }
}


void writeStringToEEPROM(int addrOffset, const String &strToWrite)
{
  byte len = strToWrite.length();
  EEPROM.write(addrOffset, len);
  for (int i = 0; i < len; i++)
  {
    EEPROM.write(addrOffset + 1 + i, strToWrite[i]);
  }
}



String readStringFromEEPROM(int addrOffset)
{
  int newStrLen = EEPROM.read(addrOffset);
  char data[newStrLen + 1];
  for (int i = 0; i < newStrLen; i++)
  {
    data[i] = EEPROM.read(addrOffset + 1 + i);
  }
  data[newStrLen] = '\0'; 
  return String(data);
}