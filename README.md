# 🌿 Smart Garden IoT - Penyiraman Tanaman Otomatis

Proyek ini merupakan sistem penyiraman tanaman otomatis berbasis Internet of Things (IoT) menggunakan NodeMCU (ESP8266), sensor kelembaban tanah, sensor suhu dan kelembaban udara (DHT11 & DS18B20), serta aplikasi Android Blynk.

## 🔧 Fitur
- Mode otomatis dan manual
- Monitoring kelembaban tanah, suhu, dan kelembaban udara
- Tampilan lokal via LCD 16x2
- Pengontrolan pompa air via aplikasi Android (Blynk)
- Respon cepat, hemat air & waktu

## 📦 Komponen
| Komponen            | Jumlah | Deskripsi                                |
|---------------------|--------|------------------------------------------|
| NodeMCU ESP8266     | 1      | Mikrokontroler utama dengan koneksi WiFi |
| Sensor Soil Moisture| 1      | Mengukur kelembaban tanah                |
| Sensor DHT11        | 1      | Suhu dan kelembaban udara                |
| Sensor DS18B20      | 1      | Sensor suhu akurat (opsional)           |
| Relay 5V            | 1      | Mengaktifkan pompa air                   |
| Pompa air mini      | 1      | Untuk menyiram tanaman                   |
| LCD 16x2 I2C        | 1      | Menampilkan data secara lokal            |

## 🛠️ Instalasi
1. Buka file `smart_garden.ino` di Arduino IDE.
2. Install library berikut:
   - Blynk
   - DHT
   - OneWire
   - DallasTemperature
   - LiquidCrystal_I2C
3. Masukkan `BLYNK_AUTH_TOKEN`, SSID WiFi, dan password kamu.
4. Upload ke NodeMCU, dan sambungkan perangkat.

## 📱 Tampilan Aplikasi Blynk
- Virtual Pin:
  - V1: Suhu (DS18B20)
  - V2: Kelembaban tanah
  - V3: Kelembaban udara
  - V4: Toggle Mode Otomatis/Manual
  - V5: Kontrol pompa (mode manual)

## 📃 Dokumentasi
Proposal Tugas Akhir: [`Proposal UP.docx`](proposal/Proposal%20UP.docx)

## 🧪 Hasil Pengujian
- Delay rata-rata 2.75 detik
- Hemat air hingga 46% dibanding penyiraman manual
- Sistem stabil dan bisa dipantau dari jarak jauh

## 📸 Gambar Prototipe
![prototype](images/prototype.jpg)

## 📝 Lisensi
MIT License — silakan gunakan, ubah, dan distribusikan dengan menyebutkan pembuat.

## 👥 Kontributor
- Yusuf Harry Setiawan
- Daffa Hariz
- Muhammad Faisal Syafiq
- Azrial Farabi Fashih
- Panji Purwito Armin
