### Theory

The goal of this project is to develop a fleet of autonomous UAVs (drones) capable of detecting and reporting specific targets in an outdoor grassy area. The drones are equipped with various sensors to assist in target detection and communication systems for coordination.

#### Key Components

1. **Autonomous Flight**:
   - **Takeoff and Landing**: Drones are capable of taking off and landing autonomously, using onboard GPS and inertial measurement units (IMUs) for navigation.
   - **Navigation**: Predefined waypoints are used for navigation, ensuring that each drone covers its designated search area efficiently without human intervention.

2. **Lidar Sensor**:
   - **Object Detection**: Lidar (Light Detection and Ranging) sensors emit laser pulses to measure distances to nearby objects, creating a 3D map of the environment.
   - **Dimension Measurement**: Lidar is used to detect objects and measure their height, width, and length. In this scenario, the drone is programmed to stop and measure the dimensions if an object with a height of 15cm is detected.

3. **Color Sensor**:
   - **Target Identification**: Once an object with the specified dimensions is detected, the color sensor identifies if the object is green. Only objects with the target color are considered for further action.

4. **Swarm Technology**:
   - **Communication**: Drones communicate with each other using a mesh network. When one drone detects the target, it immediately informs the other drones, which then cease their search operations.

### Sketch and Calculation

#### Assumptions:
- The search area is divided into smaller segments, each covered by one drone to avoid overlap and ensure complete coverage.
- Objects are scattered randomly, and their dimensions must be measured to identify the target.

#### Diagram:

```plaintext
        +-----------------------+
        |       Grassy Field    |
        |                       |
        |   D1               D3 |
        |                       |
        |                       |
        |                       |
        |           D2          |
        +-----------------------+
```

- **Drone1(D1)**, **Drone2(D2)**, and **Drone3(D3)** start from different points and follow a predefined path.

#### Calculation:
1. **Search Area Division**: Assuming the total area is divided into three equal parts.
2. **Object Detection Range**: The detection range of the lidar and the communication range of the swarm technology must be sufficient to cover the entire search area without gaps.

### Workflow of the Logic/Algorithm

1. **Initialization**:
   - Each drone initializes its sensors and communication modules.
   - The drones take off and move to their starting positions.

2. **Search Pattern**:
   - Drones follow a predefined search pattern to cover their designated areas systematically.
   - This pattern can be a grid, spiral, or zigzag to ensure thorough coverage.

3. **Object Detection and Measurement**:
   - The lidar sensor continuously scans for objects.
   - Upon detecting an object with a height of 15cm, the drone stops and measures the other dimensions (width and length).
   - If the object matches the target dimensions (15cm x 15cm x 15cm), the color sensor checks the object's color.

4. **Target Identification**:
   - If the object is green, the drone sends the target's coordinates to the other drones using the swarm communication module.
   - The other drones stop their search upon receiving the target information.

5. **Termination**:
   - The drone that finds the target lands at a predefined location.
   - Other drones land once they receive the target information.

### Refer to the Python code dr.py

### Summary

This UAV fleet operates autonomously to search for and identify specific targets in a grassy field. Each drone utilizes lidar and color sensors to detect and verify the target object and communicates with other drones using swarm technology. The pseudocode provides a structured approach to implementing the necessary functionalities, ensuring efficient and coordinated search operations.
