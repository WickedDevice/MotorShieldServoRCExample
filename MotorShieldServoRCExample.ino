#include <math.h>
#include <WickedMotorShield.h>
#include <Servo.h>

WickedMotorShield m;
long ch1;
long ch2;
const int timeout = 25000;

Servo servo1;
Servo servo2;

void setup() {
  Serial.begin(115200);
  Serial.print("Hello World!");  

  servo1.attach(5);  // servo1 on M3
  servo2.attach(10); // servo2 on M4
}

void loop(){
  //STEP 1: Read in the RC values
  ch1 = m.getRCIN(RCIN1, timeout);
  ch2 = m.getRCIN(RCIN2, timeout);

  Serial.print(ch1);
  Serial.print("\t");
  Serial.println(ch2);

  // STEP 2: 
  // pass through the RC input to one or more Servos of your choice
  // first constrain ch1 and ch2 to the range of 1000 to 2000
  ch1 = constrain(ch1, 1000, 2000);
  ch2 = constrain(ch2, 1000, 2000);

  // the servo write function wants an integer between 0 and 180
  // with 90 corresponding to no movement / neutral position (and which should be a 1.5ms pulse)
  // so we need to map the ch values back to this range from milliseconds
  int val1 = map(ch1, 1000, 2000, 0, 180);
  int val2 = map(ch2, 1000, 2000, 0, 180);

  servo1.write(val1);
  servo2.write(val2);
  // you could write to additional servo objects here as well
  // for example to drive multiple servos from the same RC control input
}


