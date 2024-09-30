#include <vector>
#include <memory>

#include "../headers/car.hpp"
#include "../headers/logger.hpp"

/**
 * @brief Constructs a Car object and initializes its sensors.
 * 
 * @param sens A reference to a vector of unique pointers to Sensor objects.
 */
Car::Car(std::vector<std::unique_ptr<Sensor>>& sens) {
    this->sensors = &sens;
}

/**
 * @brief Generates random values for all sensors.
 * 
 * This function iterates through all sensors and invokes the 
 * setRandomValue method for each sensor. It uses references 
 * to ensure unique ownership of sensor pointers.
 */
void Car::generateRandomVal(){
    // Due to uniqueness, we can't assign the variable to more than one pointer
    // so we have to use references.
    for(const auto &s : *sensors){ 
        s->setRandomValue(); // Polymorphism 
    }
}

/**
 * @brief Displays the current values of all sensors.
 * 
 * This function iterates through all sensors and calls the 
 * printValue method for each sensor to output its current state.
 * Using `const` signals that the elements being iterated over 
 * should not be modified.
 */
void Car::showData(){
    // Using `const` can make your code clearer in terms of intent.
    // It signals to other developers (or to yourself in the future) that
    // the elements being iterated over should not be modified.
    for(const auto &s : *sensors){
        s->printValue();
    }
    std::cout << std::endl;
}

/**
 * @brief Performs diagnostics on the car's sensors.
 * 
 * This function checks the alert status of critical sensors, 
 * such as engine temperature, battery temperature, and battery level. 
 * If any sensor indicates a critical condition, an alert is logged 
 * using the Logger instance.
 */
void Car::diagnostics(){
    if ((*sensors)[index::tempSensor]->isAlert()) 
        Logger::getInstance()->alert("Engine temperature is critical! Initiating cooling...\n", 0000);
        // TODO: add relation between speed and engine temperature
    if ((*sensors)[index::batteryTemp]->isAlert()) 
        Logger::getInstance()->alert("Battery temperature is critical! Initiating cooling...\n", 0000);
    if ((*sensors)[index::batteryLvl]->isAlert()) 
        Logger::getInstance()->alert("Low battery level! Please recharge...\n", 0000);
}

/**
 * @brief Implements adaptive cruise control functionality.
 * 
 * This function checks the alert status of the speed sensor and radar sensor. 
 * If either sensor indicates an alert, it applies brakes to maintain safety. 
 * A dynamic cast is used to ensure that the correct sensor type is being handled.
 */
void Car::adaptiveCruiseControl() {
    // Correct dynamic cast
    SpeedSensor* speedSensor = dynamic_cast<SpeedSensor*>((*sensors)[index::speedSensor].get());

    if ((*sensors)[index::speedSensor]->isAlert()){
        if (speedSensor)
            applyBrakes(speedSensor);
        else {
            Logger::getInstance()->debug("Invalid dynamic casting!\n", 0000);
            return;
        }
    }

    if ((*sensors)[index::radarSensor]->isAlert()) {
        if (speedSensor)
            applyBrakes(speedSensor);
    }  
    // TODO: add relation between speed and distance

   // free(speedSensor); // Note: Using 'free' on a unique_ptr is not correct; consider removing this line.
}

/**
 * @brief Destructs the Car object.
 */
Car::~Car(){}
