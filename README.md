# Smart Soil Irrigation System 🌱💧

## Overview
This repository contains the embedded C++ control logic and hardware architecture for a **Smart Soil Irrigation System**. Built as a proof-of-concept for precision agriculture, this closed-loop cyber-physical prototype autonomously monitors soil hydration levels and triggers mechanical actuation to optimize water preservation.

## Technical Architecture
The system operates on a sensor-to-actuation pipeline, bridging physical environmental data with automated hardware responses to eliminate water waste in agricultural settings.

* **Microcontroller:** Arduino Uno R3
* **Input:** Analog Soil Moisture Sensor
* **Control Logic:** Edge-threshold algorithm written in C++
* **Actuation:** 5V Single-Channel Relay Module driving a DC Water Pump
* **Power Distribution:** Independent 5V/12V supplies for logic and mechanical load

## Operational Workflow
1. **Data Acquisition:** The soil moisture sensor continuously reads the dielectric permittivity of the soil, sending analog telemetry to the Arduino.
2. **Edge Processing:** The microcontroller processes the raw data against calibrated dry/wet thresholds.
3. **Actuation:** If the soil moisture drops below the critical threshold, the Arduino triggers the optoisolated relay, closing the high-current circuit to activate the DC water pump.
4. **Closed-Loop Feedback:** Once the moisture sensor detects optimal hydration, the logic loop breaks the relay circuit, instantly halting water flow.

## Research Application
This prototype demonstrates foundational competencies in **IoT sensor integration**, **hardware-software co-design**, and **sustainable automation**—key technical requirements for advancing smart agricultural frameworks and environmental monitoring systems.
