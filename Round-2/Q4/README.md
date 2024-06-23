# Smart Irrigation System using Arduino

This project implements a smart irrigation system using an Arduino microcontroller. The system automatically waters plants based on soil moisture levels, with additional features for user customization, feedback mechanisms, and power efficiency.

## Features

- **Automatic Watering**: Monitors soil moisture and activates the water pump when the soil becomes too dry.
- **Customizable Threshold**: Users can set a custom soil moisture threshold using a potentiometer.
- **Feedback System**: Provides feedback through an LED and buzzer to indicate when watering starts and stops.
- **Manual Activation**: A push button allows users to manually activate the system.
- **Power Saving Mode**: Includes a sleep mode feature to conserve power when the system is not in use.

## Components Used

- **Arduino Uno**: Microcontroller board that runs the irrigation system.
- **Soil Moisture Sensor**: Detects soil moisture levels.
- **Potentiometer**: Adjusts the threshold for soil moisture.
- **Servo Motor**: Controls the water flow by opening and closing the valve.
- **LED and Buzzer**: Provide visual and auditory feedback to the user.
- **Push Button**: Allows manual activation of the system and wakes it from sleep mode.

## Setup and Usage

### Hardware Setup

1. **Connections**:
   - Connect the soil moisture sensor to analog pin A0 of the Arduino.
   - Connect the potentiometer to analog pin A1 to adjust the threshold.
   - Connect the servo motor to digital pin 10 to control the water valve.
   - Connect the water pump relay to digital pin 9 for activating the pump.
   - Connect the LED to digital pin 8 for visual feedback.
   - Connect the buzzer to digital pin 7 for auditory feedback.
   - Connect a push button to digital pin 2 to manually activate the system.

2. **Power**:
   - Ensure the Arduino and components are powered appropriately as per their specifications.

### Software Setup

1. **Arduino IDE**:
   - Open the `SmartIrrigationSystem.ino` file in Arduino IDE.

2. **Upload Code**:
   - Verify and upload the code to your Arduino board.

### Operation

- **Threshold Adjustment**:
  - Turn the potentiometer to set the desired soil moisture threshold (range: 200 to 800).

- **Automatic Mode**:
  - The system continuously monitors soil moisture.
  - When the moisture drops below the set threshold, the pump activates to water the plants.
  - LED blinks and buzzer emits a short beep to indicate watering.

- **Manual Mode**:
  - Press the button connected to pin 2 to manually activate the system if it's in sleep mode.
  - This wakes up the system and resumes monitoring soil moisture.

### Notes

- **Calibration**:
  - Calibrate the soil moisture sensor according to your specific soil and plant requirements.
  - Adjust the threshold range (`map()` function in the code) based on the sensor's readings and plant needs.

- **Power Efficiency**:
  - Use sleep mode to conserve power when the system is not actively monitoring soil moisture.
  - Press the button to wake the system from sleep mode.

## Contributing

Contributions to improve or extend this project are welcome! Please fork the repository, make your changes, and submit a pull request.
