# 🌿 Smart Plant Water Reminder – Project Files

This repository contains all the technical files for my Smart Plant Water Reminder: a Wi-Fi-connected device that tells you when your plant needs watering via LED alert and Telegram notification.

> 🚀 Full tutorial, project story, and photos available on my portfolio:  
> 👉 [Smart Plant Water Reminder – EcoHacks #1] (link)


## 📁 What’s Inside

- code/: Arduino code and example secrets.h file
- media/: Circuit wiring diagram and project photos
- 3d-print-files/: STL file for the 3D-printed mushroom-style enclosure

---

## 🛠️ Tech Stack

- ESP8266 NodeMCU
- Capacitive soil moisture sensor
- Wi-Fi connectivity + Telegram Bot API
- Arduino IDE
- 3D design: Shapr3D / AutoCAD

---

## 🧠 Usage Notes

1. Open the .ino file in the Arduino IDE  
2. Create your own secrets.h file in the same folder with:
   ```cpp
   #define WIFI_SSID "your_wifi"
   #define WIFI_PASSWORD "your_password"
   #define BOT_TOKEN "your_bot_token"
   #define CHAT_ID "your_telegram_chat_id"
