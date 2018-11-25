//#include <LiquidCrystal.h>
//LiquidCrystal lcd(2, 4, 9, 10, 11, 12);
#include <AFMotor.h>
const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
AF_DCMotor motor(2);
//const int MotorInPin2 = 6;

int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)
int percentValue = 0;

void setup() {
 Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Motor test!");

  // turn on motor
  motor.setSpeed(200);
 
  motor.run(RELEASE);
}

void loop() {

  // read the analog in value:
  sensorValue = analogRead(analogInPin);
  // map it to the range of the analog out:
  outputValue = map(sensorValue, 0, 1023, 0, 255);
  // map it to the range of the percentValue:
  percentValue = map(outputValue, 0, 255, 0, 100);

  // Motor control
  //analogWrite(MotorInPin1, outputValue);
  //analogWrite(MotorInPin2, LOW);

  // print the results to the Serial Monitor:
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.print(outputValue);
  Serial.print("\t percent = ");
  Serial.print(percentValue);
  Serial.println("%");
if(percentValue>=60)
{
  Serial.println("pump start");
    uint8_t i;
  
  Serial.print("tick");
  
  motor.run(FORWARD);
  for (i=0; i<255; i++) {
    motor.setSpeed(i);  
    delay(10);
 }
 
  for (i=255; i!=0; i--) {
    motor.setSpeed(i);  
    delay(10);
 }
  
  Serial.print("tock");

  motor.run(BACKWARD);
  for (i=0; i<255; i++) {
    motor.setSpeed(i);  
    delay(10);
 }
 
  for (i=255; i!=0; i--) {
    motor.setSpeed(i);  
    delay(10);
 }
  

  Serial.print("tech");
  motor.run(RELEASE);
  delay(1000);
}
else
if(percentValue<=30)
{
  Serial.println("pumpstop");
  Serial.print("\t percent = ");
  Serial.print(percentValue);
  Serial.println("%");
  Serial.print("\t percent = ");
  Serial.print(percentValue);
  Serial.println("%");
  exit(0);
}

  // wait 2 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading:
  //delay(2);
  // print the results to the Lcd display:
  //lcd.setCursor(0, 0);
  //lcd.print("Dc Water Pump");
  //lcd.setCursor(0, 1);
  //lcd.print("Speed: ");
  //lcd.print(percentValue);
  //lcd.print(" %");
  delay(200);
  //lcd.clear();
}

