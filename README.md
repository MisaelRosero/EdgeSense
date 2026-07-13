# EdgeSense

EdgeSense is a modular embedded telemetry platform built on the ESP32-S3 using ESP-IDF and FreeRTOS.

The system is being designed to acquire motion data from an inertial measurement unit, process telemetry locally, detect meaningful motion events, buffer data during network outages, and securely transmit results to cloud infrastructure.

The project emphasizes real-time firmware architecture, hardware/software integration, fault recovery, measurable system performance, and professional engineering documentation.

## Project Status

**Current phase:** Firmware foundation and hardware bring-up

Completed:

- ESP-IDF v6.0.2 development environment configured on macOS
- ESP32-S3 firmware project initialized
- ESP32-S3 target configured
- Firmware builds successfully
- Initial FreeRTOS health-monitoring task implemented
- Health-monitoring functionality separated into a dedicated module
- USB communication investigation completed
- Known data-capable USB cable ordered for hardware validation

In progress:

- Flashing and monitoring firmware on the ESP32-S3
- Verifying board flash and PSRAM configuration
- Preparing the ICM-42670 IMU interface

## Planned System Architecture

```text
ICM-42670 IMU
        |
        v
Sensor Acquisition Task
        |
        v
Motion Processing and Event Detection
        |
        v
Telemetry Buffer
       / \
      /   \
     v     v
microSD   MQTT Client
Logging       |
              v
        AWS IoT Core
              |
              v
        Cloud Backend
              |
              v
        Monitoring Dashboard