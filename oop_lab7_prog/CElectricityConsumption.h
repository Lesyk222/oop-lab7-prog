#pragma once

class CElectricityConsumption
{
public:
    virtual double GetElectricityBill(double dConsumptionPerHours[24U]) const = 0;
};
