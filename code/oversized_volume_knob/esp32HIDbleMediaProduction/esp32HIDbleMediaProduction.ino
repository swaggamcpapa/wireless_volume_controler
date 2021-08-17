/**
   YOUTUBE - https://www.youtube.com/watch?v=4sIkW7wogrE
   INSPIRATION - https://blog.prusaprinters.org/3d-print-an-oversized-media-control-volume-knob-arduino-basics_30184/
   WIFI BOARD USED - https://github.com/Heltec-Aaron-Lee/WiFi_Kit_series/blob/master/PinoutDiagram/WIFI%20Kit%2032.pdf
   ESP32 BLE Keyboard library - https://github.com/T-vK/ESP32-BLE-Keyboard
   ENCODER LIBRARY - https://github.com/madhephaestus/ESP32Encoder/
*/

#include <BleKeyboard.h>
#include <ESP32Encoder.h>

BleKeyboard bleKeyboard;
ESP32Encoder encoder;
int32_t previousEncoderCount;

void setup() {
  // Serial.begin(115200);

  // Enable the weak pull down resistors
  //ESP32Encoder::useInternalWeakPullResistors=DOWN;
  // Enable the weak pull up resistors
  ESP32Encoder::useInternalWeakPullResistors = UP;
  // use pin 21 and 22 for the first encoder
  encoder.attachHalfQuad(22, 21);

  // set starting count value after attaching
  encoder.setCount(20);
  previousEncoderCount = (int32_t)encoder.getCount();

  // Serial.println("Starting BLE work!");
  bleKeyboard.begin();
}

void loop() {
  // Serial.println(String(previousEncoderCount));
  // Serial.println(String((int32_t)encoder.getCount()));

  if (bleKeyboard.isConnected()) {
    //    Serial.println("Sending 'Hello world'...");
    //    bleKeyboard.print("Hello world");
    //    delay(1000);
    //
    //    Serial.println("Sending Enter key...");
    //    bleKeyboard.write(KEY_RETURN);
    //    delay(1000);
    //Serial.println(String(previousEncoderCount));
    //Serial.println(String((int32_t)encoder.getCount()));
    if (previousEncoderCount < (int32_t)encoder.getCount()) {
      //Serial.println("Sending Vol UP media key...");
      //Serial.println();
      bleKeyboard.write(KEY_MEDIA_VOLUME_UP);
      previousEncoderCount = (int32_t)encoder.getCount();
    }

    if (previousEncoderCount > (int32_t)encoder.getCount()) {
      //Serial.println("Sending Vol DOWN media key...");
      bleKeyboard.write(KEY_MEDIA_VOLUME_DOWN);
      previousEncoderCount = (int32_t)encoder.getCount();
    }

    //    Serial.println("Sending Ctrl+Alt+Delete...");
    //    bleKeyboard.press(KEY_LEFT_CTRL);
    //    bleKeyboard.press(KEY_LEFT_ALT);
    //    bleKeyboard.press(KEY_DELETE);
    //    delay(100);

    delay(100);
    bleKeyboard.releaseAll();
  }
}
