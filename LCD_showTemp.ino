#include "DHT.h"
#define DHTPIN 4        //ขาdata ต่อ ขา4
#define DHTTYPE DHT11   //กำหนดค่าตามชนิดDHTที่ใช้งาน
DHT dht(DHTPIN, DHTTYPE);
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2); 
void setup()
{
  Serial.begin(9600);
  Serial.println("DHTxx test!");
  dht.begin();
  lcd.begin();
  lcd.backlight();
}

void loop() {

  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" *C ");
  lcd.setCursor(0, 0);
  lcd.print("Humidity:"); //พิมพ์ข้อความ
  lcd.setCursor(11, 0);
  lcd.print(h); //พิมพ์ข้อความ
  lcd.setCursor(0, 1);
  lcd.print("Temp:"); //พิมพ์ข้อความ  
  lcd.setCursor(11, 1);
  lcd.print(t); //พิมพ์ข้อความ
  delay(500);
}
