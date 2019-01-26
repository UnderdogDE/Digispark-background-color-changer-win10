#include "DigiKeyboard.h"
#define KEY_DOWN_ARROW   0x51
void digiBegin() {
  DigiKeyboard.sendKeyStroke(0,0);
  DigiKeyboard.delay(50);
}
void digiEnd() {
  const int led=1;
  pinMode(led, OUTPUT);
  while (1) {
    digitalWrite(led, !digitalRead(led));
    DigiKeyboard.delay(700);
  }
}
void printText(fstr_t *txt) {
  DigiKeyboard.print(txt);
  DigiKeyboard.update();
}
void setup() {
  digiBegin();
  DigiKeyboard.sendKeyStroke(KEY_U, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  printText(F("background"));
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_DOWN_ARROW);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_DOWN_ARROW);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.sendKeyStroke(KEY_F4, MOD_ALT_LEFT);
  digiEnd();
}
void loop() {}
