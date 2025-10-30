# 🌿 Smart Plant Water Reminder – Project Files

This repository contains all the technical files for my Smart Plant Water Reminder: a Wi-Fi-connected device that tells you when your plant needs watering via LED alert and Telegram notification.

👉 Project breakdown and photos available on my portfolio:  
>  [PlantBot: Smart Plant Water Reminder](https://editor.wix.com/html/editor/web/renderer/edit/7dd5ee8c-e91b-44d8-93e9-605d003c71eb?metaSiteId=678279c4-7c1c-49d0-87b9-8d6adbd433d8)


## 🛠️ Tech Stack

- ESP8266 NodeMCU
- Capacitive soil moisture sensor
- Wi-Fi connectivity + Telegram Bot API
- Arduino IDE
- 3D design: Shapr3D / AutoCAD

## 🧠 Usage Notes

1. Open the .ino file in the Arduino IDE  
2. Create your own secrets.h file in the same folder with:
   ```cpp
   #define WIFI_SSID "your_wifi"
   #define WIFI_PASSWORD "your_password"
   #define BOT_TOKEN "your_bot_token"
   #define CHAT_ID "your_telegram_chat_id"
