#include <AltSoftSerial.h>
AltSoftSerial altSerial;
#define debounce 20 // ms debounce period 
#define holdTime 250 // ms hold time to know the button release time dealy

// this constant won't change:
const int  buttonPin_red = 12;    // the pin that the pushbutton is attached to
const int  buttonPin_green_rst = 13;    // the pin that the pushbutton is attached to
const int  buttonPin_green_usb = 11;    // the pin that the pushbutton is attached to
const int  buttonPin_yellow = 8;    // the pin that the pushbutton is attached to
int buttonPushCounter = 0;   // counter for the number of button presses


void setup()
{                
  // Set up the digital pin 2 to an Interrupt and Pin 4 to an Output
  altSerial.begin(57600); 
  pinMode(12, INPUT_PULLUP);
  //pinMode(13, INPUT_PULLUP);
  //pinMode(13, INPUT);
  //digitalWrite(13, HIGH);
  pinMode(11, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  while(1){
  buttons();
  //loop(); 
  }; 
 }

void loop()                     
{
  altSerial.println("Button Process Running:");
 }
 


void buttons()
{
  if (digitalRead(buttonPin_red)==0) // 
  {
   
   delay(debounce);   
   buttonPushCounter++;
   altSerial.println("on");
   altSerial.print("button 1 Red pushes:  ");
   altSerial.println(buttonPushCounter);
   altSerial.println(); 
   delay( holdTime);   
  }  
 /*else
    if (digitalRead(buttonPin_green_rst)==0)
    {
       
   
   delay(debounce);   
   buttonPushCounter++;
   altSerial.println("on");
   altSerial.print("button 2 green_rst pushes:  ");
   altSerial.println(buttonPushCounter);
   altSerial.println(); 
   delay( holdTime);   
     } 
*/     
else
    if (digitalRead(buttonPin_green_usb)==0)
    {
     
   delay(debounce); 
   buttonPushCounter++;
   altSerial.println("on");
   altSerial.print("button 3 green_usb pushes:  ");
   altSerial.println(buttonPushCounter);
   altSerial.println(); 
   delay( holdTime);  
  
    }                   
 else
      if (digitalRead(buttonPin_yellow)==0)
      {
  
   delay(debounce); 
   buttonPushCounter++;
   altSerial.println("on");
   altSerial.print("button 4 yellow pushes:  ");
   altSerial.println(buttonPushCounter);
   altSerial.println();
   delay( holdTime);   
 
      }
   //else delay(holdTime); 
}
