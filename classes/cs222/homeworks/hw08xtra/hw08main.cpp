#include <iostream>
#include <string>
#include <sstream>

#include "cmps222lib.h"
#include "inherited.h"

#ifndef HEADER
#define HEADER

using namespace std;

int main() {
   
    class InventoryItem invItem, invItem2;
    class ReplenishInventoryItem repItem;
    class WholeSaleItem wItem;
    class RetailItem rItem;

    cout<<"Setting ModelNumber for InventoryItem"<<endl;
    invItem.SetModelNumber("1969 Stingray");
    
    cout<<"Testing using the GetModelNumber function" <<endl;
    cout<< invItem.GetModelNumber() << endl <<endl;

    cout<<"Testing SetCost for InventoryItem"<<endl;
    invItem.SetCost(30000);

    cout<<"Testing GetCost for InventoryItem"<<endl;
    cout<< invItem.GetCost() <<endl <<endl;

    cout<<"Testing SetUnitCount for InventoryItem"<<endl;
    invItem.SetUnitCount(300);

    cout<<"Testing GetUnitCount for InventoryItem"<<endl;
    cout<< invItem.GetUnitCount() <<endl <<endl;

    cout<<"Testing SetLocation for InventoryItem"<<endl;
    invItem.SetLocation("Chicago");

    cout<<"Testing GetLocation for InventoryItem"<<endl;
    cout<< invItem.GetLocation() <<endl <<endl;

    cout<<"Testing SetOnHand for InventoryItem"<<endl;
    invItem.SetOnHand(9);

    cout<<"Testing GetOnHand for InventoryItem"<<endl;
    cout<< invItem.GetOnHand()<< endl <<endl;

    cout<<"Testing SetBackOrdered for InventoryItem"<<endl;
    invItem.SetBackOrdered(10);

    cout<<"Testing GetBackOrdered for InventoryItem"<<endl;
    cout<< invItem.GetBackOrdered() << endl << endl;

    cout<< "Testing ToString for InventoryItem"<<endl;
    cout<< invItem.ToString() << endl <<endl;


/*============================================/
 * Setting values for invItem2
 * ==========================================*/

    cout<<"Setting ModelNumber for InventoryItem"<<endl;
    invItem2.SetModelNumber("1964 Shelby Mustang");
    
    cout<<"Testing using the GetModelNumber function" << endl
	<< invItem2.GetModelNumber() << endl <<endl;

    cout<<"Testing SetCost for InventoryItem"<<endl;
    invItem2.SetCost(30000);

    cout<<"Testing GetCost for InventoryItem"<<endl;
    cout<< invItem2.GetCost() <<endl <<endl;

    cout<<"Testing SetUnitCount for InventoryItem"<<endl;
    invItem2.SetUnitCount(300);

    cout<<"Testing GetUnitCount for InventoryItem"<<endl;
    cout<< invItem2.GetUnitCount() <<endl <<endl;

    cout<<"Testing SetLocation for InventoryItem"<<endl;
    invItem2.SetLocation("Chicago");

    cout<<"Testing GetLocation for InventoryItem"<<endl;
    cout<< invItem2.GetLocation() <<endl <<endl;

    cout<<"Testing SetOnHand for InventoryItem"<<endl;
    invItem2.SetOnHand(9);

    cout<<"Testing GetOnHand for InventoryItem"<<endl;
    cout<< invItem2.GetOnHand()<< endl <<endl;

    cout<<"Testing SetBackOrdered for InventoryItem"<<endl;
    invItem2.SetBackOrdered(291);

    cout<<"Testing GetBackOrdered for InventoryItem"<<endl;
    cout<< invItem2.GetBackOrdered() << endl << endl;

    cout<< "Testing ToString for InventoryItem"<<endl;
    cout<< invItem2.ToString() << endl <<endl;

    cout<< "Testing the overloaded operator for InventoryItem"<<endl;
    cout<< "Is " << invItem.GetModelNumber() << " less than "; 
    cout<< invItem2.GetModelNumber() << "?" << endl;
    if(invItem < invItem2){
      cout<< invItem.GetModelNumber() << " is less than ";
      cout<< invItem2.GetModelNumber() <<endl;
    }
    else{
	cout<< invItem2.GetModelNumber() << " is less than "; 
	cout<< invItem.GetModelNumber() << endl <<endl;
    }
//-----------------------------------------------------------------//
//-----------------------------------------------------------------//
    cout<<"Setting ModelNumber for ReplenishInventoryItem"<<endl;
    repItem.SetModelNumber("1964 Shelby Mustang");
    
    cout<<"Testing using the GetModelNumber function" << endl
	<< repItem.GetModelNumber() << endl <<endl;

    cout<<"Testing SetCost for ReplenishInventoryItem"<<endl;
    repItem.SetCost(30000);

    cout<<"Testing GetCost for ReplenishInventoryItem"<<endl;
    cout<< repItem.GetCost() <<endl <<endl;

    cout<<"Testing SetUnitCount for ReplenishInventoryItem"<<endl;
    repItem.SetUnitCount(300);

    cout<<"Testing GetUnitCount for ReplenishInventoryItem"<<endl;
    cout<< repItem.GetUnitCount() <<endl <<endl;

    cout<<"Testing SetLocation for ReplenishInventoryItem"<<endl;
    repItem.SetLocation("Chicago");

    cout<<"Testing GetLocation for ReplenishInventoryItem" <<endl;
    cout<< repItem.GetLocation() <<endl <<endl;

    cout<<"Testing SetOnHand for ReplenishInventoryItem"<<endl;
    repItem.SetOnHand(9);

    cout<<"Testing GetOnHand for ReplenishInventoryItem"<<endl;
    cout<< repItem.GetOnHand()<< endl <<endl;

    cout<<"Testing SetBackOrdered for ReplenishInventoryItem"<<endl;
    repItem.SetBackOrdered(291);

    cout<<"Testing GetBackOrdered for ReplenishInventoryItem"<<endl;
    cout<< repItem.GetBackOrdered() << endl << endl;


    cout<<"Testing SetDistributorID for ReplenishInventoryItem"<<endl;
    repItem.SetDistributorID(99709);

    cout<<"Testing GetDistributorID for ReplenishInventoryItem"<<endl;
    cout<< repItem.GetDistributorID() << endl << endl;

    cout<<"Testing SetMinCount for ReplenishInventoryItem"<<endl;
    repItem.SetMinCount(1);

    cout<<"Testing GetMinCount for ReplenishInventoryItem"<<endl;
    cout<< repItem.GetMinCount() << endl << endl;

    cout<<"Testing SetMaxCount for ReplenishInventoryItem"<<endl;
    repItem.SetMaxCount(20);

    cout<<"Testing GetMaxCount for ReplenishInventoryItem"<<endl;
    cout<< repItem.GetMaxCount() << endl << endl;

    cout<<"Testing SetCaseCount for ReplenishInventoryItem"<<endl;
    repItem.SetCaseCount(14);

    cout<<"Testing GetCaseCount for ReplenishInventoryItem"<<endl;
    cout<< repItem.GetCaseCount() << endl << endl;

    cout<<"Testing SetCasePrice for ReplenishInventoryItem"<<endl;
    repItem.SetCasePrice(80);

    cout<<"Testing GetCasePrice for ReplenishInventoryItem"<<endl;
    cout<< "$" << repItem.GetCasePrice() << endl << endl;

    cout<< "Testing ToString for ReplenishInventoryItem"<<endl;
    cout<< repItem.ToString() << endl <<endl;

/*============================================/
 * Testing functions for WholeSaleItem        |
 * ===========================================*/

    cout<<"Setting ModelNumber for WholeSaleItem"<<endl;
    wItem.SetModelNumber("1964 Shelby Mustang");
    
    cout<<"Testing using the GetModelNumber function" << endl
	<< wItem.GetModelNumber() << endl <<endl;

    cout<<"Testing SetCost for WholeSaleItem"<<endl;
    wItem.SetCost(30000);

    cout<<"Testing GetCost for WholeSaleItem"<<endl;
    cout<< wItem.GetCost() <<endl <<endl;

    cout<<"Testing SetUnitCount for WholeSaleItem"<<endl;
    wItem.SetUnitCount(300);

    cout<<"Testing GetUnitCount for WholeSaleItem"<<endl;
    cout<< wItem.GetUnitCount() <<endl <<endl;

    cout<<"Testing SetLocation for WholeSaleItem"<<endl;
    wItem.SetLocation("Chicago");

    cout<<"Testing GetLocation for WholeSaleItem" <<endl;
    cout<< wItem.GetLocation() <<endl <<endl;

    cout<<"Testing SetOnHand for WholeSaleItem"<<endl;
    wItem.SetOnHand(9);

    cout<<"Testing GetOnHand for WholeSaleItem"<<endl;
    cout<< wItem.GetOnHand()<< endl <<endl;

    cout<<"Testing SetBackOrdered for WholeSaleItem"<<endl;
    wItem.SetBackOrdered(291);

    cout<<"Testing GetBackOrdered for WholeSaleItem"<<endl;
    cout<< wItem.GetBackOrdered() << endl << endl;


    cout<<"Testing SetDistributorID for WholeSaleItem"<<endl;
    wItem.SetDistributorID(99709);

    cout<<"Testing GetDistributorID for WholeSaleItem"<<endl;
    cout<< wItem.GetDistributorID() << endl << endl;

    cout<<"Testing SetMinCount for WholeSaleItem"<<endl;
    wItem.SetMinCount(1);

    cout<<"Testing GetMinCount for WholeSaleItem"<<endl;
    cout<< wItem.GetMinCount() << endl << endl;

    cout<<"Testing SetMaxCount for WholeSaleItem"<<endl;
    wItem.SetMaxCount(20);

    cout<<"Testing GetMaxCount for WholeSaleItem"<<endl;
    cout<< wItem.GetMaxCount() << endl << endl;

    cout<<"Testing SetCaseCount for WholeSaleItem"<<endl;
    wItem.SetCaseCount(14);

    cout<<"Testing GetCaseCount for WholeSaleItem"<<endl;
    cout<< wItem.GetCaseCount() << endl << endl;

    cout<<"Testing SetCasePrice at 80 for WholeSaleItem"<<endl;
    wItem.SetCasePrice(80);

    cout<<"Testing GetCasePrice for WholeSaleItem"<<endl;
    cout<< "$" << wItem.GetCasePrice() << endl << endl;

    cout<< "Testing WholeSaleCost at 25000 for WholeSaleItem" <<endl;
    wItem.SetWholeSaleCost(25000);

    cout<< "Testing GetWholeSaleCost for WholeSaleItem" <<endl;
    cout<< "$" << wItem.GetWholeSaleCost() << endl;

    cout<< "Testing ToString for WholeSaleItem"<<endl;
    cout<< wItem.ToString() << endl <<endl;

/*=================================================================/
 * Testing Functions for the RetailItem class                     |
 * ===============================================================*/

    cout<<"Setting ModelNumber for RetailItem"<<endl;
    rItem.SetModelNumber("1964 Shelby Mustang");
    
    cout<<"Testing using the GetModelNumber function" << endl
	<< rItem.GetModelNumber() << endl <<endl;

    cout<<"Testing SetCost for RetailItem"<<endl;
    rItem.SetCost(30000);

    cout<<"Testing GetCost for RetailItem"<<endl;
    cout<< rItem.GetCost() <<endl <<endl;

    cout<<"Testing SetUnitCount for RetailItem"<<endl;
    rItem.SetUnitCount(300);

    cout<<"Testing GetUnitCount for RetailItem"<<endl;
    cout<< rItem.GetUnitCount() <<endl <<endl;

    cout<<"Testing SetLocation for RetailItem"<<endl;
    rItem.SetLocation("Chicago");

    cout<<"Testing GetLocation for RetailItem" <<endl;
    cout<< rItem.GetLocation() <<endl <<endl;

    cout<<"Testing SetOnHand for RetailItem"<<endl;
    rItem.SetOnHand(9);

    cout<<"Testing GetOnHand for RetailItem"<<endl;
    cout<< rItem.GetOnHand()<< endl <<endl;

    cout<<"Testing SetBackOrdered for RetailItem"<<endl;
    rItem.SetBackOrdered(291);

    cout<<"Testing GetBackOrdered for RetailItem"<<endl;
    cout<< rItem.GetBackOrdered() << endl << endl;


    cout<<"Testing SetDistributorID for RetailItem"<<endl;
    rItem.SetDistributorID(99709);

    cout<<"Testing GetDistributorID for RetailItem"<<endl;
    cout<< rItem.GetDistributorID() << endl << endl;

    cout<<"Testing SetMinCount for RetailItem"<<endl;
    rItem.SetMinCount(1);

    cout<<"Testing GetMinCount for RetailItem"<<endl;
    cout<< rItem.GetMinCount() << endl << endl;

    cout<<"Testing SetMaxCount for RetailItem"<<endl;
    rItem.SetMaxCount(20);

    cout<<"Testing GetMaxCount for RetailItem"<<endl;
    cout<< rItem.GetMaxCount() << endl << endl;

    cout<<"Testing SetCaseCount for RetailItem"<<endl;
    rItem.SetCaseCount(14);

    cout<<"Testing GetCaseCount for RetailItem"<<endl;
    cout<< rItem.GetCaseCount() << endl << endl;

    cout<<"Testing SetCasePrice at 80 for RetailItem"<<endl;
    rItem.SetCasePrice(80);

    cout<<"Testing GetCasePrice for RetailItem"<<endl;
    cout<< "$" << rItem.GetCasePrice() << endl << endl;

    cout<< "Testing SetWholeSaleCost at 40000 for RetailItem" <<endl;
    rItem.SetWholeSaleCost(40000);

    cout<< "Testing GetWholeSaleCost for RetailItem" <<endl;
    cout<< "$" << rItem.GetWholeSaleCost() << endl;

    cout<< "Testing SetRetailCost at 40000 for RetailItem" <<endl;
    rItem.SetRetailCost(40000);

    cout<< "Testing GetRetailCost for RetailItem" <<endl;
    cout<< "$" << rItem.GetRetailCost() << endl;

    cout<< "Testing ToString for RetailItem"<<endl;
    cout<< rItem.ToString() << endl <<endl;

    return 0;
}
#endif
