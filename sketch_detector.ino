#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);
#define sensor A0
int estado=0;
#define buzzer 8
byte carga[8]{
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};
int persona;
void setup() {
  lcd.init();
  lcd.backlight();
lcd.setCursor(0,0);
lcd.print("");
pinMode(buzzer, OUTPUT);
digitalWrite(8, 0);
lcd.createChar(0, carga);
Serial.begin(9600);
pinMode(7, OUTPUT);
pinMode(6, OUTPUT);
digitalWrite(7, LOW);
digitalWrite(6, LOW);
}
void alarma(){
    digitalWrite(7, HIGH);
    digitalWrite(6, LOW);
    delay(100);
    tone(8,244,100);    
    digitalWrite(7, LOW);
    digitalWrite(6, HIGH);
    delay(100);
    tone(8,244,100);
    digitalWrite(7, HIGH);
    digitalWrite(6, LOW);
    delay(100);
    tone(8,244,100);    
    digitalWrite(7, LOW);
    digitalWrite(6, HIGH);
    delay(100);
    tone(8,244,100);
    digitalWrite(7, HIGH);
    digitalWrite(6, LOW);
    delay(100);
    tone(8,244,100);   
    digitalWrite(7, LOW);
    digitalWrite(6, HIGH);
    delay(100);
    tone(8,244,100);
 digitalWrite(7, HIGH);
    digitalWrite(6, LOW);
    delay(100);
    tone(8,244,100);    
    digitalWrite(7, LOW);
    digitalWrite(6, HIGH);
    delay(100);
    tone(8,244,100);
    digitalWrite(7, HIGH);
    digitalWrite(6, LOW);
    delay(100);
    tone(8,244,100);    
    digitalWrite(7, LOW);
    digitalWrite(6, HIGH);
    delay(100);
    tone(8,244,100);
    digitalWrite(7, HIGH);
    digitalWrite(6, LOW);
    delay(100);
    tone(8,244,100);   
    digitalWrite(7, LOW);
    digitalWrite(6, HIGH);
    delay(100);
    tone(8,244,100);    

 digitalWrite(7, HIGH);
    digitalWrite(6, LOW);
    delay(100);
    tone(8,244,100);    
    digitalWrite(7, LOW);
    digitalWrite(6, HIGH);
    delay(100);
    tone(8,244,100);
    digitalWrite(7, HIGH);
    digitalWrite(6, LOW);
    delay(100);
    tone(8,244,100);    
    digitalWrite(7, LOW);
    digitalWrite(6, HIGH);
    delay(100);
    tone(8,244,100);
    digitalWrite(7, HIGH);
    digitalWrite(6, LOW);
    delay(100);
    tone(8,244,100);   
    digitalWrite(7, LOW);
    digitalWrite(6, HIGH);
    delay(100);
    tone(8,244,100);
 digitalWrite(7, HIGH);
    digitalWrite(6, LOW);
    delay(100);
    tone(8,244,100);    
    digitalWrite(7, LOW);
    digitalWrite(6, HIGH);
    delay(100);
    tone(8,244,100);
    digitalWrite(7, HIGH);
    digitalWrite(6, LOW);
    delay(100);
    tone(8,244,100);    
    digitalWrite(7, LOW);
    digitalWrite(6, HIGH);
    delay(100);
    tone(8,244,100);
    digitalWrite(7, HIGH);
    digitalWrite(6, LOW);
    delay(100);
    tone(8,244,100);   
    digitalWrite(7, LOW);
    digitalWrite(6, HIGH);
    delay(100);
    tone(8,244,100);        
    digitalWrite(7, LOW);
    digitalWrite(6, LOW);
}
void robo(){
    alarma();
    puertas();
    gas();
    
}
void puertas(){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Cerrando compuertas");
  lcd.setCursor(0, 2);
  lcd.print("Liberando...");
  for (int i = 0; i < 21; i++) {
    if (i == 20) {
      lcd.clear();
      lcd.print("");
    } else {
      lcd.setCursor(i, 3);
      lcd.write(0);
      delay(150);
    }
  }
}

void gas(){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Soltando gas");
  lcd.setCursor(0, 2);
  lcd.print("Liberando...");
  for (int i = 0; i < 21; i++) {
    if (i == 20) {
      lcd.clear();
      lcd.print("Completamente seguro");
    } else {
      lcd.setCursor(i, 3);
      lcd.write(0);
      delay(150);
    }
  }
}

void obj_sensor(){
  estado = analogRead(sensor);
  estado = map(estado, 0, 1023, 0, 100);  
  if(estado==0){
  robo();
}else{
  int s=5;
  do{
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Salir de la bobeda");
    lcd.setCursor(0,2);
    lcd.print("Las alarmas activas");
    lcd.setCursor(0,3);
    lcd.print(" en: ");
    lcd.print(s);    
    s=s-1;
    delay(1000);
    }while(s!=0);
    if(Serial.available()>0){
    persona=Serial.read();
  if(persona=='P'){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Persona desconocida detectada");
    lcd.setCursor(0,2);
    robo();
  }if(persona=='N'){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("No se detecta nadie en la bobeda");
    lcd.setCursor(0,2);
    lcd.print("Bobeda cerrada");
  }
  }delay(1000);
}
}
void pasw(){
    if(!digitalRead(1)){
      Serial.print("1");
    }else if(!digitalRead(2)){
      Serial.print("2");     
    }else if(!digitalRead(3)){
      Serial.print("3");
    }
}

void loop() {
  if(Serial.available()>0){
    persona=Serial.read();
  if(persona=='P'){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Persona desconocida detectada");
    lcd.setCursor(0,2);
    obj_sensor();
    /*lcd.print("Ingrese la contraseña:  ");
    int pasword=pasw();
    if(pasword==312){
      lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Contraseña correcta");
    lcd.setCursor(0,2);
    }else{
    lcd.print("Bobeda desbloqueada");      
      obj_sensor();
    }*/
    
  }if(persona=='N'){
    lcd.setCursor(0,0);
    lcd.print("No se detecta nadie en la bobeda");
    lcd.setCursor(0,2);
    lcd.print("Bobeda cerrada");
  }
  }delay(1000);
}
