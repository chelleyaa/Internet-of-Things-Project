#define DHTPIN 13      // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11  // DHT 22  (AM2302), AM2321
#define SENSOR A0      // Set the A0 as SENSOR
#define relayheater 14
#define relaykipas 27
#define LED 4

#define BLYNK_TEMPLATE_ID "TMPL63T8fffDL"
#define BLYNK_TEMPLATE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN "IGQmAHPGeFwZ9e-lGj_FyGX7SBgbkd74"
#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include "DHT.h"
#include <LiquidCrystal_I2C.h>

char ssid[] = "LT1";
char pass[] = "22446688";

int kelembaban;
float suhu;

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);  // Set the LCD address to 0x27 for a 16 chars and 2 line display

BLYNK_WRITE(V3) {
  int saklar = param.asInt();
  if (saklar == 1) {
    digitalWrite(LED, HIGH);  //LED nyala
  } else {
    digitalWrite(LED, LOW);  //LED mati
  }
}

void setup() {
  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  dht.begin();
  lcd.init();      // Initialize the LCD
  lcd.backlight();  // Turn on the backlight

  pinMode(relayheater, OUTPUT);
  pinMode(relaykipas, OUTPUT);
  digitalWrite(relayheater, HIGH);  //Heater OFF dulu
  digitalWrite(relaykipas, HIGH);   //Kipas OFF dulu

  pinMode(LED, OUTPUT);

  lcd.setCursor(0, 0);
  lcd.print("STARTING UP...");
  lcd.setCursor(0, 1);
  lcd.print("SMART INCUBATOR");
  delay(3000);
  lcd.clear();
}

void sendData(){
 
 int sensor = analogRead(SENSOR);
  /* 4 is mininum width, 2 is precision; float value is copied onto str_sensor*/
  Serial.print("ADC EKG:");
  Serial.println(sensor);
  Blynk.virtualWrite(V2, sensor);

  if(sensor <= 1241 && suhu >= 2072){
 
    Blynk.logEvent("ecg_warning","Darurat! Detak Jantung Bayi Tidak Normal");
  }
  else {
   }
}


void loop() {
  Blynk.run();
  suhu = dht.readTemperature();
  Serial.print("Suhu: ");
  Serial.print(suhu);
  Serial.println("C");
  Blynk.virtualWrite(V0, suhu);

  kelembaban = dht.readHumidity();
  Serial.print("Kelembaban: ");
  Serial.print(kelembaban);
  Serial.println("%");
  Blynk.virtualWrite(V1, kelembaban);

  int sensor = analogRead(SENSOR);
  /* 4 is mininum width, 2 is precision; float value is copied onto str_sensor*/
  Serial.print("ADC EKG:");
  Serial.println(sensor);
  Blynk.virtualWrite(V2, sensor);

  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(suhu, 1);
  lcd.print("C");

  lcd.print("   H:");
  lcd.print(kelembaban);
  lcd.print("%");

  lcd.setCursor(0, 1);
  lcd.print("EKG:");
  lcd.print(sensor);



  if (suhu <= 19) {
    digitalWrite(relayheater, LOW);  //nyala
    digitalWrite(relaykipas, HIGH);  //mati
  }
  if (suhu >= 20 && suhu <= 25) {
    digitalWrite(relayheater, HIGH);  //mati
    digitalWrite(relaykipas, HIGH);   //mati
  }
  if (suhu >= 26) {
    digitalWrite(relayheater, HIGH);  //mati
    digitalWrite(relaykipas, LOW);    //nyala
  }

  Serial.println("--------------------------------------------");
  delay(1000); /* Wait for 0.1 detik */
  lcd.clear();
}