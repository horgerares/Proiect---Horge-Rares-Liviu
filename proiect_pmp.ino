#include <Servo.h>

//note
#define NOTE_C4 262
#define NOTE_G3 196

//Constants

const int pResistor = A0; // Photoresistor at Arduino analog pin A0

// melodia ca lista de note
int melody[] = {NOTE_C4, NOTE_G3, NOTE_G3};

//introducem durata pentru fiecare notă din melodie


//Variables
Servo motor_servo;
int value;          // Store value from photoresistor (0-1023)

void setup(){
 pinMode(pResistor, INPUT);// Set pResistor - A0 pin as an input (optional)
 motor_servo.attach(9);// attaches the servo on pin 9 to the servo object 
 motor_servo.write(100);
}

void loop(){
  
  value = analogRead(pResistor);
  if(motor_servo.read() != 100){
    motor_servo.write(100);
  }
  delay(1);
  
  if (value < 255){ 
    motor_servo.write(60);

    tone(8, melody[0],100);
    delay(100);
    
    noTone(8);

    
    delay(100);
  }
  
}
