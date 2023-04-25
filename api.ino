int Sensormosture =A0;
int Speaker =13;
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#define I2C_ADDR 0x27
#define BACKLIGHT_PIN 3
#define En_pin 2
#define Rw_pin 1
#define Rs_pin 0
#define D4_pin 4
#define D5_pin 5
#define D6_pin 6
#define D7_pin 7

LiquidCrystal_I2C
lcd(I2C_ADDR, En_pin, Rw_pin, Rs_pin, D4_pin, D5_pin, D6_pin, D7_pin);

void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600);
  pinMode(Sensormosture,INPUT);
   
  lcd.begin(16,2);
lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
lcd.setBacklight(HIGH);
lcd.setCursor(1,0);
lcd.print(" ada api  ");
lcd.setCursor(0,1);
lcd.print(" bahayaaaa  ");

}

void loop() {
  // put your main code here, to run repeatedly:
int dataSensor=analogRead(Sensormosture);
  Serial.println(dataSensor);
  delay(100);
  if (dataSensor<=100){
 digitalWrite(Speaker,LOW);
     lcd.setCursor(1,0);
lcd.print(" ada api  ");
lcd.setCursor(0,1);
lcd.print(" bahayaaaa  ");
  }else{
  digitalWrite(Speaker,HIGH);
    lcd.clear();
  lcd.setCursor(1,0);
lcd.print(" ga ada   ");
lcd.setCursor(0,1);
lcd.print("  AMAN ");

  }
}

