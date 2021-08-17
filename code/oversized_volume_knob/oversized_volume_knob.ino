#include <Arduino.h>
#include <ClickEncoder.h>
#include <TimerOne.h>


#define ENCODER_CLK 21 // Change A0 to, for example, A5 if you want to use analog pin 5 instead
#define ENCODER_DT 22
#define ENCODER_SW 19

ClickEncoder *encoder; // variable representing the rotary encoder
int16_t last, value; // variables for current and last rotation value

void timerIsr() {
  encoder->service();
}

void setup() {
  Serial.begin(9600); // Opens the serial connection used for communication with the PC. 

  encoder = new ClickEncoder(ENCODER_DT, ENCODER_CLK, ENCODER_SW); // Initializes the rotary encoder with the mentioned pins

  Timer1.initialize(1000); // Initializes the timer, which the rotary encoder uses to detect rotation
  Timer1.attachInterrupt(timerIsr); 
  last = -1;
} 

void loop() {  
  value += encoder->getValue();

  // This part of the code is responsible for the actions when you rotate the encoder
  if (value != last) { // New value is different than the last one, that means to encoder was rotated
    if(last<value) // Detecting the direction of rotation
last = value; // Refreshing the "last" varible for the next loop with the current value
    Serial.print("Encoder Value: "); // Text output of the rotation value used manily for debugging (open Tools - Serial Monitor to see it)
    Serial.println(value);
  }

  // This next part handles the rotary encoder BUTTON
  ClickEncoder::Button b = encoder->getButton(); // Asking the button for it's current state
  if (b != ClickEncoder::Open) { // If the button is unpressed, we'll skip to the end of this if block
    //Serial.print("Button: "); 
    //#define VERBOSECASE(label) case label: Serial.println(#label); break;
    switch (b) {
      case ClickEncoder::Clicked: // Button was clicked once
   break;      
      
      case ClickEncoder::DoubleClicked: // Button was double clicked
         break;      
    }
  }

  delay(10); // Wait 10 milliseconds, we definitely don't need to detect the rotary encoder any faster than that
  // The end of the loop() function, it will start again from the beggining (the begginging of the loop function, not the whole document)
}


/*
    This is just a long comment
    Here are some fun functions you can use to replace the default behaviour 
    Consumer.write(CONSUMER_BRIGHTNESS_UP);
    Consumer.write(CONSUMER_BRIGHTNESS_DOWN);
    Consumer.write(CONSUMER_BROWSER_HOME);
    Consumer.write(CONSUMER_SCREENSAVER);
    Consumer.write(HID_CONSUMER_AL_CALCULATOR); //launch calculator :)
    Consumer.write(HID_CONSUMER_AC_ZOOM_IN);
    Consumer.write(HID_CONSUMER_AC_SCROLL_UP);
    CONSUMER_SLEEP = 0x32,

    FULL LIST CAN BE FOUND HERE:
    https://github.com/NicoHood/HID/blob/master/src/HID-APIs/ConsumerAPI.h
*/
        
