#include "Conveyor.h"
using namespace std;

Conveyor::Conveyor(): head(nullptr), tail(nullptr) {}

Conveyor::~Conveyor(){
   
   while (head != nullptr){
    Harness* next = head->next;
    delete head;
    head = next;
   }
   
}

Conveyor :: Harness :: Harness (Tray* pl, Harness* nx) : payload(pl), next(nx) {}

//Destructor for Harness struct
Conveyor :: Harness :: ~Harness()
{
    //releases memory allocated to payload
    delete payload; 
}

void Conveyor::attach_front(Tray* tray_ptr){


Harness* newHead = new Harness(tray_ptr, head);
    head = newHead;
    // if Conveyor is empty the tail and the head point to the same place
    if (tail == nullptr)
    {
        tail = head;
    }

}

void Conveyor::attach_back(Tray* tray_ptr){

if(tail == nullptr)
    {
        // the head and tail are null there is nothing on the Conveyor thus memory is newly allocated
        head = tail = new Harness(tray_ptr, nullptr);
    }
    else 
    {
        //if it is not the tail points to newly allocated memory
        tail -> next = new Harness (tray_ptr, nullptr);
        tail = tail -> next;
    }
}


ostream& operator<<(ostream& os, const Conveyor& rhs){


  // starts at the head
    Conveyor :: Harness* currHarness = rhs.head;
    os << "  |  " << endl;
    /*if (currHarness != nullptr)
    {
        // indicates the start of the conveyor
        os << "  |  " << endl;
    }*/
    
    //iterates through 
    while (currHarness != nullptr) 
    {
        os << *currHarness;
        currHarness = currHarness -> next;
    }
    
    return os;
}
  
  
  ostream& operator<<(ostream& os, const Conveyor::Harness& rhs)
{
  
  os << " / \\ " << endl;
  os << "/   \\" << endl;
  os << *rhs.payload;
  os << "\\   /" << endl;
  os << " \\ / " << endl;
  if(rhs.next == nullptr){
    os << "  S  " << endl;
  }
  else{
    os << "  $  " << endl;
  }

return os;
}  


void Conveyor::remove(const Tray& trays_like_me){
  
  Harness anchor(nullptr, head);
  Harness* current_suspect=&anchor;

  while(current_suspect->next != nullptr)
  {
    if(trays_like_me == *(current_suspect->next->payload))
    {
      Harness* guilty_as_charged=current_suspect->next;
      current_suspect->next = current_suspect->next->next;
      delete guilty_as_charged;
      
    }
    else current_suspect=current_suspect->next;
  }

  if(current_suspect == &anchor){
    head = nullptr;
    tail = nullptr;

  }
  else{
    tail = current_suspect;

    head = anchor.next;
  }

  
}