# Arduino-Multi-Direction-Motor

This project has a DC motor that is turned on/off by a switch, changes the direction it spins with another switch, and has the speed it rotates at controlled by a potentiometer.
In order to change the direction of the motor, I used an H-bridge IC which flips the polarity of the power and ground to the motor.
The potentiometer adjusts the Pulse Width Modulation output between 0 and 5V from the Arduino that is going into the Enable Pin of the H-Bridge. This determines the speed of the motor. (0V off, 5V max speed)

A demo can be seen at the following link to my Google Drive: https://drive.google.com/folderview?id=0BzlL2mOr29jDOTRyZG40NEtRWms&usp=sharing
