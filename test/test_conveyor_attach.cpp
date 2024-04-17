#include<iostream>
#include<cstring>
#include "Conveyor.h"

using namespace std;

#if __has_include("memory_replacement.h")
#include "memory_replacement.h"
#endif


int main()
{
  Egg smaller(1.24);
  Egg peewee(1.25);
  Egg small(1.5);
  Egg medium(1.75);
  Egg large(2.0);
  Egg xlarge(2.25);
  Egg jumbo(2.5);

  { //Conveyor with one empty tray
    Conveyor con;
    con.attach_back(new Tray);
    cout << "A converyor with an empty tray\n";
    cout << con << "\n\n";
  }

  { //Conveyor with three trays via attach_back
    Conveyor con;
    Tray* ptr=new Tray;
    ptr->place_back(smaller);
    ptr->place_back(peewee);
    ptr->place_back(small);
    ptr->place_back(medium);
    ptr->place_back(large);
    ptr->place_back(xlarge);
    ptr->place_back(jumbo);
    con.attach_back(ptr);

    ptr=new Tray;
    ptr->place_back(jumbo);
    ptr->place_back(medium);
    ptr->place_back(jumbo);
    ptr->place_back(jumbo);
    con.attach_back(ptr);

    ptr=new Tray;
    ptr->place_back(jumbo);
    ptr->place_back(medium);
    ptr->place_back(medium);
    ptr->place_back(medium);
    ptr->place_back(large);
    ptr->place_back(large);
    ptr->place_back(large);
    ptr->place_back(small);
    con.attach_back(ptr);

    cout << "\n\n\nThree trays on the Conveyor via Conveyor::attach_back\n" << con;
  }
  { //Conveyor with three trays via attach_front
    Conveyor con;
    Tray* ptr=new Tray;
    ptr->place_back(smaller);
    ptr->place_back(peewee);
    ptr->place_back(small);
    ptr->place_back(medium);
    ptr->place_back(large);
    ptr->place_back(xlarge);
    ptr->place_back(jumbo);
    con.attach_front(ptr);

    ptr=new Tray;
    ptr->place_back(jumbo);
    ptr->place_back(medium);
    ptr->place_back(jumbo);
    ptr->place_back(jumbo);
    con.attach_front(ptr);

    ptr=new Tray;
    ptr->place_back(jumbo);
    ptr->place_back(medium);
    ptr->place_back(medium);
    ptr->place_back(medium);
    ptr->place_back(large);
    ptr->place_back(large);
    ptr->place_back(large);
    ptr->place_back(small);
    con.attach_front(ptr);

    cout << "\n\n\nThree trays on the Conveyor via Conveyor::attach_front\n" << con;
  }

  return 0;
}
