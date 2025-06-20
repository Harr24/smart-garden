/*************
 * IoT Smart Garden dg Android (Blynk)
 * Board  : NodeMCU  V3
 * Input  : Soil Moisture, DHT11, DS18B20
 * Output : Relay, Blynk Android & LCD 16x2
 *************/

#define BLYNK_TEMPLATE_ID "masukin template id blynk kamu"
#define BLYNK_TEMPLATE_NAME "Smart Garden"
#define BLYNK_AUTH_TOKEN "masukin token blynk kamu"

#include <DallasTemperature.h>
#include <OneWire.h>
#include <DHT.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define BLYNK_PRINT Serial

#define ONE_WIRE_BUS D5
#define DHTPIN D3
#define DHTTYPE DHT11
#define pump D6

DHT dht(DHTPIN, DHTTYPE);
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int AirValue = 620;
const int WaterValue = 310;
int soilMoistureValue = 0;
int soilmoist = 0;
int humi, temp, fp, sistem;
int buttonState;

//-- GANTI SESUAI DENGAN NILAI SET POINT ANDA
int SP_LOW = 40;
int SP_HIGH = 60;

//--- GANTI SESUAI DENGAN JARINGAN WIFI KAMU
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "******";  // Nama wifi atau hospot kamu
char pass[] = "*******"; // password wifi atau hospot kamu

//================= KONTROL MODE OTOMATIS / MANUAL =================//
BLYNK_WRITE(V4)
{
    buttonState = param.asInt();
    if (buttonState == HIGH)
    {
        sistem = 1; // automatic
        fp = 0;
    }
    else
    {
        sistem = 0; // manual
    }
}

//================= KONTROL POMPA MANUAL =================//
BLYNK_WRITE(V5)
{
    buttonState = param.asInt();
    if (sistem == 0)
    { // mode manual
        if (buttonState == HIGH)
        {
            digitalWrite(pump, HIGH); // nyalakan pompa
            fp = 1;                   // update flag pompa nyala
            lcd.setCursor(13, 1);
            lcd.print("ON ");
        }
        else
        {
            digitalWrite(pump, LOW); // matikan pompa
            fp = 0;                  // update flag pompa mati
            lcd.setCursor(13, 1);
            lcd.print("OFF");
        }
    }
}

//================= SETUP =================//
void setup()
{
    Wire.begin(D2, D1); // Pastikan LCD I2C terbaca
    lcd.init();
    lcd.backlight();
    lcd.clear();
    lcd.print("  Smart Garden  ");
    lcd.setCursor(0, 1);
    lcd.print("   NodeMCU V3   ");

    Serial.begin(9600);
    sensors.begin();
    dht.begin();
    pinMode(pump, OUTPUT);
    digitalWrite(pump, LOW);

    delay(1200);
    digitalWrite(pump, HIGH);
    delay(1200);
    digitalWrite(pump, LOW);
    delay(1200);
    digitalWrite(pump, HIGH);
    delay(1200);

    Blynk.begin(auth, ssid, pass);
    delay(1500);
    lcd.clear();
    lcd.print("Mst=   %, T=   C");
    lcd.setCursor(0, 1);
    lcd.print("Hum=   %, P= OFF");
}

//================= LOOP =================//
void loop()
{
    Blynk.run();
    sensors.requestTemperatures();
    temp = sensors.getTempCByIndex(0);

    Serial.print("Temp : ");
    Serial.println(temp);
    lcd.setCursor(12, 0);
    lcd.print(temp);
    lcd.print(" ");

    soilMoistureValue = analogRead(A0);
    soilmoist = map(soilMoistureValue, AirValue, WaterValue, 0, 100);
    soilmoist = constrain(soilmoist, 0, 100);

    Serial.print("Soil Moisture : ");
    Serial.print(soilmoist);
    Serial.println("%");
    lcd.setCursor(4, 0);
    lcd.print(soilmoist);
    lcd.print(" ");

    humi = dht.readHumidity();
    if (!isnan(humi))
    {
        Serial.print("Humi: ");
        Serial.println(humi);
        lcd.setCursor(4, 1);
        lcd.print(humi);
        lcd.print(" ");
    }
    else
    {
        Serial.println("DHT11 tidak terbaca!");
        return;
    }

    // ===== Kontrol Otomatis Pompa =====
    if (sistem == 1)
    {
        if (soilmoist < SP_LOW && fp == 0)
        {
            digitalWrite(pump, HIGH);
            lcd.setCursor(13, 1);
            lcd.print("ON ");
            fp = 1;
        }
        else if (soilmoist > SP_HIGH && fp == 1)
        {
            digitalWrite(pump, LOW);
            lcd.setCursor(13, 1);
            lcd.print("OFF");
            fp = 0;
        }
    }

    // ===== Kirim ke Blynk App =====
    Blynk.virtualWrite(V1, temp);
    Blynk.virtualWrite(V2, soilmoist);
    Blynk.virtualWrite(V3, humi);

    Serial.print("Sistem = ");
    Serial.println(sistem);
    Serial.print("fp = ");
    Serial.println(fp);

    delay(1500);
}
