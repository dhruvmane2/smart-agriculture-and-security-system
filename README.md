# Smart Agriculture Irrigation and Security System

## 📌 Project Overview

The Smart Agriculture Irrigation and Security System is an IoT-based project using ESP32 to automate irrigation, monitor environmental conditions, and provide security for agricultural fields.

## 🎯 Objectives

* Automate irrigation based on soil moisture.
* Reduce water wastage.
* Monitor temperature and humidity.
* Detect animals or intruders.
* Provide real-time monitoring through Blynk IoT.

## 🔧 Components Used

* ESP32 Microcontroller
* Soil Moisture Sensor
* DHT11 Temperature & Humidity Sensor
* Ultrasonic Sensor
* L298N Motor Driver
* DC Water Pump
* 16×2 LCD Display
* Buzzer
* Power Supply

## 💻 Software & Technologies

* Arduino IDE
* Embedded C
* Blynk IoT
* Wi-Fi
* IoT Technology

## ⚙️ Working

1. The **Soil Moisture Sensor** measures the moisture level of the soil.
2. The **ESP32** processes the sensor data.
3. If the soil is dry, the **L298N Motor Driver** turns ON the **DC Water Pump**.
4. When sufficient moisture is reached, the pump turns OFF automatically.
5. The **DHT11 Sensor** monitors temperature and humidity.
6. The **Ultrasonic Sensor** detects animals or intruders.
7. The **Buzzer** provides an alert when an object is detected.
8. The **16×2 LCD** displays sensor readings and system status.
9. Data can also be monitored remotely using the **Blynk IoT Application**.

## ✨ Features

* Automatic irrigation
* Soil moisture monitoring
* Temperature and humidity monitoring
* Animal/intruder detection
* Buzzer security alert
* LCD status display
* Remote IoT monitoring
* Water conservation

## 📂 Project Structure

```text
Smart-Agriculture-Irrigation-and-Security-System/
│
├── Code/
│   └── smart_agriculture.ino
│
├── Circuit/
│   └── circuit_diagram.png
│
├── Flowchart/
│   └── flowchart.png
│
├── Images/
│   ├── hardware_setup.jpg
│   ├── lcd_output.jpg
│   └── blynk_app.jpg
│
├── Simulation/
│   └── simulation.png
│
└── README.md
```

## 🌱 Applications

* Smart agriculture farms
* Greenhouse irrigation
* Garden watering systems
* Water conservation
* Farm security monitoring
* Automated agricultural systems

## 📊 Results

The system successfully performs automatic irrigation, monitors environmental conditions, detects nearby objects, provides security alerts, and displays real-time information. It helps reduce water wastage and manual effort while improving farm monitoring.

## 🚀 Future Scope

* Cloud-based data storage
* Weather prediction
* AI-based crop monitoring
* Solar-powered operation
* Advanced crop disease detection

## 👨‍💻 Project

**Smart Agriculture Irrigation and Security System**
Developed using **ESP32 and IoT technology**.
