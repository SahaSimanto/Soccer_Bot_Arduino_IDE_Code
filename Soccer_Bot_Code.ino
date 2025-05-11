Soccer bot code

#include <Servo.h>

Servo motor_1;
#define enA 6  //Enable1 L298 Pin enA 
#define in1 A3 //Motor1  L298 Pin in1 
#define in2 A2 //Motor1  L298 Pin in1 
#define in3 A1 //Motor2  L298 Pin in1 
#define in4 A0 //Motor2  L298 Pin in1 
#define enB 6  //Enable2 L298 Pin enB 
#define servoPin 12 //servo motor pin 12 (PWM)

int servo1 = 90;
int bt_data;
int Speed = 255;

void setup(){
  
Serial.begin(9600); // initialize serial communication at 9600 bits per second:
 
motor_1.attach(servoPin);
motor_1.write(servo1); 
 
pinMode(enA, OUTPUT); // declare as output for L298 Pin enA 
pinMode(in1, OUTPUT); // declare as output for L298 Pin in1 
pinMode(in2, OUTPUT); // declare as output for L298 Pin in2 
pinMode(in3, OUTPUT); // declare as output for L298 Pin in3   
pinMode(in4, OUTPUT); // declare as output for L298 Pin in4 
pinMode(enB, OUTPUT); // declare as output for L298 Pin enB

delay(1000);
}

void loop(){
//if some date is sent, reads it and saves in state

if(Serial.available() > 0){     
bt_data = Serial.read(); 
Serial.println(bt_data);
// if(bt_data > 20){Speed = bt_data;}      
}

analogWrite(enA, Speed); // Write The Duty Cycle 0 to 255 Enable Pin A for Motor1 Speed 
analogWrite(enB, Speed); // Write The Duty Cycle 0 to 255 Enable Pin B for Motor2 Speed 


if(bt_data == 1){turnLeft(); }  // if the bt_data is '1' the DC motor will go forward
else if(bt_data == 2){turnRight();}  // if the bt_data is '2' the motor will Reverse
else if(bt_data == 3){forword();}  // if the bt_data is '3' the motor will turn left
else if(bt_data == 4){backword();} // if the bt_data is '4' the motor will turn right
else if(bt_data == 5){Stop(); }     // if the bt_data '5' the motor will Stop

else if(bt_data == 6){turnRight();  delay(400);  bt_data = 5;}
else if(bt_data == 7){turnLeft(); delay(400);  bt_data = 5;}   

else if (bt_data == 8){
// Serial.write("Servo 8");
if(servo1<90){servo1 = servo1+30;}
motor_1.write(servo1);
}
else if (bt_data == 9){
// Serial.write("Servo 9");
if(servo1>0){servo1 = servo1-30;} 
motor_1.write(servo1);
// Serial.write("   ", servo1);
}

delay(30);
}


void backword(){  //forword
digitalWrite(in1, HIGH); //Right Motor forword Pin 
digitalWrite(in2, LOW);  //Right Motor backword Pin 
digitalWrite(in3, LOW);  //Left Motor backword Pin 
digitalWrite(in4, HIGH); //Left Motor forword Pin 
}

void forword(){ //backword
digitalWrite(in1, LOW);  //Right Motor forword Pin 
digitalWrite(in2, HIGH); //Right Motor backword Pin 
digitalWrite(in3, HIGH); //Left Motor backword Pin 
digitalWrite(in4, LOW);  //Left Motor forword Pin 
}

void turnLeft (){ //turnRight
digitalWrite(in1, LOW);  //Right Motor forword Pin 
digitalWrite(in2, HIGH); //Right Motor backword Pin  
digitalWrite(in3, LOW);  //Left Motor backword Pin 
digitalWrite(in4, HIGH); //Left Motor forword Pin 
}

void turnRight(){ //turnLeft
digitalWrite(in1, HIGH); //Right Motor forword Pin 
digitalWrite(in2, LOW);  //Right Motor backword Pin 
digitalWrite(in3, HIGH); //Left Motor backword Pin 
digitalWrite(in4, LOW);  //Left Motor forword Pin 
}

void Stop(){ //stop
digitalWrite(in1, LOW); //Right Motor forword Pin 
digitalWrite(in2, LOW); //Right Motor backword Pin 
digitalWrite(in3, LOW); //Left Motor backword Pin 
digitalWrite(in4, LOW); //Left Motor forword Pin 
}