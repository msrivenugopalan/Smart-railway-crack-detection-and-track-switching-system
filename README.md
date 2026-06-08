# Smart Railway Crack Detection and Track Switching System
---

## Project Overview

This project is a simulation-based embedded system designed to detect cracks or anomalies in railway tracks using an ultrasonic sensor.  
When a fault is detected, the system triggers alerts and follows a structured decision-making process including authority approval and fail-safe operation.

The project is implemented using **ESP32** and simulated on the **Wokwi platform**.

---

## Objective

The main objective is to design an embedded safety system that can:

- Detect railway track cracks or abnormalities
- Trigger real-time alerts
- Evaluate alternate track conditions
- Request authority approval before action
- Ensure fail-safe operation during emergencies

---

## Working Principle

- Ultrasonic sensor continuously monitors track condition  
- If distance is below threshold → crack detected  
- System activates alert mechanisms (LED, buzzer, LCD)  
- System enters self-healing mode  
- Checks alternate track availability  
- Waits for authority approval (button input with timeout)  
- If approved → servo switches track  
- If not approved → system enters fail-safe stop mode  

---

## Features

- Real-time crack detection simulation  
- LCD display for system status  
- LED and buzzer alert system  
- Servo-based track switching  
- Authority approval logic with timeout  
- Fail-safe emergency stop system  
- Fully simulated using Wokwi  

---

## Components Used

- ESP32 Development Board  
- Ultrasonic Sensor (HC-SR04)  
- I2C LCD Display (16x2)  
- Servo Motor  
- Buzzer  
- Red LED  
- Green LED  
- Push Button  

---

## Software Used

- Arduino IDE  
- ESP32 Arduino Core  
- Wokwi Online Simulator  

---

## Simulation

This project is fully tested using Wokwi virtual simulation environment.

**Wokwi Simulation Link:**  
(https://wokwi.com/projects/458388798923858945)


---

## System Workflow

- Continuous track monitoring using ultrasonic sensor  
- Crack detection based on threshold value  
- Alert system activation (LED + buzzer + LCD)  
- Alternate track verification  
- Authority approval window (10 seconds)  
- Servo-based track switching  
- Fail-safe emergency stop if no approval  

---

## Future Enhancements

- GSM/IoT-based alert notifications  
- Cloud dashboard integration  
- AI-based predictive maintenance  
- Real-world hardware deployment  
- Multi-sensor fusion system  

---

## Key Highlights

- Embedded real-time decision-making system  
- Railway safety simulation model  
- Multi-stage fail-safe architecture  
- Clean modular embedded code design  
- Strong IoT + automation concept demonstration  

---

## Author

**Srivenugopalan M**

Embedded Systems & IoT Enthusiast  


---
