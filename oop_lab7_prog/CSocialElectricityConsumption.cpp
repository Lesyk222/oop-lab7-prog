#include "CSocialElectricityConsumption.h"

double CSocialElectricityConsumption::GetElectricityBill(double dConsumptionPerHours[24U]) const {
    double sum = 0;
    for (int i = 0; i < 24; i++) {
        sum += dConsumptionPerHours[i] * CTariffs::socialPriceOfKilowat;
    }
    return sum; // Повернення суми нарахувань у грн
}

void CSocialElectricityConsumption::PrintName() const {
    std::cout << "Social tariff";
}