const int controlPin1 = 2;                                            //Set variables equal to pins
const int controlPin2 = 3;
const int enablePin = 9;
const int directionSwitchPin = 4;
const int onOffSwitchPin = 5;
const int potPin = A0;

int onOffSwitchState = 0;                                             //Initialize variables equal to 0
int previousOnOffSwitchState = 0;
int directionSwitchState = 0;
int previousDirectionSwitchState = 0;

int motorEnabled = 0;                                                 //Initialize motorEnabled and motorSpeed = 0
int motorSpeed = 0;
int motorDirection = 1;                                               //Initialize direction = 1. This is the forward direction.

void setup() {
  // put your setup code here, to run once:

  pinMode(directionSwitchPin, INPUT);                                 //Set pin 4 to Input
  pinMode(onOffSwitchPin, INPUT);                                     //Set pin 5 to Input
  pinMode(controlPin1, OUTPUT);                                       //Set pin 2 to Output
  pinMode(controlPin2, OUTPUT);                                       //Set pin 3 to Output
  pinMode(enablePin, OUTPUT);                                         //Set pin 9 to Output

  digitalWrite(enablePin, LOW);                                       //Write output to pin 9 as Low
}

void loop() {
  // put your main code here, to run repeatedly:

  onOffSwitchState = digitalRead(onOffSwitchPin);                     //Variable onOffSwitchState = digital read out (High or Low) of pin 5
  delay(1);
  directionSwitchState = digitalRead(directionSwitchPin);             //Variable directionSwitchState = digital read out (High or Low) of pin 4

  motorSpeed = analogRead(potPin)/4;                                  //Variable motorSpeed = analog read out of potentiometer(pin A0)/4. This is because motor speed = 0 to 256 or analog read out (1023)/4.

  if(onOffSwitchState != previousOnOffSwitchState) {                  //if onOffSwitchState is not equal to previousOnOffSwitchState
    if (onOffSwitchState == HIGH) {                                   //if onOffSwitchState is High
      motorEnabled = !motorEnabled;                                   //Switch state of the motor enable. If it was = 1, it is now = 0. If it was = 0, It is now = 1.
    }
    
  }

  if(directionSwitchState != previousDirectionSwitchState) {          //if directionSwitchState is not equal to previousDirectionSwitchState
    if (directionSwitchState == HIGH) {                               //if directionSwitchState is High
      motorDirection = !motorDirection;                               //Switch state of the motor direction. If it was = 1, it is now = 0. If it was = 0, It is now = 1.
    }
   
  }

  if (motorDirection == 1) {                                          //if motorDirection = 1
    digitalWrite(controlPin1, HIGH);                                  //Pin 2 is High, pin 3 is Low. Motor will spin in one direction
    digitalWrite(controlPin2, LOW);
  }
  else {                                                              //if motorDirection = 0
    digitalWrite(controlPin1, LOW);                                   //Pin 2 is Low, pin 3 is High. Motor will spin in the opposite direction
    digitalWrite(controlPin2, HIGH);                                  
  }

  if(motorEnabled == 1) {                                             //if motorEnabled = 1
    analogWrite(enablePin, motorSpeed);                               //Output the analog value of the motor speed to pin 9
  }
  else{                         
    analogWrite(enablePin, 0);                                        //else, output 0 to the enablePin, pin 9
  }

  previousDirectionSwitchState = directionSwitchState;                //Set previousDirectionSwitchState equal to directionSwitchState before the next loop
  previousOnOffSwitchState = onOffSwitchState;                        //Set previousOnOffSwitchState equal to onOffSwitchState before the next loop

}
