#include <iostream>
#include "../../headers/speed.hpp"
#include "../../headers/logger.hpp"

/*Sensor Range*/
constexpr int backSpeed = -50; // 50 km/h backward
constexpr int forwardSpeed = 100; // 100 km/h forward
constexpr float forwardSpeedAlert = 0.8f; // 80km/h
constexpr float backSpeedAlert = 0.9f; // -45 km/h

SpeedSensor::SpeedSensor() : Sensor(backSpeed, forwardSpeed, forwardSpeedAlert, backSpeedAlert) {
    Logger::getInstance()->info("That's all about speed sensor\n",0000);
}
                 // as the drived class constructs the base class so, 
                // we will need a default constructor for the drived and base classes

void SpeedSensor::printValue() const  {
    std::cout << " Speed: " << getValue() << "km/h\t\t";
}

SpeedSensor::~SpeedSensor(){}

/**
 * @brief Applies brakes by continuously adjusting the sensor's value until the alert condition is resolved.
 * 
 * @param ss A pointer to the Sensor object, which represents the speed sensor.
 * 
 * The function reduces the sensor value if it exceeds the alert threshold,
 * simulating the application of brakes. Logs the adjusted value during each iteration.
 */
void applyBrakes(Sensor* speedsens){
    while(speedsens->isAlert()){ 
        int val = speedsens->getValue();
        if (val > 0){
            speedsens->setValue(val-1); 
            Logger::getInstance()->alert("BREAKS!! Speed decreased to (km/h): ", val-1);
        }
        else{
            speedsens->setValue(val+1); 
            Logger::getInstance()->alert("BREAKS!! Speed decreased to (km/h): ", val+1); // -ve
        }
    }     
}