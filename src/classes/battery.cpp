#include <iostream>
#include "../headers/battery.hpp"


BatterySensor::BatterySensor(int minTemp, int maxTemp, int maxLevel) : Sensor(0, maxLevel), tempUpperBound(maxTemp), tempLowerBound(minTemp) {}
BatterySensor::BatterySensor(){} // as the drived class constructs the base class so, 
                // we will need a default constructor for the drived and base classes

void BatterySensor::setRandomValue(){
    // inherited attribute
    setValue(getLowerBound() + std::rand() % (getUpperBound() - getLowerBound() + 1)); // battery level
    // attribure owned by this class
    temprature = tempLowerBound + std::rand() % (tempUpperBound - tempLowerBound + 1);
} 

int BatterySensor::getTemp() const{
    return temprature;
}

int BatterySensor::getLevel() const{
    return getValue(); // we just used the value variable as its already allocated.
                    // I don't think that this is the best way to do that, just practicing
}


void BatterySensor::printValue() const  {
    // std::cout << std::endl;
    // std::cout ;
    std::cout << "Battery temp: " << getTemp() << "`C\t" << "level: " << getLevel() << "%\t";
}
