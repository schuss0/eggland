#include <iostream>
#include "Tray.h"
#ifndef CONVEYOR_H
#define CONVEYOR_H
using namespace std;



class Conveyor{

private:

struct Harness{

    Harness(Tray* pl, Harness* nx);
    ~Harness();

    

    Tray* payload;
    Harness* next;



};

Harness* head;
Harness* tail;

public:

Conveyor(); // Constructor declaration
~Conveyor(); // Destructor declaration

void attach_front(Tray* tray_ptr);

void attach_back(Tray* tray_ptr);

friend ostream& operator<<(ostream& os, const Conveyor& rhs);

friend ostream& operator<<(ostream& os, const Conveyor::Harness& rhs);


void remove(const Tray& trays_like_me);

};


#endif // CONNVEYOR_H