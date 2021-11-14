//#include <iostream>
#include "TritSet.h"

void print_all_trits (mylab1::TritSet tritSet, int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << "trit[" << i << "] = " << tritSet[i] << std::endl;
    }
}


int main() {
    int test_int_for_trit = 0;
    mylab1::TritSet tritset(15);






    //tritset.setTrit(18, mylab1::TRUE);


    //tritset.setTrit(19, mylab1::FALSE);


    /*for (int i = 0; i<512; ++i) {
        tritset[i] = mylab1::TRUE;
    }
    tritset[19] = mylab1::UNKNOWN;
    tritset[29] = mylab1::UNKNOWN;
    tritset[39] = mylab1::UNKNOWN;
    tritset[49] = mylab1::UNKNOWN;
    tritset[59] = mylab1::UNKNOWN;*/


    tritset[19] = mylab1::UNKNOWN;
    tritset[29] = mylab1::UNKNOWN;
    tritset[39] = mylab1::UNKNOWN;
    tritset[49] = mylab1::TRUE;
    tritset[512] = mylab1::TRUE;
    tritset[455] = mylab1::TRUE;

    std::cout << tritset.getSize() << std::endl;

    tritset.trim(450) ;

    std::cout << tritset.getSize() << std::endl;

    tritset.shrink();

    std::cout << tritset.getSize() << std::endl;


    //print_all_trits(tritset, 512);


    //tritset[19] = mylab1::UNKNOWN;

    //print_all_trits(tritset, 1000);





    return 0;
}
