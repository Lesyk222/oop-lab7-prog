#pragma once
#include <iostream>

class CElectricityConsumption
{
public:
    virtual double GetElectricityBill(double dConsumptionPerHours[24U]) const = 0;
    virtual void PrintName() const = 0;
};
