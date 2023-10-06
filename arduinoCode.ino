//#include <LiquidCrystal_I2C.h>
//#include <Wire.h>
//
//LiquidCrystal_I2C lcd(0x32,16,2);  
/*يتم تعطيل دائره ال 7segment بمجرد إلغاء التعليق من الاوامر 
الخاصه بال LCD*/

int forceSensor =A0;

int buttons[10] = {2,3,4,5,6,7,8,9,10,11};
int segment[7] = {12,13, A1,A2,A3,A4,A5};
byte numbers[10] = {
  0b00111111, 
  0b00000110, 
  0b01011011, 
  0b01001111, 
  0b01100110, 
  0b01101101, 
  0b01111101, 
  0b00000111, 
  0b01111111, 
  0b01101111    
};

void setup() {
//  lcd.init();
//  lcd.backlight();
 pinMode(forceSensor,INPUT);
for(int i=0; i<7; i++){
  pinMode(segment[i],OUTPUT);
  }

for(int i=0; i<10; i++){
  pinMode(buttons[i],INPUT);
  }
 
  Serial.begin(9600);

}

void loop (){
int forceRead = analogRead(forceSensor);
//lcd.setCursor(0,2);
//lcd.print(forceRead);
  Serial.println(forceRead);
  for (int i=0; i<10; i++){
    if(digitalRead(buttons[i])==1){
      getNum(i);
      delay(1000);
Serial.println(i);
      }
    }
  }


  void getNum(int num) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segment[i], bitRead(numbers[num], i));
  }
  }
