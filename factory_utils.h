#include <iostream>
#include "Conveyor.h"
#ifndef FACTORY_UTILS_H
#define FACTORY_UTILS_H

void load_conveyors(std::vector<Conveyor*>& assembly_line);

std::string vertical_report(const std::vector<Conveyor*>& assembly_line);



string basic_report(const std::vector<Conveyor*>& assembly_line);

string horizontal_report(const vector<Conveyor*>& assembly_line);

#endif // FACTORY_UTILS_H
