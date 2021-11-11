//
// Created by Kirill on 18.10.2021.
//
/*
 * FALSE = -1 = {0,1} or {1,0}
 * UNKNOWN = 0 = {0,0}
 * TRUE = 1 = {1,1}
 *
 */

#ifndef LAB1_TRIT_H
#define LAB1_TRIT_H

#include <iostream>

namespace mylab1 {

    enum Trit {
        FALSE = 1,
        UNKNOWN = 0,
        TRUE = 3
    };

    Trit operator~(Trit trit_1);
    Trit operator&(Trit trit_1, Trit trit_2);
    Trit operator|(Trit trit_1, Trit trit_2);


}




#endif //LAB1_TRIT_H
