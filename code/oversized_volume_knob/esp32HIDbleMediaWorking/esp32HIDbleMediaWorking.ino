/**
 * This example turns the ESP32 into a Bluetooth LE keyboard that writes the words, presses Enter, presses a media key and then Ctrl+Alt+Delete
 */
#include <BleKeyboard.h>

BleKeyboard bleKeyboard;

void setup() {
  Serial.begin(115200);
  Serial.println("Starting BLE work!");
  bleKeyboard.begin();
}

void loop() {

  if(bleKeyboard.isConnected()) {
//    Serial.println("Sending 'Hello world'...");
//    bleKeyboard.print("Hello world");
//    delay(1000);
//
//    Serial.println("Sending Enter key...");
//    bleKeyboard.write(KEY_RETURN);
//    delay(1000);

    Serial.println("Sending Vol UP media key...");
    bleKeyboard.write(KEY_MEDIA_VOLUME_UP);
    delay(1000);

    Serial.println("Sending Vol DOWN media key...");
    bleKeyboard.write(KEY_MEDIA_VOLUME_DOWN);
    delay(1000);

//    Serial.println("Sending Ctrl+Alt+Delete...");
//    bleKeyboard.press(KEY_LEFT_CTRL);
//    bleKeyboard.press(KEY_LEFT_ALT);
//    bleKeyboard.press(KEY_DELETE);
//    delay(100);
    bleKeyboard.releaseAll();
  }
}
