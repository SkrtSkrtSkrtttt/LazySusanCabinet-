#include <Stepper.h>

const long stepsPerRevolution = 200;  // set the steps per revolution

// initialize the stepper library on pins 8 through 11:
Stepper myStepper1(stepsPerRevolution, 8, 9, 10, 11);
// initialize the stepper library on pins 4 through 7:
Stepper myStepper2(stepsPerRevolution, 4, 5, 6, 7);

int command = 0; // start the switch case function at 0
int time = 50; // delay time
// function that turns the stepper motor to set degree
const float Steps = 64;
long step_degree(float desired_degree) {
  return (desired_degree / Steps);
}

const int degree = 27000; // the degree used to rotate 72 degree
// values used to for spin function
int CAngle = 0;
int CAngle2 = 6;
int DAngle;
int DAngle2;
int num = 0;
int na;
int nb;

void setup() {
  // set the speed at 185 rpm:
  myStepper1.setSpeed(185);
  myStepper2.setSpeed(64);
  // initialize the serial port:
  Serial.begin(9600);
  // text to assist participants with the usage of the program
  Serial.println("Press 0-4 to turn the top wheel");
  Serial.println("Press 6-10 to turn the bottom wheel");
  Serial.println("Press 11 to reset system");
}

void loop() {
  // switch case function that connects inputs to numbers
  while (Serial.available() > 0) {
    command = Serial.readString().toInt();
    switch (command) {
      // Spin1: 0-4
      // controls the top wheel, spinning it from position 0 to position 4
      case 0:
        Serial.println('0');
        DAngle = 0;
        Spin1(degree);
        delay(time);
        break;
      case 1:
        Serial.println('1');
        DAngle = 1;
        Spin1(degree);
        delay(time);
        break;
      case 2:
        Serial.println('2');
        DAngle = 2;
        Spin1(degree);
        delay(time);
        break;
      case 3:
        Serial.println('3');
        DAngle = 3;
        Spin1(degree);
        delay(time);
        break;
      case 4:
        Serial.println('4');
        DAngle = 4;
        Spin1(degree);
        delay(time);
        break;

      // Spin2: 6-10
      // controls the bottom wheel, spinning it from position 6 to position 10
      case 6:
        Serial.println('6');
        DAngle2 = 6;
        Spin2(degree);
        delay(time);
        break;
      case 7:
        Serial.println('7');
        DAngle2 = 7;
        Spin2(degree);
        delay(time);
        break;
      case 8:
        Serial.println('8');
        DAngle2 = 8;
        Spin2(degree);
        delay(time);
        break;
      case 9:
        Serial.println('9');
        DAngle2 = 9;
        Spin2(degree);
        delay(time);
        break;
      case 10:
        Serial.println("10");
        DAngle2 = 10;
        Spin2(degree);
        delay(time);
        break;

      // Reset: 11
      // after the program finish, use this to reset machine back to original position of 0 and 6
      case 11:
        Serial.println("System Reset");
        num++;
        break;
    }
    // use to reset the program back to original position
    if (num == 1) {
      DAngle = 0;
      Spin1(degree);
      delay(time);

      DAngle2 = 6;
      Spin2(degree);
      delay(time);
    }
  }
}

// function design to spin the top wheel
void Spin1 (int n1) {
  // if current angle is not equal to desired angle
  if (CAngle != DAngle) {
    // if current angle is less than desired angle, the top wheel will move
    // by the difference multiplied by 72 degrees.
    if (CAngle < DAngle) {
      na = DAngle - CAngle;
      myStepper1.step(step_degree(n1)*na); //375 per one degree.
      delay(time);
      CAngle = DAngle;
    }
    // if current angle is more than desired angle, the top wheel will move
    // by the difference plus 5, and then the total will be multiplied by 72 degrees.
    if (CAngle > DAngle) {
      na = (DAngle - CAngle) + 5;
      myStepper1.step(step_degree(n1)*na); //375 per one degree.
      delay(time);
      CAngle = DAngle;
    }
    // else stop the top wheel from moving
    else {
      myStepper1.step(step_degree(0));
    }
  }
}

// function design to spin the bottom wheel
void Spin2 (int n2) {
  // if current angle #2 is not equal to desired angle #2
  if (CAngle2 != DAngle2) {
    // if current angle #2 is less than desired angle #2, the bottom wheel will move
    // by the difference multiplied by 72 degrees.
    if (CAngle2 < DAngle2) {
      nb = DAngle2 - CAngle2;
      Serial.println(nb);
      myStepper2.step((step_degree(n2))*nb);
      delay(time);
      CAngle2 = DAngle2;
    }
    // if current angle #2 is more than desired angle #2, the bottom wheel will move
    // by the difference plus 5, and then the total will be multiplied by 72 degrees.
    if (CAngle2 > DAngle2) {
      nb = (DAngle2 - CAngle2) + 5;
      Serial.println(nb);
      myStepper2.step((step_degree(n2))*nb); 
      delay(time);
      CAngle2 = DAngle2;
    }
    // else stop the bottom wheel from moving
    else {
      myStepper2.step(step_degree(0));
    }
  }
}
