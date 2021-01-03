#include <Servo.h>



//Constants

const int pResistor = A0; // Photoresistor at Arduino analog pin A0



//Variables
Servo motor_servo;
int value;          // Store value from photoresistor (0-1023)

void setup(){
 pinMode(pResistor, INPUT);// Set pResistor - A0 pin as an input (optional)
 motor_servo.attach(9);// attaches the servo on pin 9 to the servo object 
 motor_servo.write(70);
}

void loop(){
  
  value = analogRead(pResistor);
  if(motor_servo.read() != 100){
    motor_servo.write(100);
  }
  delay(1);
  
  if (value < 250){
    motor_servo.write(70);
    delay(100);
  }
  
}
