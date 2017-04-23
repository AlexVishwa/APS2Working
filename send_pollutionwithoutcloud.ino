
#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;



const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
int analogPin = A2;    

unsigned int sensor1 = 0;        // value read from the potg
unsigned int sensor2 = 0;        // value output to the PWM (analog out)
void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
   // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  
}
void breath(unsigned char color)
{

    for(int i=0; i<255; i++)
    {
        lcd.setPWM(color, i);
        delay(5);
    }

    delay(500);
    for(int i=254; i>=0; i--)
    {
        lcd.setPWM(color, i);
        delay(5);
    }

    delay(500);
}

void loop() 
{
 
 int sensorReading = analogRead(analogPin);
  Serial.println(sensorReading);
    if (sensorReading > 500) {
     breath(RGB_RED);
    }
    elseif {
      breath(RGB_BLUE);
    }  
    elseif{
    breath(RGB_GREEN);
    }
  
 
  // read the analog in for Co2 and Co
  sensor1 = analogRead(analogInPin);
  sensor1 = sensor1*4.88;

  
  sensor2 = analogRead(analogInPin2);
  sensor2 = sensor2*4.88;
  
  
  
  // print the results to the serial monitor:
  lcd.setCursor(0,0); Serial.print("CO2(mv)");  lcd.print("CO2(mV)");
  Serial.print(sensor1); lcd.print(sensor1);
  lcd.setCursor(0,1); Serial.print("\tCO(mv)"); lcd.print("CO(mV)");
  Serial.println(sensor2); lcd.print(sensor2);
  delay(1000);
  lcd.clear();
   sensor1= ((sensor1*1996+10)*0.001);
  sensor2=sensor2*0.5;
  lcd.setCursor(0,0); Serial.print("CO2(ppm)");  lcd.print("CO2(ppm)");
  Serial.print(sensor1); lcd.print(sensor1);
  lcd.setCursor(0,1); Serial.print("\tCO(ppm)"); lcd.print("CO(ppm)");
  Serial.println(sensor2); lcd.print(sensor2);
  

  // wait 2 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(1000);
  lcd.clear();
}
