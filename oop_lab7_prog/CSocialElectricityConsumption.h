#pragma once

#include "CElectricityConsumption.h"
#include "CTariffs.h"

class CSocialElectricityConsumption : public CElectricityConsumption {
public:
    double GetElectricityBill(double dConsumptionPerHours[24U]) const override;
};
