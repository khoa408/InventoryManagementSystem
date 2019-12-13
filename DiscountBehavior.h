#ifndef DISCOUNTBEHAVIOR_H_
#define DISCOUNTBEHAVIOR_H_

#include <iostream>
using namespace std;
//DiscountBehavior.h
class DiscountBehavior{
public:
    virtual ~DiscountBehavior()=default;
    virtual int Discount() = 0;//returns the percentage (e.g 50 for 50%)
};

class BlackFridayDiscount : public DiscountBehavior{
public:
    int Discount(){
        cout<<"You got a black Friday discount!"<<endl;
      	return 50;
    }
};

class NoDiscount : public DiscountBehavior{
public:
    int Discount(){
        cout<<"no discont allowed for this item"<<endl;
      	return 0;
    }
};

#endif