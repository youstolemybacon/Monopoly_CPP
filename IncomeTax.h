//
// Created by zacka on 7/15/2024.
//

#ifndef INCOMETAX_H
#define INCOMETAX_H
#include "Space.h"


class IncomeTax : public Space {
    IncomeTax();
    bool payTaxes(Player* taxPayer);
};



#endif //INCOMETAX_H