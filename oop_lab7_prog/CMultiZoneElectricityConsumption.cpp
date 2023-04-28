#include "CMultiZoneElectricityConsumption.h"

double CMultiZoneElectricityConsumption::GetElectricityBill(double dConsumptionPerHours[24U]) const {
    double sum = 0;
    for (int i = 0; i < 24; i++) {
        if ((i >= 0 && i < 7) || i == 23) {
            sum += dConsumptionPerHours[i] * CTariffs::socialPriceOfKilowat;
        }
        else if (i == 7 || (i >= 11 && i < 17)) {
            sum += dConsumptionPerHours[i] * CTariffs::normalPriceOfKilowat;
        }
        else
        {
            sum += dConsumptionPerHours[i] * CTariffs::peekPrice;
        }
    }
    return sum;
}