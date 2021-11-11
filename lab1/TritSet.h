//
// Created by Kirill on 18.10.2021.
//

#ifndef LAB1_TRITSET_H
#define LAB1_TRITSET_H


#include <vector>
#include "Trit.h"

namespace mylab1{




    class TritSet {
    private:
        // в каждом элементе вектора хранится по 16 тритов
        std::vector<int> values;

        //кол-во тритов
        //int trit_number;

        // попробую сюда несколько тритов записать
        int test_int_for_trits = 0;





        //
        void trit_to_array(int* trit_array, Trit trit);



        //
        void save_trit_to_posision(int &cell_in_vector,
                                   unsigned current_trit, Trit trit);

        //
        int GetRightElement (int trit_number);

        //занулить все биты, кроме нужного трита
        unsigned mask_for_trit(unsigned index) const;

    public:
        TritSet (int count_of_trits);

        //Устанавливает Trit в позицию size_t
        void setTrit(size_t index, Trit trit);

        Trit getTrit(size_t index) const ;

        class Refference {
        private:
            // указатель на нужный int в TritSet
            //int& _item;

            // номер трита в инте
            //int _number;

            size_t _index;    // индекс трита

            TritSet* proxy_triset;   //вроде это ссылка на тритсет с вектором с тритами

            Trit trit;

            //преобразовать ссылку в номер трита
            // &vector[0] - _item = number_of_elements  (кол-во заполненных элементов вектора)
            // number_of_elements = vector.size()
            //number_of_elements + _number = trit_number





        public:

            Refference(TritSet *tritset, size_t index) {
                this->proxy_triset = tritset;
                this->_index = index;
            }

            Refference(TritSet *tritset) {
                this->proxy_triset = tritset;
            }

            Refference& operator=(Trit trit);

            operator Trit() {
                return proxy_triset->getTrit(_index);
            }


        };

        void print(int element_of_vector);


        int GetVectorSize () {
            return values.size();
        }

        int GetVectorElement (int element_of_vector) {
            return values[element_of_vector];
        }

        Trit get_trit_from_posision (int const &cell_in_vector, unsigned index) const;


        Refference operator[](const size_t &index);

        Trit operator[](const size_t &index) const;

        TritSet &operator=(const TritSet& other);

        TritSet operator&(const TritSet& other) const;

    };

    // перегрузка для вывода трита в std::cout
    std::ostream& operator<< (std::ostream &out, const Trit &trit);

}



#endif //LAB1_TRITSET_H
