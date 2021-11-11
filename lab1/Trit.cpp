//
// Created by Kirill on 18.10.2021.
//

#include "Trit.h"

namespace mylab1 {


    //Перегрузка '~'
    Trit operator~(Trit trit) {
        if (trit == TRUE) return FALSE;
        else if (trit == FALSE) return TRUE;
        else return UNKNOWN;

    }

//Перегрузка '&'
    Trit operator& (Trit trit_1, Trit trit_2) {
        if (trit_1 == FALSE || trit_2 == FALSE) return FALSE;
        else if (trit_1 == UNKNOWN || trit_2 == UNKNOWN) return UNKNOWN;
        else return  TRUE;
    }

//Перегрузка '|'
    Trit operator| (Trit trit_1, Trit trit_2) {
        if (trit_1 == TRUE || trit_2 == TRUE) return TRUE;
        else if (trit_1 == UNKNOWN || trit_2 == UNKNOWN) return UNKNOWN;
        else return FALSE;
    }


}

