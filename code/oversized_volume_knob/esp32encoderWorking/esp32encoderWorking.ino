// https://github.com/madhephaestus/ESP32Encoder/

#include <ESP32Encoder.h>

ESP32Encoder encoder;


void setup(){
  
  Serial.begin(115200);
  // Enable the weak pull down resistors

  //ESP32Encoder::useInternalWeakPullResistors=DOWN;
  // Enable the weak pull up resistors
  ESP32Encoder::useInternalWeakPullResistors=UP;

  // use pin 21 and 22 for the first encoder
  encoder.attachHalfQuad(21, 22);
    
  // set starting count value after attaching
  encoder.setCount(37);

  // clear the encoder's raw count and set the tracked count to zero
  Serial.println("Encoder Start = " + String((int32_t)encoder.getCount()));
}

void loop(){
  // Loop and read the count
  Serial.println("Encoder count = " + String((int32_t)encoder.getCount()));
  delay(100);
}
