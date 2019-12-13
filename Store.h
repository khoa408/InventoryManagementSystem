// #ifndef STORE_H_
// #define STORE_H_

// #include <iostream>
// #include "Observer.h"
// #include <map>
// #include <vector>
// #include "Items.h"
// #include "Warehouse.h"
// using namespace std;
// //Store.h
// class Store : public Observer{
// public:
// 	//using Store::update;
//     void print(){
//     	map<Warehouse*,vector<Items*>>::iterator it;
//     	for(it = warehouse_map.begin();it!=warehouse_map.end();it++){
//     		cout<<"From Warehouse "<<it->first->getName()<<" ";
//     		it->second->printItem();
//     	}
//         // for(Items* item: warehouse_vec){
//         //     item->printItem();
//         // }
//     }
//     // Store(int id,Warehouse* warehouse) : Observer(warehouse){
//     //     store_id = id;
//     // }
//     Store():store_id(0),store_name(""),subject(nullptr){}
//     Store(int id,string sname):store_id(id),subject(nullptr),store_name(sname){}
//     Store(int id,Warehouse* warehouse,string sname){
//     	warehouse->attach(this);
// 		store_id = id;
// 		subject = warehouse;
// 		store_name = sname;
//     }
//     void update(vector<Items*> item_vec)override{
//         warehouse_vec.clear();
//         for(Items* item: item_vec){
//         	warehouse_vec.push_back(item);
// 		}
//     }
//     void update(Warehouse* warehouse,vector<Items*> item_vec)override{
//     	warehouse_map[warehouse].clear();
//         for(Items* item: item_vec){
//         	warehouse_map[warehouse].push_back(item);
// 		}
//     }
//     void order(Items* item,int amt){
//     	cout<<"Total Cost would be: "<<item->getPrice(amt)<<endl;
//     	subject->sell_item(item,amt);
//     }
//     string getName(){return store_name;}
//     int getID(){return store_id;}
//     void unattach(){
//     	subject = nullptr;
//     }
//     void attach(Warehouse * w){
//     	subject = w;
//     }
// private:
//     //std::vector<Items*> warehouse_vec;
//     std::map<Warehouse*,vector<Items*>> warehouse_map;
//  	Warehouse * subject;
//  	int store_id;
//  	string store_name;
// };

// #endif

#ifndef STORE_H_
#define STORE_H_

#include <iostream>
#include "Observer.h"
#include <map>
#include <vector>
#include "Items.h"
#include "Warehouse.h"
using namespace std;
//Store.h
class Store : public Observer{
public:
	//using Store::update;
    void print(){
        int counter = 1;
        for(Items* item: warehouse_vec){
            cout<<counter++<<". ";
            item->printItem();
        }
    }
    // Store(int id,Warehouse* warehouse) : Observer(warehouse){
    //     store_id = id;
    // }
    Store():store_id(0),store_name(""),subject(nullptr){}
    Store(int id,string sname):store_id(id),subject(nullptr),store_name(sname){}
    Store(int id,Warehouse* warehouse,string sname){
    	warehouse->attach(this);
		store_id = id;
		subject = warehouse;
		store_name = sname;
    }
    void update(vector<Items*> item_vec)override{
        warehouse_vec.clear();
        for(Items* item: item_vec){
        	warehouse_vec.push_back(item);
		}
    }
    void order(Items* item,int amt){
    	cout<<"Total Cost would be: "<<item->getPrice(amt)<<endl;
    	subject->sell_item(item,amt);
    }
    string getName(){return store_name;}
    int getID(){return store_id;}
    void unattach(){
    	subject = nullptr;
    }
    void attach(Warehouse * w){
    	subject = w;
    }
private:
    std::vector<Items*> warehouse_vec;
    //std::map<int,vector<Items*>> warehouse_map;
 	Warehouse * subject;
 	int store_id;
 	string store_name;
};

#endif
