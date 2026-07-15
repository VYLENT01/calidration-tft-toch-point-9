# 🎯 ESP32 TFT Touch Calibration (9-Point)

A calibration utility for **ESP32** touchscreen displays using a **9-point calibration algorithm**.

This project helps generate accurate touch calibration parameters for TFT displays equipped with touch controllers such as the **XPT2046**, allowing touch coordinates to correctly match screen pixels.

---

## ✨ Features

- 🎯 9-point touchscreen calibration
- 📐 Accurate coordinate mapping
- 🖥 Compatible with ILI9341 TFT displays
- 📱 Optimized for ESP32 boards
- ⚡ Fast calibration process
- 🧮 Generates calibration coefficients
- 🔄 Improves touch accuracy across the entire screen

---

## 🛠 Supported Hardware

- ESP32 / ESP32-S3
- ILI9341 SPI TFT Display
- XPT2046 Touch Controller

---

## 📂 Project Structure

```
Calibration/
│
├── src/
│   ├── main.cpp
│   ├── TouchCalibration.cpp
│   └── ...
│
├── include/
├── lib/
└── platformio.ini
```

---

## 🚀 Getting Started

### Clone the repository

```bash
git clone https://github.com/VYLENT01/calidration-tft-toch-point-9.git
```

### Open with PlatformIO

Open the project using **Visual Studio Code** with the **PlatformIO Extension** installed.

### Upload

Compile and upload the firmware to your ESP32 board.

---

## 📋 Calibration Procedure

1. Flash the firmware.
2. The display will show calibration targets.
3. Touch each point as accurately as possible.
4. The calibration parameters will be calculated.
5. Copy the generated coefficients into your application.

---

## 📐 Calibration Output

The calibration process generates transformation coefficients that convert raw touch values into screen coordinates.

Example:

```cpp
constexpr float bx = -0.08883249;
constexpr float cx = 347.88070679;

constexpr float by = -0.06439150;
constexpr float cy = 246.46490478;
```

These values can then be used in your touch driver to achieve accurate touch positioning.

---

## 💡 Applications

- GUI applications
- Embedded dashboards
- Touchscreen interfaces
- IoT devices
- Industrial HMIs
- ESP32-based control panels

---

## 🧰 Technologies

- C++
- PlatformIO
- Arduino Framework
- ESP32
- SPI
- ILI9341
- XPT2046

---

## 📷 Demo

> Screenshots and demonstration videos will be added soon.

---

## 🚀 Future Improvements

- 5-point and 25-point calibration modes
- Automatic calibration validation
- Save coefficients to NVS/Flash
- Touch accuracy visualization
- Multi-display support
- LVGL integration

---

## 👨‍💻 Author

**Sadegh Kazemi**

Embedded Systems Engineer

GitHub:
https://github.com/VYLENT01

---

## ⭐ Support

If this project helped you, consider giving it a ⭐ on GitHub!
