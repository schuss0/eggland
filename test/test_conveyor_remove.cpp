#include<iostream>
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

  {
    Conveyor vey;
    vey.remove(Tray());
    cout << "Attempted removal from empty conveyor. Should still be empty:" << endl << vey << endl << endl;
  }

  {
    Conveyor vey;
    vey.attach_back(new Tray);
    vey.remove(Tray());
    cout << "Removed only tray from conveyor. Should be empty:" << endl << vey << endl << endl;
    cout << "Now adding back a tray..." << endl;
    Tray* tp=new Tray;
    tp->place_back(jumbo);
    vey.attach_front(tp);
    cout << vey << endl << endl;
  }
  {
    Conveyor vey;
    Tray* tp;
    for(int i=0; i<5; ++i)
    {
      tp=new Tray;
      tp->place_back(small);
      tp->place_back(small);
      if(i<=3)//last one will be used outside loop
        vey.attach_back(tp);

    }
    cout << "Removing four identical trays from conveyor...";cout.flush();
    vey.remove(*tp);
    delete tp;
    cout << "should now be empty:" << endl << vey << endl << endl;
    tp=new Tray;tp->place_back(medium);tp->place_back(medium);
    vey.attach_back(tp);
    tp=new Tray;tp->place_back(large);tp->place_back(large);
    vey.attach_front(tp);
    cout << "Reattached two trays. Should now have two:" << endl << vey << endl << endl;
  }
  {
    Conveyor vey;
    Tray* tp;
    for(int i=0; i<3; ++i)
    {
      tp=new Tray;
      tp->place_back(small);
      tp->place_back(small);
      vey.attach_back(tp);
    }
    tp=new Tray;
    vey.attach_back(tp);
    cout << "Removing last of 4 trays from conveyor...";cout.flush();
    vey.remove(Tray());
    cout << "should now have 3 identical trays remaining:" << endl << vey << endl << endl;
  }

  return 0;
}
