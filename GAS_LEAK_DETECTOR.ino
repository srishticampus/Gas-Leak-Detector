#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // Change 0x27 if your I2C address is different

int mq3Pin = A0; 
int sensorValue = 0;

void setup() {
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(mq3Pin); // Read MQ-3 analog value
  Serial.println(sensorValue);
  if (sensorValue >=100)
  lcd.print("GAS_LEAK");
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("GAS VALUE:");
  lcd.setCursor(0, 1);
  lcd.print(sensorValue);

  delay(500);
}


