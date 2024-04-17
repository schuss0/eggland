//Tray.cpp
#include "Tray.h"
using namespace std;
#include <vector>

Tray::Tray() : capacity(2), current_number_of_eggs(0), carton(new Egg[2]) {}

Tray::~Tray() {
    delete[] carton;
}

void Tray::place_back(Egg newegg) {
    if (capacity == current_number_of_eggs) {
        Egg* tempPtr = new Egg[capacity + 2];
        capacity += 2;
        
        for (int i = 0; i < current_number_of_eggs; i++) {
            tempPtr[i] = carton[i];
        }

        delete[] carton;
        carton = tempPtr;
    }

    carton[current_number_of_eggs] = newegg;
    ++current_number_of_eggs;
    
}

ostream& operator<<(ostream& os, const Tray& rhs) {
    os << "+---+\n";

    for (int i = 0; i < rhs.capacity; ++i) {
        if (i != 0)
            os << "|-+-|\n";
        os << "|";

        if (i < rhs.current_number_of_eggs) {
            os << rhs.carton[i];
        } else {
            os << " ";
        }

        os << "|";

        if ((i + 1) < rhs.current_number_of_eggs) {
            os << rhs.carton[i + 1];
        } else {
            os << " ";
        }

        os << "|\n";
        ++i;
    }

    os << "+---+\n";

    return os;
}

bool operator==(const Tray& lhs, const Tray& rhs) {

  int rhseggct[7] = {0,0,0,0,0,0,0};//CHANGED
  int lhseggct[7] = {0,0,0,0,0,0,0};//CHANGED
  if(lhs.current_number_of_eggs!=rhs.current_number_of_eggs){
    return false;
  }

  for(int i = 0; i<rhs.current_number_of_eggs; i++){
    if(rhs.carton[i] == 'E') {rhseggct[0]++;}
    else if(rhs.carton[i].wtcl == '.') {rhseggct[1]++;}
    else if(rhs.carton[i].wtcl == '*') {rhseggct[2]++;}
    else if(rhs.carton[i].wtcl == 'o') {rhseggct[3]++;}
    else if(rhs.carton[i].wtcl == 'O') {rhseggct[4]++;}
    else if(rhs.carton[i].wtcl == '0') {rhseggct[5]++;}
    else if(rhs.carton[i].wtcl == '@') {rhseggct[6]++;}

    if(lhs.carton[i] == 'E') {lhseggct[0]++;}
    else if(lhs.carton[i].wtcl == '.') {lhseggct[1]++;}
    else if(lhs.carton[i].wtcl == '*') {lhseggct[2]++;}
    else if(lhs.carton[i].wtcl == 'o') {lhseggct[3]++;}
    else if(lhs.carton[i].wtcl == 'O') {lhseggct[4]++;}
    else if(lhs.carton[i].wtcl == '0') {lhseggct[5]++;}
    else if(lhs.carton[i].wtcl == '@') {lhseggct[6]++;}


  }
  //COMPARISON FOR EQUALITY CHANGED
  for(int i=0; i<7; ++i)
    if(lhseggct[i]!=rhseggct[i])
      return false;
  return true;

}


void Tray :: place_front (Egg e)
{
    if (capacity == current_number_of_eggs)
    {
        Egg* tempPtr = new Egg[capacity + 2];
        capacity += 2;

        for (int i = 0;i < current_number_of_eggs; ++i)
        {
           tempPtr [i + 1 ] = carton [i];
        }

        delete [] carton;

        carton = tempPtr;
    }
    else
    {
        for (int i = current_number_of_eggs; i > 0; --i)
        {
            carton [i] = carton [i - 1];
        }
    }

    carton [0] = e;

    ++current_number_of_eggs;
}

void Tray :: remove(Egg e) {
for (int i = 0; i < current_number_of_eggs; ++i) {
        if (carton[i] == e) {
            for (int j = i; j < current_number_of_eggs - 1; ++j) {
                carton[j] = carton[j + 1];
            }
            --current_number_of_eggs;
            --i; // Adjust index as an element is removed
        }
    }
}

bool Tray::take_back(Egg& e){
    if(current_number_of_eggs == 0){
        return false;
    }

    else{
        
        e = carton[current_number_of_eggs-1];
        current_number_of_eggs--;
        return true;
    }
     

}










