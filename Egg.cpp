#include "Egg.h"

Egg::Egg() : weight(0.0) {}

Egg::Egg(float w) : weight(w) {
    if (weight < 1.25) {
        wtcl = 'E';
    } else if (weight < 1.5) {
        wtcl = '.';
    } else if (weight < 1.75) {
        wtcl = '*';
    } else if (weight < 2) {
        wtcl = 'o';
    } else if (weight < 2.25) {
        wtcl = 'O';
    } else if (weight < 2.5) {
        wtcl = '0';
    } else if (weight >= 2.5) {
        wtcl = '@';
    }
}

std::ostream& operator<<(std::ostream& os, const Egg& rhs) {
    os << rhs.wtcl;
    return os;
}

bool operator==(const Egg& lhs, const Egg& rhs) {
    return (
        ((0.0 <= lhs.weight && lhs.weight < 1.25) && (0.0 <= rhs.weight && rhs.weight < 1.25)) ||
        ((1.25 <= lhs.weight && lhs.weight < 1.5) && (1.25 <= rhs.weight && rhs.weight < 1.5)) ||
        ((1.5 <= lhs.weight && lhs.weight < 1.75) && (1.5 <= rhs.weight && rhs.weight < 1.75)) ||
        ((1.75 <= lhs.weight && lhs.weight < 2) && (1.75 <= rhs.weight && rhs.weight < 2)) ||
        ((2 <= lhs.weight && lhs.weight < 2.25) && (2 <= rhs.weight && rhs.weight < 2.25)) ||
        ((2.25 <= lhs.weight && lhs.weight < 2.5) && (2.25 <= rhs.weight && rhs.weight < 2.5)) ||
        (lhs.weight >= 2.5 && rhs.weight >= 2.5)
    );
}

bool Egg::operator<(const Egg& rhs){
    const Egg& lhs = *this;
    if( lhs.weight != rhs.weight){

    if( lhs. weight < rhs.weight){
        return true;
    }
    else{
        return false;
    }
    }
    else{
        return false;
    }
}
