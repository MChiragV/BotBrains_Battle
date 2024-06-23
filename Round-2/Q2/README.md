# Autonomous Parcel Delivery Robot

## Overview

This project aims to develop an autonomous parcel delivery robot capable of navigating to a specified destination while avoiding obstacles and delivering parcels. The robot utilizes various sensors and control algorithms to achieve its tasks.

## File Structure

- **main.py**: Main control script that orchestrates the integration of different modules to achieve autonomous navigation and parcel delivery.
- **pid_controller.py**: Implements a PID controller for maintaining balance and controlling the robot's orientation.
- **navigation.py**: Provides path planning algorithms (such as A*) to generate a route from the robot's current position to a specified destination.
- **obstacle_avoidance.py**: Manages obstacle detection using ultrasonic sensors and adjusts the robot's path to avoid collisions.
- **parcel_delivery.py**: Controls the mechanism for holding and releasing parcels at the destination.
- **imu_sensor.py**: Interfaces with the IMU sensor to read orientation data (roll, pitch, yaw) for balance control.
- **camera.py**: Manages the camera module to capture visual data for navigation and obstacle detection.
- **ultrasonic_sensor.py**: Handles interactions with ultrasonic sensors to measure distances to obstacles.
- **utils.py**: Contains utility functions used across different modules, such as mathematical calculations and distance measurements.

## Functionality

### `main.py`

- Initializes all necessary modules and sensors.
- Utilizes `AStarPathPlanner` for pathfinding and navigation.
- Implements PID control from `PIDController` to maintain robot balance.
- Integrates obstacle avoidance strategies from `ObstacleAvoidanceSystem`.
- Manages parcel delivery process using `ParcelHandler`.

### `pid_controller.py`

- Implements a PID controller (`PIDController`) with methods to calculate control signals based on orientation data (`roll`).
- Parameters such as `Kp`, `Ki`, and `Kd` can be adjusted for tuning the PID controller.

### `navigation.py`

- Provides an `AStarPathPlanner` class that uses A* algorithm for path planning.
- Generates a path from the robot's current position to a specified destination.

### `obstacle_avoidance.py`

- `ObstacleAvoidanceSystem` class manages obstacle detection using ultrasonic sensors (`UltrasonicSensor`).
- Adjusts robot's path dynamically to avoid obstacles detected in its path.

### `parcel_delivery.py`

- `ParcelHandler` class controls the mechanism for holding and releasing parcels.
- Releases the parcel when the robot reaches its destination.

### `imu_sensor.py`

- `IMUSensor` class interfaces with the IMU sensor to read orientation data (`roll`, `pitch`, `yaw`).
- Provides methods for initializing the sensor and reading orientation data.

### `camera.py`

- `Camera` class manages the camera module to capture images for visual navigation and obstacle detection.
- Initializes the camera and captures images for processing.

### `ultrasonic_sensor.py`

- `UltrasonicSensor` class handles interactions with ultrasonic sensors to measure distances to obstacles.
- Provides methods for initializing the sensor and reading distance measurements.

### `utils.py`

- Contains utility functions used across different modules, such as Euclidean distance calculation (`distance`) and angle difference calculation (`angle_difference`).

## Usage

1. Clone the repository.
2. Install necessary dependencies (if any) mentioned in each module's documentation.
3. Run `main.py` to start the autonomous parcel delivery robot.

## Contributors

- [Chirag M V](https://github.com/MChiragV)
