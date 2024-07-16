//
// Created by zacka on 7/15/2024.
//

#ifndef LUXURYTAX_H
#define LUXURYTAX_H
#include "Space.h"


class LuxuryTax : public Space {
public:
    LuxuryTax();
    bool payTaxes(Player* taxPayer);
};



#endif //LUXURYTAX_H
