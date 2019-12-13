#ifndef WARRANTYBEHAVIOR_H_
#define WARRANTYBEHAVIOR_H_

#include <iostream>
using namespace std;
//WarrantyBehavior.h
class WarrantyBehavior{
public:
    virtual ~WarrantyBehavior()=default;
    virtual void Warranty()=0;
};
class ElectronicWarranty : public WarrantyBehavior{
public:
    void Warranty(){
        cout<<"Returnable within 30 days"<<endl;
    }
};

class NoWarranty : public WarrantyBehavior{
public:
    void Warranty(){
        cout<<"This item canot be returned"<<endl;
    }
};


#endif