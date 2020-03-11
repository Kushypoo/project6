#include <iostream>
#include <cstring>
#include "Vehicle.h"

Vehicle::Vehicle(){
    std::cout << "Vehicle: Default-ctor" << std::endl;
}

Vehicle::Vehicle(const float* lla){
    this->SetLLA(lla);
    std::cout << "Vehicle: Parametrized-ctor" << std::endl;
}


Vehicle::Vehicle(const Vehicle& obj){
    this->SetLLA(obj.getLLA());
    std::cout << "Vehicle: Copy-ctor" << std::endl;
}


Vehicle::~Vehicle(){
    std::cout << "Vehicle: Dtor" << std::endl;
}

void Vehicle::SetLLA(const float *lla){
    m_lla[0] = lla[0];
    m_lla[1] = lla[1];
    m_lla[2] = lla[2];
}

const float *Vehicle::getLLA() const {
return this->m_lla;
}


std::ostream & operator<< (std::ostream & os, const Vehicle & vehicle){
    vehicle.serialize(os);
    return os;
}

void Vehicle::operator= (const Vehicle& other){
    this->SetLLA(other.getLLA());
    std::cout << "Vehicle: Assignment" << std::endl;
}

void Vehicle::serialize(std::ostream& os) const{
    const float *ptr = this->getLLA();
    os << "Vehicle @ [" << *ptr << ", ";
    ptr++;
    os << *ptr << ", ";
    ptr++;
    os << *ptr << ']';
}
