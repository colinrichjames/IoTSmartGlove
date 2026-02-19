# IoT Smart Glove: Gesture-Based Ubiquitous Computing

**A wearable prototype redefining human-computer interaction through real-time motion classification.**

## 🎯 Project Vision

The **IoT Smart Glove** was engineered to replace traditional remote controls with a seamless, gesture-based input system. By integrating low-latency hardware with a **Random Forest classifier**, the system recognizes dynamic hand gestures in real-time to facilitate intuitive control over smart home ecosystems.

## 🛠️ Technical Architecture

### Hardware Configuration

The prototype utilizes a modular hardware stack designed for low-power, wearable efficiency:

* **Microcontroller:** Arduino-based logic for real-time processing.
* **Inertial Measurement:** MPU6050 6-axis accelerometer & gyroscope (I2C) for high-fidelity motion capture.
* **Connectivity:** HM10 Bluetooth Low Energy (BLE) module for wireless JSON data transmission.
* **Feedback System:** LED-based visual indicators providing immediate HCI state confirmation.

### Software & Gesture Pipeline

The firmware is built on a modular, object-oriented architecture to ensure low latency and scalability:

1. **Sensor Abstraction (`SensorHandler`):** Reads normalized 3-axis data at 100Hz intervals.
2. **Signal Segmentation:** The `ModelAssistant` orchestrates the data pipeline to identify potential movement windows (e.g., Flick Up, Flick Down).
3. **Classification & Output:** Recognized gestures are serialized into JSON payloads (e.g., `{"ID": "type", "DATA": "flick_up"}`) and transmitted over BLE.

## 📈 Data & Machine Learning

A custom dataset was curated to train the gesture recognition model, including multiple recording sessions for:

* **Flick Down:** High-velocity downward motion capture.
* **Flick Up:** Rapid upward wrist extension data.
* **Dataset Management:** The `WearableData/` directory contains CSV-formatted accelerometer streams used for offline analysis and model validation.

## 🚀 Getting Started

### Prerequisites

* Arduino IDE (Uno or compatible board).
* MPU6050 and HM10 BLE sensor modules.
* Prototyping components: Breadboard, 1K/2K Ohm resistors for voltage division.

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

### Installation

1. **Clone the Repo:** `git clone https://github.com/cjames/iot-smart-glove.git`.
2. **Upload Firmware:** Open `what_the_hack.ino` in the Arduino IDE to deploy the full gesture recognition pipeline.
3. **Connect:** Use a mobile BLE terminal to pair with the HM10 and receive real-time gesture data.

---

### Project Credits

Developed by **Team 12 — What The Hack** for **CS 7470: Mobile & Ubiquitous Computing** at **Georgia Tech**.

* **Core Contributors:** Colin James, Jason Bunyea, Pete Fuentes, Jasmine Manansala, John West.




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

### Upload

1. Open either `wearable_accel_gyro/wearable_accel_gyro.ino` or `what_the_hack/what_the_hack.ino` in the Arduino IDE.
2. Select your board and port under **Tools**.
3. Click **Upload**.

### Data Collection

Connect to the HM10 BLE module from a mobile device or serial terminal to receive streaming accelerometer data. The `WearableData/` directory contains sample gesture recordings for flick up and flick down motions.
