# SmartSphere: Home Control at Your Fingertips

An IoT-based home automation system enabling remote control and real-time monitoring of home appliances and security devices via a custom Android application.

## Hardware Components

- ESP12E Wi-Fi module (ESP8266)
- Arduino Pro MINI and Arduino NANO
- nRF24L01 2.4GHz RF transceiver modules
- DHT22 temperature sensor
- MQ6 LPG gas sensor
- PIR motion sensors
- Relay modules

## System Architecture

The hardware is divided into four modules:
- **Gas Sensing Module** — MQ6 LPG sensor with instant alert on detection
- **Motion Sensing Module** — PIR sensor with automatic alarm triggering
- **Temperature Monitoring Module** — DHT22 sensor with real-time updates
- **Main Control Module** — relay-based appliance switching via ESP12E

## Software

- Android application built using **MIT App Inventor**
- **Google Firebase** as real-time database backend
- ESP12E communicates bidirectionally with Firebase — receiving commands and sending sensor data simultaneously

## Key Features

- Remote ON/OFF and brightness/speed control of appliances
- Real-time temperature monitoring
- LPG gas leakage detection with instant app notifications
- PIR-based intruder detection with automatic alarm triggering
- Automated safety responses — valve shutoff and window control
- Appliance usage logging for power management
