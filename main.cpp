#include <iostream>
#include "Warehouse.h"
#include "Store.h"
#include "Items.h"
#include "ItemFactory.h"
#include <vector>
using namespace std;

void printMenu(){
	cout<<"**************************************"<<endl;
	cout<<"**************** MENU ****************"<<endl;
	cout<<"**************************************"<<endl;
	cout<<"1. Add Warehouses"<<endl;
	cout<<"2. Add Stores"<<endl;
	cout<<"3. List Warehouses"<<endl;
	cout<<"4. List Stores"<<endl;
	cout<<"5. Attach Store to Warehouse"<<endl;
	cout<<"6. Remove Store from Warehouse"<<endl;
	cout<<"7. Add ten iPhones 11 to Warehouse"<<endl;
	cout<<"8. Add ten Bananas to Warehouse"<<endl;
	cout<<"9. List Items in Warehouse"<<endl;
	cout<<"10. List Items in Store"<<endl;
	cout<<"11. Order Items from Warehouse"<<endl;
	cout<<"12. Check Warranty"<<endl;
	cout<<"**************************************"<<endl;
	cout<<"**************************************"<<endl;
	cout<<"**************************************"<<endl;
}
int main()
{
    // // FoodSpecs food1("apple", 69, 2, 3.5,"01/01/2020", 50, Weight_unit::kilogram);
    // ItemSpecs* ispec = new FoodSpecs("apple", 69, 2, 3.5,"01/01/2020", 50, Weight_unit::kilogram);
    // ItemFactory fac_obj;
    // Items* fooditem = fac_obj.createItem("Food",ispec);

    // ItemSpecs* ispec2 = new ClothesSpecs("shirt", 12, 10, 15, Gender::male);
    // Items* shirtitem = fac_obj.createItem("Clothes",ispec2);

    // ItemSpecs* ispec3 = new ItemSpecs("iPhone11", 13, 10, 799);
    // Items* phoneitem = fac_obj.createItem("Electronic",ispec3);

    // Warehouse w1; // Make warehouse w/ ID = 1
    // Store s1(1,&w1);
    // cout<<"LIST OF WAREHOUSE BEFORE ADDING ITEMS"<<endl;
    // w1.print();
    // cout<<endl;
    // cout<<"LIST OF STORES BEFORE ADDING ITEMS"<<endl;
    // s1.print();
    // cout<<endl;
    // w1.add_item(fooditem);
    // w1.add_item(shirtitem);
    // cout<<"LIST OF WAREHOUSE AFTER ADDING ITEMS"<<endl;
    // w1.print();
    // cout<<endl;
    // cout<<"LIST OF STORES AFTER ADDING ITEMS"<<endl;
    // s1.print();
    // cout<<endl;

    // s1.order(shirtitem,2);
    // cout<<"LIST OF WAREHOUSE AFTER SELLING 2 SHIRTS"<<endl;
    // w1.print();
    // cout<<endl;
    // cout<<"LIST OF STORES AFTER SELLING 2 SHIRTS"<<endl;
    // s1.print();
    // cout<<endl;

    // s1.order(shirtitem,10);

    // w1.evict(&s1);

    // w1.add_item(phoneitem);
    // cout<<"LIST OF WAREHOUSE AFTER EVICTING STORE1"<<endl;
    // w1.print();
    // cout<<endl;
    // cout<<"LIST OF STORES AFTER EVICTING STORE1"<<endl;
    // s1.print();
    // cout<<endl;

    

    // w1.add_item(x)

    // s1




    int option;
    int warehouse_id_cnt = 1;
    int store_id_cnt = 1;
    int item_id_cnt = 1;
    vector<Warehouse*> warehouse_vec;
    vector<Store*> store_vec;
    ItemFactory fac_obj;

	warehouse_vec.push_back(new Warehouse(warehouse_id_cnt++,"WareHouse1"));
	store_vec.push_back(new Store(store_id_cnt++,"Store1"));   

    while(1){
    	printMenu();
    	cout<<"Menu Option: ";
    	cin>>option;
    	cout<<endl;
    	if(option==1){//1. Add Warehouse
    		string temp;
    		cout<<"Warehouse Name: ";
    		cin>>temp;
    		warehouse_vec.push_back(new Warehouse(warehouse_id_cnt++,temp));
    	}
    	else if(option==2){// 2.Add Store
    		string temp;
    		cout<<"Store Name: ";
    		cin>>temp;
    		store_vec.push_back(new Store(store_id_cnt++,temp));
    	}
    	else if(option==3){// 3. List Warehouses
    		cout<<"Warehouse List: "<<endl;
    		int counter = 1;
    		for(Warehouse* warehouse: warehouse_vec){
    			cout<<counter++<<". ";
    			cout<<"Warehouse ID: "<<warehouse->getID()<<" Warehouse Name: "<<warehouse->getName()<<endl;
    		}
    	}
    	else if(option==4){// 4. List Stores
    		cout<<"Store List: "<<endl;
    		int counter = 1;
    		for(Store* store: store_vec){
    			cout<<counter++<<". ";
    			cout<<"Store ID: "<<store->getID()<<" Store Name: "<<store->getName()<<endl;
    		}

    	}
    	else if(option==5){// Attach/Register Observer
    		int w_index;
			cout<<"Enter Warehouse Index: ";
			cin>>w_index;
			int s_index;
			cout<<"Enter Store Index: ";
			cin>>s_index;
			if(w_index <= 0 || w_index > warehouse_vec.size()){
				cout<<"ERROR! Invalid Warehouse Index"<<endl;
			}
			else if(s_index <= 0 || s_index > store_vec.size()){
				cout<<"ERROR! Invalid Store Index"<<endl;
			}
			else{
				w_index -= 1; s_index -= 1;
				store_vec[s_index]->attach(warehouse_vec[w_index]);
				warehouse_vec[w_index]->attach(store_vec[s_index]);
			}
    	}
    	else if(option==6){//Remove
    		int w_index;
			cout<<"Enter Warehouse Index: ";
			cin>>w_index;
			int s_index;
			cout<<"Enter Store Index: ";
			cin>>s_index;
			if(w_index <= 0 || w_index > warehouse_vec.size()){
				cout<<"ERROR! Invalid Warehouse Index"<<endl;
			}
			else if(s_index <= 0 || s_index > store_vec.size()){
				cout<<"ERROR! Invalid Store Index"<<endl;
			}
			else{
				w_index -= 1; s_index -= 1;
				store_vec[s_index]->unattach();
				warehouse_vec[w_index]->evict(store_vec[s_index]);
			}
    	}
    	else if(option==7){//add iphones
			int temp_index;
			cout<<"Enter Warehouse Index: ";
			cin>>temp_index;
			if(temp_index > 0 && temp_index <= warehouse_vec.size()){
				temp_index -= 1;
				ItemSpecs* iphonespec = new ItemSpecs("iPhone11", item_id_cnt++, 10, 799);
		    	Items* phoneitem = fac_obj.createItem("Electronic",iphonespec);
		    	warehouse_vec[temp_index]->add_item(phoneitem);
			}
			else{
				cout<<"ERROR! Invalid Warehouse Index"<<endl;
			}
    	}
    	else if(option==9){//list items in warehouse
    		int temp_index;
			cout<<"Enter Warehouse Index: ";
			cin>>temp_index;
			cout<<endl;
			if(temp_index > 0 && temp_index <= warehouse_vec.size()){
				temp_index -= 1;
				warehouse_vec[temp_index]->print();
			}
			else{
				cout<<"ERROR! Invalid Warehouse Index"<<endl;
			}
    	}
    	else if(option==10){//list items in store
			int temp_index;
			cout<<"Enter Store Index: ";
			cin>>temp_index;
			cout<<endl;
			if(temp_index > 0 && temp_index <= store_vec.size()){
				temp_index -= 1;
				store_vec[temp_index]->print();
			}
			else{
				cout<<"ERROR! Invalid Store Index"<<endl;
			}
    	}
    	else if(option==11){//order from warehouse
    		int w_index;
			cout<<"Enter Warehouse Index: ";
			cin>>w_index;
			int i_index;
			cout<<"Enter Item Index: ";
			cin>>i_index;
			int amt;
			cout<<"Enter Item Amount: ";
			cin>>amt;
			if(w_index > 0 && w_index <= warehouse_vec.size()){
				w_index -= 1;
				i_index -= 1;
				warehouse_vec[w_index]->sell_item(i_index,amt);
			}
			else{
				cout<<"ERROR! Invalid Warehouse Index"<<endl;
			}
    	}
    	else if(option==12){//check warranty
    		int w_index;
			cout<<"Enter Warehouse Index: ";
			cin>>w_index;
			int i_index;
			cout<<"Enter Item Index: ";
			cin>>i_index;
			if(w_index > 0 && w_index <= warehouse_vec.size()){
				w_index -= 1;
				i_index -= 1;
				warehouse_vec[w_index]->perform_return(i_index);
			}
			else{
				cout<<"ERROR! Invalid Warehouse Index"<<endl;
			}

    	}
    	else if(option==8){//add bananas
    		int temp_index;
			cout<<"Enter Warehouse Index: ";
			cin>>temp_index;
			if(temp_index > 0 && temp_index <= warehouse_vec.size()){
				temp_index -= 1;
    			ItemSpecs* banana_spec = new FoodSpecs("Bananas", item_id_cnt, 10, 3.59,"01/01/2020", 50, Weight_unit::gram);
		    	Items* bananas = fac_obj.createItem("Food",banana_spec);
		    	warehouse_vec[temp_index]->add_item(bananas);
			}
			else{
				cout<<"ERROR! Invalid Warehouse Index"<<endl;
			}
    	}
    	else{
    		cout<<"INVALID OPTION!"<<endl;
    		break;
    	}
    	cout<<endl;

    }


    return 0;
}