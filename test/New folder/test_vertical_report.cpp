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
  string report_content=vertical_report(assembly_line);

  //release the memory allocated in load_conveyors()
  for(Conveyor* convey : assembly_line)
    delete convey;

  cout << report_content;
  return 0;
}

