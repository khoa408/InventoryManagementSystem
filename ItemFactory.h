#include <iostream>
#include <string>
#include "Items.h"
using namespace std;
//ItemFactory.h
class ItemFactory{
public:
      Items* createItem(string item_type,ItemSpecs* specs){
        if(item_type == "Food"){
            return new Food(specs);
        }
        else if(item_type == "Clothes"){
            return new Clothes(specs);
        }
        else if(item_type == "Electronic"){
            return new Electronic(specs);
        }
        else{
            return new Food(specs);
        }
      }
};