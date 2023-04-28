#include <iostream>

#include "CElectricityConsumption.h"
#include "CFixedElectricityConsumption.h"
#include "CSocialElectricityConsumption.h"
#include "CMultiZoneElectricityConsumption.h"

using namespace std;

void GetMinMaxBills(CElectricityConsumption** arr, int size, double dConsumptionPerHours[24U], double& minBill, double& maxBill)
{
    minBill = arr[0]->GetElectricityBill(dConsumptionPerHours);
    maxBill = minBill;

    for (int i = 1; i < size; i++) {
        double bill = arr[i]->GetElectricityBill(dConsumptionPerHours);

        if (bill < minBill) {
            minBill = bill;
        }

        if (bill > maxBill) {
            maxBill = bill;
        }
    }
}


int main()
{
    double dConsumption[24] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24 };

    CElectricityConsumption* consumption1 = new CFixedElectricityConsumption();
    CElectricityConsumption* consumption2 = new CSocialElectricityConsumption();
    CElectricityConsumption* consumption3 = new CMultiZoneElectricityConsumption();

    double bill1 = consumption1->GetElectricityBill(dConsumption);
    double bill2 = consumption2->GetElectricityBill(dConsumption);
    double bill3 = consumption3->GetElectricityBill(dConsumption);

    cout << "Fixed consumption bill: " << bill1 << endl;
    cout << "Social consumption bill: " << bill2 << endl;
    cout << "Multi-zone consumption bill: " << bill3 << endl;


    const int size = 3;
    CElectricityConsumption* arr[size] = { consumption1, consumption2, consumption3 };

    double minBill, maxBill;
    GetMinMaxBills(arr, size, dConsumption, minBill, maxBill);

    cout << "Minimum bill: " << minBill << endl;
    cout << "Maximum bill: " << maxBill << endl;

    delete consumption1;
    delete consumption2;
    delete consumption3;
    return 0;
}