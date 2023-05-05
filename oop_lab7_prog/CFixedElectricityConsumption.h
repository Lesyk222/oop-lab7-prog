#pragma once

#include "CElectricityConsumption.h"
#include "CTariffs.h"

class CFixedElectricityConsumption : public CElectricityConsumption {
public:
    double GetElectricityBill(double dConsumptionPerHours[24U]) const override;
    void PrintName() const override;
};
