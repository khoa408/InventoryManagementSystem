// #ifndef WAREHOUSE_H_
// #define WAREHOUSE_H_

// #include <iostream>
// #include <string>
// #include <vector>
// #include <iterator>
// #include "Observer.h"
// #include "Items.h"
// using namespace std;
// class Warehouse : public Subject{
// public:
//     Warehouse():warehouse_id(0),warehouse_name(""){}

//     Warehouse(int i,string wname):warehouse_id(i),warehouse_name(wname){}

//     void print(){
//         int counter = 1;
//         for(Items* item: item_vec){
//             cout<<counter++<<". ";
//             item->printItem();
//         }
//     }

//     void update_vec(Items* x){
//         int index = search(x->getSpecs().id);
//         if(index != -1){
//             item_vec[index] = x;
//         }
//     }

//     int search(int iID){
//         for(int i=0;i<item_vec.size();i++){
//             if(item_vec[i]->getSpecs().id == iID){
//                 return i;
//             }
//         }
//         return -1;
//     }
//     void add_item(Items *x){
//         if(search(x->getSpecs().id) == -1){
//             item_vec.push_back(x);
//         }
//         else{
//             update_vec(x);
//         }
//         notify();
//     }
//     void sell_item(Items *x,int amt){
//         if(search(x->getSpecs().id) == -1){//does not exist
//             cout<<"Item Does Not Exist!"<<endl;
//         }
//         else if(x->getQuantity() < amt){
//             cout<<"Low On Stock, Not Enough!"<<endl;
//         }
//         else{
//             x->setQuantity(x->getQuantity() - amt);
//         }
//         notify();
//     }
//     void sell_item(int index,int amt){
//         if(index < 0 || index >= item_vec.size()){//does not exist
//             cout<<"Item Does Not Exist!"<<endl;
//         }
//         else if(item_vec[index]->getQuantity() < amt){
//             cout<<"Low On Stock, Not Enough!"<<endl;
//         }
//         else{
//             item_vec[index]->setQuantity(item_vec[index]->getQuantity() - amt);
//         }
//         notify();
//     }

//     void notify()override{
//         // for(vector<Observer *>::iterator it = views.begin();it!=views.end();it++){
//         //     it->update(item_vec);
//         // }
//         // for (int i = 0; i < views.size(); i++){
//         //     views[i]->update(item_vec);
//         // }
//         for(vector<Observer*>::iterator it=views.begin();it!=views.end();it++){
//             (*it)->update(this,item_vec);
//         }
//     }
//     void printViewSize(){
//         cout<<"View Size: "<<views.size()<<endl;
//     }
//     void attach(Observer* observer)override{
//         views.push_back(observer);
//     }
//     void evict(Observer* observer)override{
//         vector<Observer *>::iterator it = find(views.begin(), views.end(), observer);

//         if (it != views.end()) { // observer found
//         views.erase(it); // remove the observer
//         }
//     }
//     string getName(){return warehouse_name;}
//     int getID(){return warehouse_id;}
// private:
//     vector<Items*> item_vec;
//     vector<Observer *>views;
//     int warehouse_id;
//     string warehouse_name;
// };

// #endif
#ifndef WAREHOUSE_H_
#define WAREHOUSE_H_

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include "Observer.h"
#include "Items.h"
using namespace std;
class Warehouse : public Subject{
public:
    Warehouse():warehouse_id(0),warehouse_name(""){}

    Warehouse(int i,string wname):warehouse_id(i),warehouse_name(wname){}

    void print(){
        int counter = 1;
        for(Items* item: item_vec){
            cout<<counter++<<". ";
            item->printItem();
        }
    }

    void update_vec(Items* x){
        int index = search(x->getSpecs().id);
        if(index != -1){
            item_vec[index] = x;
        }
    }

    int search(int iID){
        for(int i=0;i<item_vec.size();i++){
            if(item_vec[i]->getSpecs().id == iID){
                return i;
            }
        }
        return -1;
    }
    void add_item(Items *x){
        if(search(x->getSpecs().id) == -1){
            item_vec.push_back(x);
        }
        else{
            update_vec(x);
        }
        notify();
    }
    void sell_item(Items *x,int amt){
        if(search(x->getSpecs().id) == -1){//does not exist
            cout<<"Item Does Not Exist!"<<endl;
        }
        else if(x->getQuantity() < amt){
            cout<<"Low On Stock, Not Enough!"<<endl;
        }
        else{
            x->setQuantity(x->getQuantity() - amt);
        }
        notify();
    }
    void sell_item(int index,int amt){
        if(index < 0 || index >= item_vec.size()){//does not exist
            cout<<"Item Does Not Exist!"<<endl;
        }
        else if(item_vec[index]->getQuantity() < amt){
            cout<<"Low On Stock, Not Enough!"<<endl;
        }
        else{
            item_vec[index]->setQuantity(item_vec[index]->getQuantity() - amt);
        }
        notify();
    }

    void notify()override{
        // for(vector<Observer *>::iterator it = views.begin();it!=views.end();it++){
        //     it->update(item_vec);
        // }
        // for (int i = 0; i < views.size(); i++){
        //     views[i]->update(item_vec);
        // }
        for(vector<Observer*>::iterator it=views.begin();it!=views.end();it++){
            (*it)->update(item_vec);
        }
    }
    void printViewSize(){
        cout<<"View Size: "<<views.size()<<endl;
    }
    void attach(Observer* observer)override{
        views.push_back(observer);
        observer->update(item_vec);
    }
    void evict(Observer* observer)override{
        vector<Observer *>::iterator it = find(views.begin(), views.end(), observer);

        if (it != views.end()) { // observer found
        views.erase(it); // remove the observer
        }
    }
    void perform_return(int index){
        if(index < 0 || index >= item_vec.size()){//does not exist
            cout<<"Item Does Not Exist!"<<endl;
        }
        else{
            item_vec[index]->perform_return();
        }
    }
    string getName(){return warehouse_name;}
    int getID(){return warehouse_id;}
private:
    vector<Items*> item_vec;
    vector<Observer *>views;
    int warehouse_id;
    string warehouse_name;
};

#endif