#include<Keypad.h>
#include<LiquidCrystal_I2C.h>
#include<Wire.h>
#define LED1 10
#define LED2 11
#define BUZZER 12
#define ROWS 4
#define COLS 4
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};
Keypad keypad = Keypad(makeKeymap(keys),rowPins,colPins,ROWS,COLS);
LiquidCrystal_I2C lcd(0x27,16,2);
String generatedOTP = "";
String enteredOTP = "";
bool otpGenerated = false;

void setup() {
Serial.begin(9600);
lcd.init();
lcd.backlight();
pinMode(LED1,OUTPUT);
pinMode(LED2,OUTPUT);
pinMode(BUZZER,OUTPUT);
lcd.setCursor(0,0);
lcd.print("OTP Lock System");
delay(2000);
lcd.clear();
lcd.print("Press B for OTP");
}
void loop() {
char key = keypad.getKey();
if(key){
  Serial.print("Key Pressed: ");
  Serial.println(key);
}
if (key=='B'){
  generatedOTP = String(random(100000,999999));
  enteredOTP = "";
  otpGenerated = true;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("OTP: ");
  lcd.setCursor(0,1);
  lcd.print(generatedOTP);
   Serial.print("Generated OTP: ");
  Serial.println(generatedOTP);
}
else if(key=='C'){
  enteredOTP = "";
  lcd.clear();
  lcd.print("OTP Cleared");
  delay(3000);
  lcd.clear();
  lcd.print("Press B for OTP");
}
else if(key=='A'){
  lcd.clear();
  if(enteredOTP==generatedOTP && otpGenerated){
    lcd.print("Correct OTP!");
    digitalWrite(LED1,HIGH);
    digitalWrite(LED2,LOW);
    digitalWrite(BUZZER,LOW);
    delay(3000);
    digitalWrite(LED1,LOW);
    digitalWrite(LED2,LOW);
    digitalWrite(BUZZER,LOW);
  }
  else{
    lcd.print("Wrong OTP");
     digitalWrite(LED1,LOW);
    digitalWrite(LED2,HIGH);
    digitalWrite(BUZZER,HIGH);
    delay(3000);
    digitalWrite(LED1,LOW);
    digitalWrite(LED2,LOW);
    digitalWrite(BUZZER,LOW);
  }
  enteredOTP = "";
  lcd.clear();
  lcd.print("Press B for OTP");
}
else if (key == '*' && enteredOTP.length() > 0) {
    enteredOTP.remove(enteredOTP.length() - 1);
    lcd.setCursor(0, 0);
    lcd.print("Entered:       ");
    lcd.setCursor(0, 1);
    lcd.print(enteredOTP + "      ");
  }
else if (isdigit(key) && enteredOTP.length() < 6) {
    enteredOTP += key;
    lcd.setCursor(0, 0);
    lcd.print("Entered:       ");
    lcd.setCursor(0, 1);
    lcd.print(enteredOTP + "      ");
  }
}
