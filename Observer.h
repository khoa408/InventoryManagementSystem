// #ifndef OBSERVER_H_
// #define OBSERVER_H_

// #include <iostream>
// #include <vector>
// #include <iterator>
// #include "Items.h"
// #include "Warehouse.h"
// // #include "Subject.h"
// using namespace std;
// class Observer {
//     // 2. "dependent" functionality
//    //Subject *subject;
//     //Subject *subject;
//   public:
//     /*Observer(Subject* sub) {
//         cout<<"obsr construc checker"<<endl;
//         subject = sub;
//         subject->attach(this);
//     }*/
//     virtual void update(vector<Items*> vec) = 0;
//     virtual void update(Warehouse * warehouse,vector<Items*> vec) = 0;
//   /*protected:
//     Subject *getSubject() {
//         return subject;
//     }*/
// };
// class Subject {
//   // protected:
//   //   vector<class Observer *>views; 
//   public:
//     // virtual Subject()=default;
//     // virtual ~Subject()=default;
//     // void attach(Observer *obs) {
//     //     views.push_back(obs);
//     // }
//     virtual void attach(Observer *obs) = 0;
//     virtual void notify() = 0;
//     virtual void evict(Observer *obs) = 0;
// };

// #endif
#ifndef OBSERVER_H_
#define OBSERVER_H_

#include <iostream>
#include <vector>
#include <iterator>
#include "Items.h"
// #include "Subject.h"
using namespace std;
class Observer {
    // 2. "dependent" functionality
   //Subject *subject;
    //Subject *subject;
  public:
    /*Observer(Subject* sub) {
        cout<<"obsr construc checker"<<endl;
        subject = sub;
        subject->attach(this);
    }*/
    virtual void update(vector<Items*> vec) = 0;
  /*protected:
    Subject *getSubject() {
        return subject;
    }*/
};
class Subject {
  // protected:
  //   vector<class Observer *>views; 
  public:
    // virtual Subject()=default;
    // virtual ~Subject()=default;
    // void attach(Observer *obs) {
    //     views.push_back(obs);
    // }
    virtual void attach(Observer *obs) = 0;
    virtual void notify() = 0;
    virtual void evict(Observer *obs) = 0;
};

#endif
