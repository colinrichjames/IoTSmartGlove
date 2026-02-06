# IoT Smart Glove

A wearable gesture recognition glove prototype built with an Arduino, MPU6050 accelerometer/gyroscope, and HM10 Bluetooth module. The glove captures hand motion data, detects gestures, and communicates results wirelessly over BLE.

**Course:** CS 7470: Mobile & Ubiquitous Computing — Georgia Tech OMSCS

**Team 12 — What The Hack:**
- Jason Bunyea
- Pete Fuentes
- Colin James
- Jasmine Manansala
- John West

## Hardware

| Component | Purpose |
|-----------|---------|
| Arduino | Microcontroller |
| MPU6050 | 6-axis accelerometer & gyroscope (I2C) |
| HM10 | Bluetooth Low Energy module (SoftwareSerial on pins 2/3) |
| LED | Visual feedback indicator |
| Breadboard | Prototyping circuit assembly |
| 1K & 2K Ohm Resistors | Voltage divider for BLE module |

### Circuit Diagram

![Wearable Design](Wearable%20Design.png)

The MPU6050 connects to the Arduino via I2C (SDA/SCL), while the HM10 BLE module communicates over SoftwareSerial (RX pin 2, TX pin 3) through a resistor voltage divider.

## Project Structure

```
.
├── wearable_accel_gyro/      # Data collection firmware
│   ├── wearable_accel_gyro.ino
│   ├── MPU6050.cpp
│   └── MPU6050.h
├── what_the_hack/            # Gesture recognition firmware
│   ├── what_the_hack.ino
│   ├── ModelAssistant.cpp/h  # Orchestrates gesture pipeline
│   ├── SensorHandler.cpp/h   # MPU6050 sensor abstraction
│   ├── CommunicationHandler.cpp/h  # BLE communication (HM10)
│   ├── LedHandler.cpp/h      # LED feedback (solid/blink)
│   ├── ThreeDVector.cpp/h    # 3D acceleration data wrapper
│   └── MPU6050.cpp/h
├── WearableData/             # Collected gesture datasets
│   ├── Wearable Gesture Data - Flick Down 1-3.csv
│   ├── Wearable Gesture Data - Flick Up 1-3.csv
│   └── Wearable Gesture Data.xlsx
└── Wearable Design.png       # Circuit diagram
```

## How It Works

1. **Sensor Reading** — The `SensorHandler` reads raw and normalized 3-axis accelerometer data from the MPU6050 at configurable intervals (100ms default).
2. **Gesture Detection** — The `ModelAssistant` collects sensor readings and runs segmentation to identify potential gestures (e.g., flick up, flick down).
3. **LED Feedback** — The `LedHandler` provides visual feedback: a solid light for a recognized gesture, or a blink pattern for an unrecognized one.
4. **BLE Communication** — The `CommunicationHandler` transmits results as JSON messages over Bluetooth: `{"ID": "<type>", "DATA": "<gesture>"}`.

## Sketches

### `wearable_accel_gyro`

A data collection sketch used to record accelerometer readings. It streams raw and normalized X/Y/Z acceleration values over BLE in CSV format at ~100Hz for offline analysis.

### `what_the_hack`

The main gesture recognition firmware with a modular, object-oriented architecture. Designed to run the full pipeline from sensor reading through gesture classification and wireless output.

## Getting Started

### Prerequisites

- Arduino IDE
- Arduino board (Uno or compatible)
- MPU6050 sensor module
- HM10 BLE module

### Upload

1. Open either `wearable_accel_gyro/wearable_accel_gyro.ino` or `what_the_hack/what_the_hack.ino` in the Arduino IDE.
2. Select your board and port under **Tools**.
3. Click **Upload**.

### Data Collection

Connect to the HM10 BLE module from a mobile device or serial terminal to receive streaming accelerometer data. The `WearableData/` directory contains sample gesture recordings for flick up and flick down motions.
