#include "Arduino.h"
#include <TM1638.h>
// define a module on data pin 8, clock pin 9 and strobe pin 10
TM1638 module(8, 9, 10);
int ledON=0;
long interval=1000;
String textScroll="This is long sentence";
String bckp;
byte buttons;
unsigned long previousMillis = 0;

void setup()
{
  bckp = textScroll;
}

void loop()
{

module.setDisplayToString(textScroll);
unsigned long currentMillis = millis();

if (currentMillis - previousMillis >= interval) {
  // save the last time you blinked the LED
  previousMillis = currentMillis;
  if(textScroll.length()>0){
    textScroll.remove(0, 1);
    if(textScroll.length()<8){
      module.clearDisplayDigit(textScroll.length(), false);
    }
  } else {
    textScroll = bckp;
  }
}

buttons=module.getButtons();
if(buttons==1) {
  module.setLED(TM1638_COLOR_RED, 0);
  interval=500;
  delay(100);
}if (buttons==4) {
  module.setLED(TM1638_COLOR_RED, 2);
  interval=1500;
  delay(100);
}if (buttons==8) {
  module.setLED(TM1638_COLOR_RED, 3);
  interval=2500;
  delay(100);
}
module.setLED(0, 0);
module.setLED(0, 2);
module.setLED(0, 3);

}
