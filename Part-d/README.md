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
        |   Drone1        Drone3|
        |                       |
        |                       |
        |           Drone2      |
        |                       |
        +-----------------------+
```

- **Drone1**, **Drone2**, and **Drone3** start from different points and follow a predefined path.

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

### Code (Python-like Pseudocode)

```python
import time

class Drone:
    def __init__(self, id, start_position, search_area_bounds):
        self.id = id
        self.position = start_position
        self.search_area_bounds = search_area_bounds
        self.lidar_sensor = LidarSensor()
        self.color_sensor = ColorSensor()
        self.communication_module = SwarmCommunication()
        self.target_found = False

    def take_off(self):
        print(f"Drone {self.id} taking off")
        # Code to take off

    def land(self):
        print(f"Drone {self.id} landing")
        # Code to land

    def move_to(self, position):
        print(f"Drone {self.id} moving to {position}")
        self.position = position
        # Code to move to a specified position

    def perform_search(self):
        print(f"Drone {self.id} starting search in area {self.search_area_bounds}")
        while not self.target_found:
            obj = self.lidar_sensor.detect_object()
            if obj and obj.height == 15 and obj.width == 15 and obj.length == 15:
                color = self.color_sensor.detect_color(obj)
                if color == "green":
                    self.communication_module.send_target_info(self.id, obj.position)
                    self.target_found = True
                    break
            self.move_to_next_position()
            time.sleep(1)  # Simulate movement delay

    def move_to_next_position(self):
        # Logic to move to the next position in the search pattern
        next_position = (self.position[0] + 1, self.position[1] + 1)  # Example increment
        self.move_to(next_position)

class LidarSensor:
    def detect_object(self):
        # Code to detect object and return its dimensions
        return Object(15, 15, 15)  # Placeholder for detected object

class ColorSensor:
    def detect_color(self, obj):
        # Code to detect the color of the object
        return "green"  # Placeholder for detected color

class SwarmCommunication:
    def __init__(self):
        self.target_info = None

    def send_target_info(self, drone_id, position):
        print(f"Drone {drone_id} found target at {position}")
        # Code to send target information to other drones
        self.target_info = (drone_id, position)

    def receive_target_info(self):
        # Code to receive target information from other drones
        return self.target_info

class Object:
    def __init__(self, height, width, length):
        self.height = height
        self.width = width
        self.length = length
        self.position = (0, 0)  # Placeholder for object position

# Initialize drones
drones = [
    Drone(id=1, start_position=(0, 0), search_area_bounds=(0, 10)),
    Drone(id=2, start_position=(10, 0), search_area_bounds=(10, 20)),
    Drone(id=3, start_position=(20, 0), search_area_bounds=(20, 30))
]

# Start the search
for drone in drones:
    drone.take_off()

# Main search logic
for drone in drones:
    drone.perform_search()

# Landing all drones once the target is found
for drone in drones:
    if drone.target_found:
        drone.land()
```

### Summary

This UAV fleet operates autonomously to search for and identify specific targets in a grassy field. Each drone utilizes lidar and color sensors to detect and verify the target object and communicates with other drones using swarm technology. The pseudocode provides a structured approach to implementing the necessary functionalities, ensuring efficient and coordinated search operations.
