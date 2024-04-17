#ifndef EGG_H
#define EGG_H

#include <iostream>

class Egg {
private:
    float weight = 0.0;
    
public:
    Egg();
    Egg(float w);
    char wtcl;
    friend std::ostream& operator<<(std::ostream& os, const Egg& rhs);
    friend bool operator==(const Egg& lhs, const Egg& rhs); // Declaration 
    bool operator<(const Egg& rhs);
};

#endif // EGG_H
