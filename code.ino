#define BLYNK_TEMPLATE_ID "TMPL3lU5QYr36"
#define BLYNK_TEMPLATE_NAME "smart agriculture irrigation system"
#define BLYNK_AUTH_TOKEN "UQ0m5Fh3yKzHGd3Fv8othKqgsXPkmHwd"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

char ssid[] = "Pramod";
char pass[] = "pr8861pr8861";

#define DHTPIN 4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

#define SOIL_PIN 34
#define RELAY_PIN 26
#define BUZZER_PIN 25

#define TRIG_PIN 27
#define ECHO_PIN 14

LiquidCrystal_I2C lcd(0x27, 16, 2);

BlynkTimer timer;

// ---------- SENSOR FILTER ----------
int readSoil()
{
  long sum = 0;

  for(int i=0; i<5; i++)
  {
    sum += analogRead(SOIL_PIN);
    delay(5);
  }

  return sum / 5;
}

float readDistance()
{
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH, 30000);

  if(duration == 0)
    return 999;

  return duration * 0.034 / 2;
}

void sendSensor()
{
  float temp = dht.readTemperature();

  if(isnan(temp))
  {
    Serial.println("DHT Error");
    return;
  }

  int soil = readSoil();

  float distance = readDistance();

  // ---------------- PUMP LOGIC ----------------

  bool pumpON = false;

  // DRY SOIL -> Pump ON
  if(temp > 30 && soil < 3000)
  {
    pumpON = true;
  }

  // WET SOIL -> Pump OFF
  else if(soil > 2500)
  {
    pumpON = false;
  }

  else
  {
    pumpON = false;
  }

  // Active LOW Relay
  digitalWrite(RELAY_PIN, pumpON ? LOW : HIGH);

  Blynk.virtualWrite(V3, pumpON);

  // ---------------- BUZZER LOGIC ----------------

  bool buzzerON = false;

  if(distance <= 10)
  {
    buzzerON = true;
  }
  else
  {
    buzzerON = false;
  }

  digitalWrite(BUZZER_PIN, buzzerON);

  Blynk.virtualWrite(V4, buzzerON);

  // ---------------- LCD ----------------

  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("T:");
  lcd.print(temp);
  lcd.print("C");

  lcd.setCursor(8,0);
  lcd.print("D:");
  lcd.print(distance);
  lcd.print("cm");

  lcd.setCursor(0,1);
  lcd.print("S:");
  lcd.print(soil);

  // ---------------- SERIAL MONITOR ----------------

  Serial.print("Temp: ");
  Serial.println(temp);

  Serial.print("Soil: ");
  Serial.println(soil);

  Serial.print("Distance: ");
  Serial.println(distance);
}

void setup()
{
  Serial.begin(115200);

  pinMode(SOIL_PIN, INPUT);

  pinMode(RELAY_PIN, OUTPUT);

  pinMode(BUZZER_PIN, OUTPUT);

  pinMode(TRIG_PIN, OUTPUT);

  pinMode(ECHO_PIN, INPUT);

  // Relay OFF initially
  digitalWrite(RELAY_PIN, HIGH);

  digitalWrite(BUZZER_PIN, LOW);

  lcd.init();

  lcd.backlight();

  dht.begin();

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  timer.setInterval(2000L, sendSensor);
}

void loop()
{
  Blynk.run();

  timer.run();
}