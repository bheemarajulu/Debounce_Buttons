
#include <AltSoftSerial.h>
AltSoftSerial altSerial;
// this constant won't change:
const int  buttonPin_red = 12;    // the pin that the pushbutton is attached to
const int  buttonPin_green_rst = 13;    // the pin that the pushbutton is attached to
const int  buttonPin_green_usb = 11;    // the pin that the pushbutton is attached to
const int  buttonPin_yellow = 8;    // the pin that the pushbutton is attached to
const int ledPin = 13;       // the pin that the LED is attached to

// Variables will change:
int buttonPushCounter = 0;   // counter for the number of button presses
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button
long lastDebounceTime = 0;
long debounceDelay = 50;

void setup() {
         
  // initialize serial communication:
  //Serial.begin(9600);
  altSerial.begin(57600); 
  pinMode(12, INPUT_PULLUP);
}

  
  
void loop() {
  // read the pushbutton input pin:
  buttonState = digitalRead(buttonPin);

  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    lastDebounceTime = micros();
    // if the state has changed, increment the counter
   if ((lastDebounceTime) > debounceDelay) {
    if (buttonState == LOW) {
      // if the current state is HIGH then the button
      // wend from off to on:
      buttonPushCounter++;
      altSerial.println("on");
      altSerial.print("number of button pushes:  ");
      altSerial.println(buttonPushCounter);
      altSerial.println(); 
    } 
    
    else {
      // if the current state is LOW then the button
      // wend from on to off:
      altSerial.println("off"); 
      altSerial.println(); 
    }
   }
  }
  // save the current state as the last state, 
  //for next time through the loop
  lastButtonState = buttonState;

  
  // turns on the LED every four button pushes by 
  // checking the modulo of the button push counter.
  // the modulo function gives you the remainder of 
  // the division of two numbers:
    
}
