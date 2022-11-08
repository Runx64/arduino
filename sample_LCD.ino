#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup()
{
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0, 0); // กำหนดตำแหน่งพิมพ์ ตัวที่ 0 บรรทัดที่ 0
  lcd.print("Arduino TEST!!!");
  lcd.setCursor(1, 1); // กำหนดตำแหน่พิมพ์ ตัวที่ 2 บรรทัดที่ 1
  lcd.print("KPN");
}
void loop() {
  //ตัวอย่างแสดงค่าตัวแปร
  int temp = 25;
  lcd.setCursor(6, 1);
  lcd.print("TEMP:");
  lcd.setCursor(11, 1);
  lcd.print(temp);
}
