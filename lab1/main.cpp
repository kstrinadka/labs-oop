//#include <iostream>
#include "TritSet.h"

int main() {
    int test_int_for_trit = 0;
    mylab1::TritSet tritset(15);
   // std::cout << "Size = " << tritset.GetVectorSize() << std::endl;
   // std::cout  << "element = " << tritset.GetVectorElement(0) << std::endl;

    tritset.setTrit(18, mylab1::TRUE);
    //std::cout << "Size = " << tritset.GetVectorSize() << std::endl;
    //std::cout  << "element = " << tritset.GetVectorElement(1) << std::endl;

    //tritset.print(1);
    //std::cout << std::endl << tritset.GetVectorElement(1) << std::endl;

    tritset.setTrit(19, mylab1::FALSE);

    //tritset.print(1);


    /*mylab1::Trit trit = tritset.getTrit(18);
    if (trit == mylab1::TRUE) {
        std::cout << "TRUE" << std::endl;
    } else
    if (trit == mylab1::FALSE) {
        std::cout << "FALSE" << std::endl;
    } else
    if (trit == mylab1::UNKNOWN) {
        std::cout << "UNKNOWN" << std::endl;
    } else {
        std::cout << "shit" << std::endl;
        std::cout << trit << std::endl;
    }

    mylab1::Trit trit2 = tritset.getTrit(19);
    if (trit2 == mylab1::TRUE) {
        std::cout << "TRUE" << std::endl;
    } else
    if (trit2 == mylab1::FALSE) {
        std::cout << "FALSE" << std::endl;
    } else
    if (trit2 == mylab1::UNKNOWN) {
        std::cout << "UNKNOWN" << std::endl;
    } else {
        std::cout << "shit" << std::endl;
        std::cout << trit << std::endl;
    }*/

    tritset[18] = tritset[19];
    //int n = mylab1::Trit::TRUE;
    //int x = tritset[18];

    std::cout << (tritset[18])<< std::endl;
    std::cout << tritset[19]<< std::endl;
    std::cout << tritset[20]<< std::endl;

    return 0;
}
