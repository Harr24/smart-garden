# Smart Garden IoT

Sistem penyiraman tanaman otomatis berbasis IoT dengan mikrokontroler NodeMCU (ESP8266), sensor kelembaban tanah, suhu dan kelembaban udara, serta aplikasi Blynk Android.

## Fitur

- Otomatis & manual kontrol pompa air
- Monitoring suhu, kelembaban tanah, dan kelembaban udara via smartphone
- Tampilan LCD lokal (16x2)
- IoT berbasis aplikasi Blynk

## Komponen

- NodeMCU ESP8266
- Sensor Soil Moisture
- Sensor DHT11
- Sensor DS18B20
- Relay 5V
- Pompa air mini
- LCD 16x2 I2C

## Instalasi

1. Upload file `SmartGarden.ino` ke board NodeMCU.
2. Pastikan library Arduino sudah terinstal:
   - Blynk
   - DallasTemperature
   - OneWire
   - DHT
   - LiquidCrystal_I2C
3. Jalankan dan sambungkan ke jaringan WiFi Anda.

## Dokumentasi

Lihat folder `proposal/` untuk file proposal tugas akhir dalam bentuk `.docx`.

## Lisensi

[MIT License](LICENSE)
