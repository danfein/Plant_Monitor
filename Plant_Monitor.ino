/*--------------------------------
Plant monitor
Ardino - Sparkfun HTU21D Temp/Humidity breakout
i2c backback on 2 line LCD

//--------------------------------*/
#include <Wire.h>
#include "SparkFunHTU21D.h"
#include <LiquidCrystal_I2C.h>

//Create an instance of the object
HTU21D myHumidity;
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address

void setup() {
  Serial.begin(9600);
  
  lcd.begin(16,2); 
  lcd.backlight();

  myHumidity.begin();

  Serial.println("Startup good");

}

void loop() {
  //Read sensor
  float humd = myHumidity.readHumidity();
  float temp = myHumidity.readTemperature();
  float tempF = (temp * 9.0)/ 5.0 + 32.0;

  //print to serial
  Serial.print(" Temperature:");
  Serial.print(temp);
  Serial.print(" F");
  Serial.print(" Humidity:");
  Serial.print(humd);
  Serial.println("%");

  //print to lcd screen
  lcd.setCursor(0,0);
  lcd.print("temp: ");
  lcd.print(temp);
  lcd.print("F");
  lcd.setCursor(0,2);
  lcd.print("humd: ");
  lcd.print(humd);
  lcd.print("%");
    
  delay(1000);

  


}


