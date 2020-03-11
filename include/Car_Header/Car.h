#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <cstring>
#include "Vehicle.h"

class Car : public Vehicle 
{
private:
    virtual void serialize(std::ostream& os) const override;
    int m_throttle;

public:
    Car();
    Car(const float* lla);
    Car(const Car& obj);
    virtual ~Car() override;
    void setThrottle(const int throttle);
    const int getThrottle() const;
    virtual void Move(const float* lla) override;
    void drive(const int throttle);
    void operator=(const Car &other);

};

#endif
