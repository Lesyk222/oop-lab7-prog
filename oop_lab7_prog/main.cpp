#include <iostream>
#include <memory>
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


    cout << "Choose the tariff (1 - Fixed, 2 - Social, 3 - Multi-zone): ";
    int choice;
    cin >> choice;
    CElectricityConsumption* consumption = nullptr;

    switch (choice) {
    case 1:
        consumption = new CFixedElectricityConsumption();
        break;
    case 2:
        consumption = new CSocialElectricityConsumption();
        break;
    case 3:
        consumption = new CMultiZoneElectricityConsumption();
        break;
    default:
        cout << "Invalid choice!" << endl;
        return 1;
    }

    if (typeid(*consumption) == typeid(CFixedElectricityConsumption)) {
        double selectedBill = consumption->GetElectricityBill(dConsumption);
        cout << "Choosed fixed price: " << selectedBill << endl << endl;  
    }
    else if (typeid(*consumption) == typeid(CSocialElectricityConsumption)) {
        double selectedBill = consumption->GetElectricityBill(dConsumption);
        cout << "Choosed social price: " << selectedBill << endl << endl;
    }
    else if (typeid(*consumption) == typeid(CMultiZoneElectricityConsumption)) {
        double selectedBill = consumption->GetElectricityBill(dConsumption);
        cout << "Choosed multizone: " << selectedBill << endl << endl;
    }

    delete consumption;

    return 0;
}