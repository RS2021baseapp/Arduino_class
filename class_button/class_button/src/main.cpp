#include <Arduino.h>
//#include <EEPROM.h>
#include <LED.h>
#include <button.h>
//#include <keyboard.h>
#include <string.h>
#define LED_1_PIN 13
#define LED_2_PIN 12
#define LED_3_PIN 11
#define LED_4_PIN 10

#define BUTTON_PIN 5 
#define EEPROM_ADDRESS 20

#define BUFFER_SIZE 250


Led led1(LED_1_PIN); 
Led led2(LED_1_PIN); 
Led led3(LED_1_PIN); 
Led led4(LED_1_PIN); 


 void parsedata(char* rec_data);

Button button1(BUTTON_PIN);

int i=0;
char c;
char mydata[100];
char* rec_data[100];

//char dest[20];

void setup() 
  {
  Serial.begin(115200);
  }

void loop() 
{
  while(Serial.available())
  {
   c = Serial.read();
   if(c=='\n')
   {
     parsedata(mydata);
     //Serial.println(mydata);
     for(int i=0;i<100;i++)
     {
       mydata[i] ='\0';
     }
     i=0;
    }else
     {
       mydata[i] = c;
       i++;
     }
   //Serial.print(data);
  }
  
  // print1(data);
 // cpystring();
  if (button1.isPressed()) 
  {
    led1.on();
    led2.off();
    led3.on();
    led4.off();
  }
  else 
  {
    led1.off();
    led2.on();
    led3.off();
    led4.on();
  }


}







/*

void print(int rows)
{
  for (int i = 1; i <= rows; ++i) {
      for (int space = 1; space <= i; ++space) {
         Serial.print("*");
      }
    
      Serial.print("\n");
   }
  
for (int i = rows; i >= 1; --i) {
      for (int space = 1; space <= i; ++space) {
         Serial.print("*");
      }
    
      Serial.print("\n");
   }

}


*/

  void parsedata(char* rec_data)
  { 
    
    char* p;
    char dest[100];
    p=strstr(rec_data,"GPGGA");
   if(p)
   {
     strcpy(dest,rec_data);
    //Serial.println("seraching complete");
    char* token = strtok(dest, ",");
   // loop through the string to extract all other tokens
   while( token != NULL ) {
      Serial.println(token);
      token = strtok(NULL, ",");
   }
   }
  else
     {
        Serial.println("string not matched");
     }
  
  }