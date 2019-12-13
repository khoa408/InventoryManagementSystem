#ifndef ITEMS_H_
#define ITEMS_H_

#include <iostream>
#include <string>
#include <map>
#include "DiscountBehavior.h"
#include "WarrantyBehavior.h"
using namespace std;
enum Weight_unit{
    pound,
    ounce,
    gram,
    kilogram
};
enum Gender{
    male,
    female,
    unisex
};
ostream& operator<<(ostream& out, const Weight_unit value){
    static map<Weight_unit,string> strings;
    if(strings.size()==0){
        strings[Weight_unit::pound] = "pound";
        strings[Weight_unit::ounce] = "ounce";
        strings[Weight_unit::gram] = "gram";
        strings[Weight_unit::kilogram] = "kilogram";
    }
    return out<<strings[value];
}
//Do gender after
class ItemSpecs{
public:
    ItemSpecs(string iname, int i, int q, float up){
        itemname = iname;
        id = i;
        quantity = q;  
        unit_price = up;
    }
    int id;
    string itemname;
    int quantity;
    float unit_price;
    
       
};

class FoodSpecs : public ItemSpecs{
public:
    FoodSpecs(string iname, int i, int q, float up,string exp_date, float w, Weight_unit u) : ItemSpecs(iname, i, q, up){
        expiration_date = exp_date;
        weight = w;
        unit = u;
    }

    string expiration_date;
    float weight;  
    Weight_unit unit;
};

class ClothesSpecs : public ItemSpecs{
public:
    ClothesSpecs(string iname, int i, int q, float up,Gender g) : ItemSpecs(iname, i, q, up){
        gender = g;
    }
    Gender gender; 
};
//Items.h
class Items{
public:
    virtual ~Items(){}
    virtual void printItem()=0;
    string getName();
    int getQuantity (){return specs->quantity;}
    void setQuantity (int amt){specs->quantity = amt;}
    void perform_return(){ warranty_behavior->Warranty();}
    int get_discount(){return discount_behavior->Discount();}
    float getPrice(int amt){return specs->unit_price * amt;} 
    ItemSpecs getSpecs(){return *specs;} 
    
protected:
    Items (ItemSpecs* i){
        specs = i;
    };
    ItemSpecs* specs;
    WarrantyBehavior *warranty_behavior;
    DiscountBehavior *discount_behavior;
};

class Food: public Items{
public:
    void printItem(){
        FoodSpecs* spec = static_cast<FoodSpecs*>(specs);
        cout<<"ItemName:"<<spec->itemname<<" ItemID:"<<spec->id<<" Quantity:"<<spec->quantity<<" Weight:"<<spec->weight<<" Unit:"<<spec->unit<<" Price:"<<spec->unit_price<<" EXPD:"<<spec->expiration_date<<endl;
    }
    Food(ItemSpecs* fs): Items (fs)
    {
        warranty_behavior = new NoWarranty();
        discount_behavior = new NoDiscount();
    }  
    /*float getPrice(){
        FoodSpecs* spec = static_cast<FoodSpecs*>(specs);
        return spec->weight*spec->unit_price;
    }//overwrite    */
};


class Clothes: public Items{
    public:
        Clothes(ItemSpecs* cs): Items (cs){
        // *Place holder for later implementation*
        // warranty_behavior = new ClothesWarranty();
        // discount_behavior = new NoDiscount();
        }
    void printItem(){
        ClothesSpecs* spec = static_cast<ClothesSpecs*>(specs);
        cout<<"Item Name:"<<spec->itemname<<" ItemID:"<<spec->id<<" Quantity:"<<spec->quantity<<" Price:"<<spec->unit_price<<" Gender:"<<spec->gender<<endl;
    }   
};

class Electronic : public Items{
public:
    Electronic(ItemSpecs* specs): Items (specs){
        warranty_behavior = new ElectronicWarranty();
    }
    void printItem(){
        cout<<"Item Name:"<<specs->itemname<<" ItemID:"<<specs->id<<" Quantity:"<<specs->quantity<<" Price:"<<specs->unit_price<<endl;
    } 
};

#endif