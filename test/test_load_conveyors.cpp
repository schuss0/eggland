#include<iostream>
#include<cassert>
#include "Conveyor.h"
#include "factory_utils.h"
#include "factory_utils.h"
using namespace std;

int main()
{
  vector<Conveyor*> assembly_line;
  //fill up assembly_line with conveyors from stdin
  load_conveyors(assembly_line);

  //print each conveyor followed by two blank lines
  for(Conveyor* convey : assembly_line)
    cout << *convey << "\n\n";

  //release the memory allocated in load_conveyors()
  for(Conveyor* convey : assembly_line)
    delete convey;
}

