#include <iostream>
#include <cstring>
#include "Vehicle.h"
#include "Car.h"

Car::Car():
    m_throttle(0)
{
    std::cout << "Car: Default-ctor" << std::endl;
}

Car::Car(const float* lla):
    Vehicle(lla)
{
    std::cout << "Car: Parametized-ctor" << std::endl;
}

Car::Car(const Car &obj):
    Vehicle(obj)
{
    std::cout << "Car: Copy-ctor" << std::endl;
}

Car::~Car(){
    std::cout << "Car: Dtor" << std::endl;
}

void Car::setThrottle(const int throttle){
    m_throttle = throttle;
}

const int Car::getThrottle() const {
return m_throttle;
}

void Car::Move(const float* lla){
    
    std::cout << "Car: DRIVE to destination, with throttle @ 75 " << std::endl;

    this->drive( 75 );
    this->SetLLA( lla );
}

void Car::drive(const int throttle){
    this->setThrottle(throttle);
}

void Car::operator=(const Car &other){
    std::cout << "Car: Assignment" << std::endl;
    this->SetLLA(other.getLLA());
    this->setThrottle(other.getThrottle());
}

void Car::serialize(std::ostream& os) const{
    const float *ptr = this->getLLA();
    std::cout << "Car: Throttle: " << this->getThrottle()
    << " @ [" << *ptr << ", ";
    ptr++;
    os << *ptr << ", ";
    ptr++;
    os << *ptr << ']';
}
