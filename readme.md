
# **Vehicle Telemetry System Documentation**

## **Introduction**

### Project Overview
The Vehicle Telemetry System is an educational project developed to practice Object-Oriented Programming (OOP) principles, leveraging the C++ Standard Template Library (STL) within an automotive simulation environment. This system models a simple vehicle telemetry setup, allowing for the simulation of various sensors monitoring parameters such as speed, temperature, and other critical data. It also incorporates a logging system to record the telemetry data and critical events, and demonstrates OOP design patterns like the Singleton pattern.


## **Installation**

### Prerequisites
- **Compiler**: C++11 or later
- **Build Tools**: Make or CMake (for building the project)
- **Libraries**: Standard C++ libraries, and any required JSON parsing library for handling configuration files [optional]

### Steps for Setup
1. Clone the repository:
   ```bash
   git clone https://github.com/aliemadabdo/vehicle_telemetry.git
   ```
2. Navigate to the project directory:
   ```bash
   cd vehicle_telemetry
   ```
3. Build the project using Make or CMake:
   ```bash
   make
   ```
4. Run the project:
   ```bash
   ./vehicle_telemetry
   ```


### Usage
After building the project, run it to simulate the telemetry system. It will:
- Create sensor instances
- Collect random sensor data
- Log data to a file via the `Logger` class
- Simulate alerts when sensor values exceed thresholds


### **System Design**:

**High-Level System Design**:  
The system comprises various sensor classes, a logging mechanism, and a central `Car` class responsible for processing sensor data. The system is designed to be flexible, allowing easy addition of new sensors and features.

**System Architecture**:  
- **Sensors**: Different sensors like speed, temperature, and battery level monitor the vehicle's status.
- **Car**: The central controller that manages sensors and checks for alerts.
- **Logger**: A singleton class responsible for logging system information and alerts.

**UML Diagrams**:  
- Class relationships between `Car`, `Sensor`, and its derived classes are structured hierarchically.
- `Logger` interacts with both `Car` and `Sensor`, providing system logging.

### **Installation**:

**Prerequisites**:  
- C++17 or later  
- CMake  
- A C++ compiler (e.g., g++, MSVC)  

**Steps for Setup**:  
1. Clone the repository.  
2. Run CMake to configure the project for your platform.  
3. Build the project using your chosen build system.  

**Dependencies**:  
- The C++ Standard Library  
- CMake for build automation  

**Usage**:  
After installation, execute the program, which will monitor simulated sensor data and log alerts when thresholds are exceeded.

### **Main Features**:

- **Modular Design**: Each sensor is its own module, inheriting from an abstract `Sensor` class.
- **Logging System**: The `Logger` class, implemented as a singleton, logs important data such as alerts and sensor readings.
- **OOP Compliant**: Demonstrates a clean object-oriented structure, utilizing inheritance and polymorphism.
- **Monitoring System**: Monitors various vehicle conditions using sensors and triggers appropriate responses.
- **CMake**: Used for build automation and cross-platform compatibility.
  
### **Covered Topics**:

**Object-Oriented Programming (OOP)**:  
- **Constructors and Destructors**: Ensuring proper initialization and cleanup of resources.  
- **Encapsulation**: Encapsulated class structure with clear boundaries between different components.  
- **Inheritance and Hierarchy**: A well-defined class hierarchy where multiple sensor types inherit from a common `Sensor` base class.  
- **Abstraction**: Utilizing setter/getter methods and initializer lists.  
- **Polymorphism**: The system leverages polymorphism with pure virtual functions like `printValue()` in the `Sensor` class.  
- **Friend Functions**: An example is `applyBrakes(Sensor*)`, used with the `speedSensor` class.

**STL Usage**:  
- **Vectors**: To manage and iterate over different types of sensors derived from the abstract `Sensor` class.  
- **Smart Pointers**: Specifically, `std::unique_ptr` is used to ensure proper memory management of sensor objects.

**General C++ Features**:  
- **Working with Files**: Leveraging the `Logger` class to log information into files.  
- **References and `this` Keyword**: Used to manage and access object data efficiently.

**Design Patterns**:  
- **Singleton**: The `Logger` class is a singleton, ensuring that only one instance is responsible for logging throughout the application.

### **Challenges**:
  
One of the challenges was passing multiple sensor-related arguments through different parts of the system. This was solved using **vectorization and abstraction** to pass a collection of sensors as a single object, enabling efficient sensor data management.

A key OOP insight was using the `isAlert()` method. Initially, all sensor values were checked in the `diagnostics()` function itself. Later, using the `isAlert()` function helped maintain solid class design by exposing sensor states directly, removing the need to pass data between unrelated classes.

### **Future Enhancements**:

- **Error Handling**: Implement more robust error handling throughout the system.
- **Unit Testing**: Integrate testing using a framework like Google Test.
- **Configuration Files**: Use JSON or XML to manage sensor thresholds and parameters dynamically without recompiling.

### **References**:
- C++ Programming: [TheCherno C++ Playlist](https://www.youtube.com/watch?v=18c3MTX0PK0&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&ab_channel=TheCherno)
- C++ Documentation: https://en.cppreference.com/  
