#include <iostream>
#include <memory>
#include "CElectricityConsumption.h"
#include "CFixedElectricityConsumption.h"
#include "CSocialElectricityConsumption.h"
#include "CMultiZoneElectricityConsumption.h"

using namespace std;

void GetMinMaxBills(unique_ptr<CElectricityConsumption>* arr, int size, double dConsumptionPerHours[24U], double& minBill, double& maxBill)
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

    //unique_ptr<CElectricityConsumption> consumption1 = make_unique<CFixedElectricityConsumption>();
    //unique_ptr<CElectricityConsumption> consumption2 = make_unique<CSocialElectricityConsumption>();
    //unique_ptr<CElectricityConsumption> consumption3 = make_unique<CMultiZoneElectricityConsumption>();

    //double bill1 = consumption1->GetElectricityBill(dConsumption);
    //double bill2 = consumption2->GetElectricityBill(dConsumption);
    //double bill3 = consumption3->GetElectricityBill(dConsumption);

    CElectricityConsumption* consumption = nullptr;

    cout << "Choose the tariff (1 - Fixed, 2 - Social, 3 - Multi-zone): ";
    int choice;
    cin >> choice;

 /*   switch (choice) {
    case 1:
        consumption = dynamic_cast<CFixedElectricityConsumption*>(consumption1.get());
        break;
    case 2:
        consumption = dynamic_cast<CSocialElectricityConsumption*>(consumption2.get());
        break;
    case 3:
        consumption = dynamic_cast<CMultiZoneElectricityConsumption*>(consumption3.get());
        break;
    default:
        cout << "Invalid choice!" << endl;
    }*/

   switch (choice) {
   case 1:
       consumption = new CFixedElectricityConsumption();
       //consumption = dynamic_cast<CFixedElectricityConsumption*>();
       break;
   case 2:
       consumption = new CSocialElectricityConsumption();
       break;
   case 3:
       consumption = new CMultiZoneElectricityConsumption();
       break;
   default:
       cout << "Invalid choice!" << endl;
   }

    double selectedBill = consumption->GetElectricityBill(dConsumption);

    cout << "Choosed price: " << selectedBill << endl
        << typeid(consumption).name() << endl;
    consumption->PrintName();

    return 0;
}