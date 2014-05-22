#pragma once

using namespace std;

class InventoryItem {
    protected:
	string ModelNumber;
	double Cost;
	double UnitCount;
	string Location;
	int OnHand;
	int BackOrdered;

    public:
	InventoryItem()
	{ cout<< "InventoryItem constructing, wear a hardhat." << endl;  }
	virtual ~InventoryItem()
	{ cout<< "InventoryItem destructing, impending doom!" << endl; }
	
//Mutator Functions
	void SetModelNumber(string pass){ 
		ModelNumber=pass; 
	}
	
	bool SetCost(double pass){
	    if(pass>=0){
		Cost = pass;
		return true;
	    }
	    return false;
	}
	
	bool SetUnitCount(double pass) { 
	    if(pass>=0){
		UnitCount = pass;
		return true;
	    }
	    return false;
	}
	
	void SetLocation(string pass) { Location = pass; }
	
	bool SetOnHand(int pass){
	    if(pass>=0){
		OnHand=pass;
		return true;
	    }
	    return false;
	}
	
	bool SetBackOrdered(int pass){
	    if(pass>=0){
		BackOrdered=pass;
		return true;
	    }
	    return false;
	}
//Accessor Functions
	string GetModelNumber(){ return ModelNumber; }
	double GetCost(){ return Cost; }
	double GetUnitCount() { return UnitCount; }
	string GetLocation() { return Location; }
	int GetOnHand() { return OnHand; }
	int GetBackOrdered() { return BackOrdered; }
	

	virtual string ToString(){
	    ostringstream oss;
	    oss<< "Cost: " << Cost << endl;
	    oss<< "UnitCount: " << UnitCount << endl;
	    oss<< "Location: " << Location << endl;
	    oss<< "OnHand: " << OnHand << endl;
	    oss<< "BackOrdered: " << BackOrdered << endl;
	return oss.str();
	}
	
	bool operator < (InventoryItem &rhs){
	    bool query = false;
	    if(ModelNumber < rhs.ModelNumber){
		query = true;
		return query;
	    }
	    return query;
	}
};

class ReplenishInventoryItem : public InventoryItem {
    protected:
	int DistributorID;
	int MinCount;
	int MaxCount;
	int CaseCount;
	int CasePrice;
    public:
	ReplenishInventoryItem() : InventoryItem() 
	{ cout<< "Replenish Constructor runs now." << endl; }
	~ReplenishInventoryItem()
	{ cout<< "Replenish Destructor killin it off." << endl; }
	
//Mutator Functions
	bool SetDistributorID(int pass){
	    if (pass>=0){
		DistributorID=pass;
		return true;
	    }
	    return false;
	}
	
	bool SetMinCount(int pass) {
	    if (pass>=0){
		MinCount=pass;
		return true;
	    }
	    return false;
	}
	
	bool SetMaxCount(int pass){
	    if (pass>=0){
		MaxCount=pass;
		return true;
	    }
	    return false;
	}
	
	bool SetCaseCount(int pass){
	    if (pass>=0){
		CaseCount=pass;
		return true;
	    }
	    return false;
	}
	
	bool SetCasePrice(int pass){
	    if (pass>=0){
		CasePrice=pass;
		return true;
	    }
	    return false;
	}
	
//Accessor Functions
	int GetDistributorID() { return DistributorID; }
	int GetMinCount() { return MinCount; }     
	int GetMaxCount() { return MaxCount; }
	int GetCaseCount() { return CaseCount; }
	int GetCasePrice() { return CasePrice; }

	string ToString(){
	    
	    ostringstream oss;
	    oss<< boolalpha << InventoryItem::ToString() <<endl;
	    oss<< "DistributorID: " << DistributorID << endl;
	    oss<< "MinCount: " << MinCount << endl;
	    oss<< "MaxCount: " << MaxCount << endl;
	    oss<< "CaseCount: " << CaseCount << endl;
	    oss<< "CasePrice: " << CasePrice << endl;
	    return oss.str();
	}
};

class WholeSaleItem : public ReplenishInventoryItem {
    protected:
	double WholeSaleCost;
    public:
	WholeSaleItem()
	{ cout<< "Wholesale runs now" << endl; }
	~WholeSaleItem()
	{ cout<< "Wholesale Destructor killin it off." << endl; }
	
//Accessor functions    
	double GetWholeSaleCost() { return WholeSaleCost; }
	
//Mutator functions	
	bool SetWholeSaleCost(double pass){
	    if (pass>=0){
		WholeSaleCost = pass;
		return true;
	    }
	    return false;
	}
	string ToString(){
	    ostringstream oss;
	    oss<< boolalpha << ReplenishInventoryItem::ToString();
	    oss<< "WholeSaleCost: " << WholeSaleCost << endl;
	    return oss.str();
	}
};

class RetailItem : public WholeSaleItem {
    protected:
	double RetailCost;
    public:
	RetailItem() 
	{ cout << "RetailItem is constructing, wear a hardhat." << endl; }
	~RetailItem()
	{ cout<< "RetailItem is destructing, impending doom." << endl; }

//Accessor functions	
	double GetRetailCost() { return RetailCost; }
	
//Mutator functions
	bool SetRetailCost(double pass) {
	    if (pass>=0){
		RetailCost=pass;
		return true;
	    }
	    return false;
	}

	string ToString(){
	    ostringstream oss;
	    oss<< boolalpha << WholeSaleItem::ToString() << endl;
	    oss<< "RetailCost: " << RetailCost << endl;
	    return oss.str();
	}
};

