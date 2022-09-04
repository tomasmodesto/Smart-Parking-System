// C++ code//

#include <LiquidCrystal_I2C.h>
#include <Adafruit_LiquidCrystal.h>
#include <Wire.h> 
#include <Servo.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

int distancia = 0;
int cm = 0;
int cm1 = 0;
int distancia1 = 0;
int unnamed = 0;
int i = 0;
int j = 0;
int k = 0;
int m = 0;
int livres = 0;
int ocupados = 0;
int n = 0;
int o = 0;
int p = 0;
int q = 0;
int r = 0;
int s = 0;
int t = 0;
int u = 0;
int v = 0;
int w = 0;
int x = 0;
int y = 0;
int active = 0;
int z = 0;
int a = 0;
int b = 0;
int c = 0;
int d = 0;
int e = 0;
int f = 0;
int g = 0;
int h = 0;
int i2 = 0;
int j2 = 0;
int limite = 0;
int limite1 = 0;
int k2 = 0;
int m2 = 0;
int n2 = 0;

Adafruit_LiquidCrystal lcd_1(0);

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

Servo servo_11;

void setup()
{
  lcd.init();
  lcd.backlight();
  lcd_1.begin(16, 2);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(11, OUTPUT);
  Serial.begin(9600);
  servo_11.attach(11, 500, 2500);

  ocupados = 0;
  livres = 4;
  lcd.print("LIVRES - 4 ");
  delay(3000); // Wait for 1000 millisecond(s)
  lcd.clear();
  lcd.print("OCUPADOS - 0");
  delay(3000); // Wait for 2000 millisecond(s)
  lcd.clear();
}

void loop()
{
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(9, LOW);
  digitalWrite(11, LOW);
  if (ocupados == 0) {
    livres = 4;
  }
  if (ocupados == 1) {
    u = 3;
  }
  if (ocupados == 2) {
    livres = 2;
  }
  if (ocupados == 3) {
    livres = 1;
  }
  if (ocupados == 4) {
    livres = 0;
  }
  livres = livres;
  ocupados = ocupados;
  Serial.println(ocupados);
  Serial.println(livres);
  distancia = 9.35;
  distancia1 = 9.35;
  limite1 = 17.5;
  limite = 17.5;
  cm = 0.01723 * readUltrasonicDistance(2, 3);
  cm1 = 0.01723 * readUltrasonicDistance(4, 5);
  Serial.print(cm);
  Serial.println("cm - ultrasonic 1;");
  Serial.print(cm1);
  Serial.println("cm - ultrasonic 2;");
  Serial.println("--------------------------");
  active = 1;
  if ((ocupados == 4 && livres == 0) && cm < 9.35) {
  
    digitalWrite(11, LOW);
    lcd.print("PARQUE CHEIO");
    delay(1000); // Wait for 1000 millisecond(s)
    lcd.clear();
    delay(500); // Wait for 500 millisecond(s)
    lcd.print("AGUARDE ATRAS");
    delay(1000); // Wait for 1000 millisecond(s)
    lcd.clear();
    delay(1000); // Wait for 1000 millisecond(s)
    lcd.print("DA LINHA");
    delay(1000); // Wait for 1000 millisecond(s)
    lcd.clear();
    Serial.println("PARQUE CHEIO");
    delay(1000); // Wait for 1000 millisecond(s)
    cm = 0.01723 * readUltrasonicDistance(2, 3);
  }
  delay(1000); // Wait for 1000 millisecond(s)
  if ((cm1 > 9.35 && cm1 < limite1) && (ocupados != 0 && livres != 4)) {
    cm1 = 0.01723 * readUltrasonicDistance(4, 5);
    Serial.print("data");
    Serial.println(cm1);
    servo_11.write(90);
    delay(3000); // Wait for 3000 millisecond(s)
  }
  if ((cm > 9.35
  && cm < limite) && (ocupados != 0 && livres != 4)) {
    cm = 0.01723 * readUltrasonicDistance(2, 3);
    ocupados = (ocupados - 1);
    livres = (livres + 1);
    Serial.println(ocupados);
    Serial.println(livres);
    lcd.clear();
    lcd.print("OCUPADOS - ");
    lcd.print(ocupados);
    delay(1000); // Wait for 1000 millisecond(s)
    lcd.clear();
    delay(500); // Wait for 500 millisecond(s)
    lcd.print("LIVRES - ");
    lcd.print(livres);
    delay(1000); // Wait for 1000 millisecond(s)
    lcd.clear();
  }
  while (cm < distancia && (ocupados != 4 && livres != 0)) {
    digitalWrite(4, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(5, HIGH);
    servo_11.write(90);
    cm = 0.01723 * readUltrasonicDistance(2, 3);
    
  }
  if (cm1 < distancia1 && (ocupados != 4 && livres != 0)) {
    digitalWrite(9, HIGH);
    cm1 = 0.01723 * readUltrasonicDistance(4, 5);
    ocupados = (ocupados + 1);
    livres = (livres - 1);
    Serial.println(ocupados);
    Serial.println(livres);
    lcd.print("OCUPADOS - ");
    lcd.print(ocupados);
    delay(2000); // Wait for 2000 millisecond(s)
    lcd.clear();
    delay(1000); // Wait for 1000 millisecond(s)
    lcd.print("LIVRES - ");
    lcd.print(livres);
    delay(2000); // Wait for 2000 millisecond(s)
    lcd.clear();
  }
  delay(200); // Wait for 200 millisecond(s)
  digitalWrite(9, LOW);
  servo_11.write(0);
}