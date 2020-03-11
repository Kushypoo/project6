#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <cstring>

class Vehicle
{
    protected:
    
        float m_lla[3];
        
    private:
    
        virtual void serialize(std::ostream & os) const;
        
    public:
    
    	Vehicle();
    	Vehicle(const float* m_lla);
    	Vehicle(const Vehicle &obj);
    	virtual ~Vehicle();
    	void SetLLA(const float *lla);
    	const float *getLLA() const;
    	friend std::ostream & operator<<(std::ostream & os, const Vehicle & vehicle);
    	void operator=(const Vehicle& other);
    	virtual void Move(const float* lla) = 0;

};

#endif
