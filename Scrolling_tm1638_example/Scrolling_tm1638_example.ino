#include <TM1638.h>
// define a module on data pin 8, clock pin 9 and strobe pin 10
TM1638 module(8, 9, 10);
unsigned long a=1;
int i=0;
int defaultDelay=1000;
String variable="This is long sentence";
byte buttons;
void setup()
{

}

void loop()
{
/*for (a=1; a<=100; a++)
{
/*module.setDisplayToDecNumber(a,0,false);
delay(100);
}*/

module.setDisplayToString(variable);
delay(defaultDelay);
while(variable.length()>0)
variable.remove(0, 1);

buttons=module.getButtons();
switch (buttons)
{
  case 0:
  module.setLEDs(0x00);
  defaultDelay=defaultDelay-100;
  break;
  case 1:
  module.setLEDs(0x7F);
  defaultDelay=defaultDelay+100;
  break;
  case 2:
  module.setLEDs(0x0A);
  break;
  case 4:
  module.setLEDs(0xEF);
  break;
  case 8:
  module.setLEDs(0x0F);
  break;
  case 16:
  module.setLEDs(0xBA);
  break;
  case 32:
  module.setLEDs(0xEE);
  break;
  case 64:
  module.setLEDs(0xDF);
  break;
  case 128:
  module.setLEDs(0xCD);
  break;
  default:
  module.setLEDs(0x00);
  break;
}

}
