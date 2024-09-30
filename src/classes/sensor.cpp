#include <cstdlib>  // For rand() and srand()

#include "../headers/sensor.hpp"
#include "../headers/logger.hpp"

/**
 * @brief Constructs a Sensor object with specified bounds and alert thresholds.
 * 
 * @param start The lower bound for sensor values.
 * @param end The upper bound for sensor values.
 * @param upperAlert The threshold percentage for the upper alert.
 * @param lowerAlert The threshold percentage for the lower alert.
 */
Sensor::Sensor(int start, int end, float upperAlert, float lowerAlert) 
: lowerBound(start), upperBound(end), upperAlertThreshold(upperAlert), lowerAlertThreshold(lowerAlert) {
    Logger::getInstance()->info("Lower Bound: ", start);
    Logger::getInstance()->info("Upper Bound: ", end);
    Logger::getInstance()->info("Lower Bound alert at: ", lowerAlert);
    Logger::getInstance()->info("Upper Bound alert at: ", upperAlert);
}

/**
 * @brief Default constructor for the Sensor class.
 */
Sensor::Sensor() {}

/**
 * @brief Returns the current sensor value.
 * 
 * @return The sensor value as an integer.
 */
int Sensor::getValue() const {
    return value;
}

/**
 * @brief Sets a random value within the sensor bounds and logs it.
 */
void Sensor::setRandomValue() {
    value = lowerBound + std::rand() % (upperBound - lowerBound + 1);
    Logger::getInstance()->info("Value: ", value);
}

/**
 * @brief Sets the sensor value to a specific value and logs it.
 * 
 * @param val The value to set the sensor to.
 */
void Sensor::setValue(int val) {
    value = val;
    Logger::getInstance()->info("Speed while applying breaks: ", value);
}

/**
 * @brief Checks if the sensor value exceeds the alert thresholds.
 * 
 * @return True if the sensor value is outside the alert thresholds, false otherwise.
 */
bool Sensor::isAlert() {
    return ((value < lowerAlertThreshold * lowerBound) || (value > upperAlertThreshold * upperBound));
}

/**
 * @brief Destructor for the Sensor class.
 */
Sensor::~Sensor() {}
