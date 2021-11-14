//
// Created by Kirill on 18.10.2021.
//

#include "TritSet.h"

namespace mylab1 {
    int INT_SIZE = 31;  // 0...31 - quantity of bits in integer
    int TRITS_PER_INT = 15;


    TritSet::TritSet(int count_of_trits) {
        //this->test_int_for_trits = 0;
        values.resize(count_of_trits/16 + 1); //выделяю нужное кол-во ячеек
        for (int i=0; i<values.size(); ++i) {
            values[i] = 0;
        }
    }


    // используется в сеттере
    void TritSet::trit_to_array(int *trit_array, Trit trit) {
        if (trit == FALSE) {
            trit_array[0] = 0;
            trit_array[1] = 1;
        }
        if (trit == TRUE) {
            trit_array[0] = 1;
            trit_array[1] = 1;
        }
        if (trit == UNKNOWN) {
            trit_array[0] = 0;
            trit_array[1] = 0;
        }
    }


    //вывод инта по тритам
    void TritSet::print(int element_of_vector) {
        int number = values[element_of_vector];

        int counter = 0;
        int bit_array[32] = {0};

        int i = 31;
        while (i >= 0) {
            counter += 1;
            // будем выводить по 2 для наглядности
            if (number & (1 << i)) {
                bit_array[31-i] = 1;
                std::cout << 1; // выводим все биты инта
            } else {
                bit_array[31-i] = 0;
                std::cout << 0;
            }
            i -= 1;
            if (number & (1 << i)) {
                bit_array[31-i] = 1;
                std::cout << 1 << ' '; // выводим все биты инта
            } else {
                bit_array[31-i] = 0;
                std::cout << 0 << ' ';
            }
            i -= 1;
        }

        std::cout << std::endl << counter << std::endl;
        for (int i=0; i<32; ++i) {
            std::cout << bit_array[i];
        }
    }


    // Для изменения конкретного трита
    void TritSet::save_trit_to_posision(int &cell_in_vector,
                                        unsigned current_trit, Trit trit) {

        //сделаем массив из 2-х элементов - перый и второй бит трита
        int trit_array[2] = {0};
        trit_to_array(trit_array, trit);

        //места в инте для первого и второго трита
        unsigned FIRST_TRIT_PLACE = INT_SIZE - (current_trit*2);
        unsigned SECOND_TRIT_PLACE = INT_SIZE - (current_trit*2 + 1);

        // изменяем нужный трит на поступивший трит
        if (trit_array[0] == 1) {
            cell_in_vector |= (1 << FIRST_TRIT_PLACE);
        }
        if (trit_array[1] == 1) {
            cell_in_vector |= (1 << SECOND_TRIT_PLACE);
        }
        if (trit_array[0] == 0) {
            cell_in_vector &= ~(1 << FIRST_TRIT_PLACE);
        }
        if (trit_array[1] == 0) {
            cell_in_vector &= ~(1 << SECOND_TRIT_PLACE);
        }
    }


    unsigned TritSet::mask_for_trit(unsigned index) const {
        unsigned FIRST_TRIT_PLACE = INT_SIZE - (index*2);
        unsigned SECOND_TRIT_PLACE = INT_SIZE - (index*2 + 1);
        unsigned mask = 0;
        mask |= (1 << FIRST_TRIT_PLACE);
        mask |= (1 << SECOND_TRIT_PLACE);
        //std::cout << std::endl << "mask = " << mask << std::endl;
        return mask;
    }


    void TritSet::setTrit(size_t index, Trit trit) {
        //запись UNKNOWN не должна приводить к выделению памяти
        if (trit == UNKNOWN && values.size()*16 < index) {
            return;
        }

        unsigned current_element = index / 16;   //элементв в векторе
        unsigned current_trit = index % 16;    //трит в элементе

        //добавить элементов в вектор, если не хватает
        if (values.size()*16 <= index) {
            int n = this->values.size();
            values.resize(current_element + 1); //выделяю нужное кол-во ячеек
            for (int i=n; i<values.size(); ++i) {
                values[i] = 0;
            }
        }

        save_trit_to_posision(values[current_element], current_trit, trit);

        /*if (values.size()*TRITS_PER_INT > index || trit != Trit::UNKNOWN) {
            // изменяем нужный трит на поступивший трит

        }*/
    }

    Trit TritSet::getTrit(size_t index) const {
        unsigned current_element = index / 16;   //элементв в векторе
        unsigned current_trit = index % 16;    //трит в элементе

        if (values.size()*16 <= index) {
            return UNKNOWN;
        }

        else {
            // изменяем нужный трит на поступивший трит
            return get_trit_from_posision(values[current_element], current_trit);
        }
    }

    Trit TritSet::get_trit_from_posision(int const &cell_in_vector, unsigned current_trit) const{
        unsigned mask = mask_for_trit(current_trit); //создаем маску под нужный трит
        unsigned shift = 32 - 2*current_trit - 2;
        uint32_t trit_value = ((uint32_t) cell_in_vector & mask) >> shift;
        //std::cout << std::endl << "trit_value = " << trit_value << std::endl;
        Trit trit = (Trit)trit_value;
        return trit;
    }


    TritSet::Refference TritSet::operator[](const size_t &index) {
        return Refference(this, index);
    }

    Trit TritSet::operator[](const size_t &index) const {
        return TritSet::getTrit(index);
    }

    TritSet TritSet::operator&(const TritSet &other) const {
        // создание нового тритсета нужного размера
        int new_size = other.values.size();
        if (this->values.size() >= other.values.size()) {
            new_size = this->values.size();
        }
        TritSet newTritSet(new_size);

        for (int i = 0; i < new_size; i++){
            newTritSet[i] = (*this)[i] & other[i];
        }
        return newTritSet;
    }

    TritSet TritSet::operator|(const TritSet& other) const{
        // создание нового тритсета нужного размера
        int new_size = other.values.size();
        if (this->values.size() >= other.values.size()) {
            new_size = this->values.size();
        }
        TritSet newTritSet(new_size);

        for (int i = 0; i < new_size; i++){
            newTritSet[i] = (*this)[i] | other[i];
        }
        return newTritSet;
    }

    TritSet TritSet::operator~() const{
        TritSet newTritSet(this->values.size());
        for (int i = 0; i < this->values.size(); i++){
            newTritSet[i] = ~(*this)[i];
        }
        return newTritSet;
    }

    TritSet &TritSet::operator=(const TritSet &other) {
        values.clear();
        values = other.values;
        return *this;
    }

    int TritSet::getSize() {
        return values.size()*16;
    }

    void TritSet::shrink() {

        int size_of_new_vector = 0;

        for (int i = (this->values.size() * 16) - 1; i >= 0; --i) {

            if ((*this)[i] != UNKNOWN) {
                // тут надо уменьшить вектор до нужного размера

                /*std::cout << "trit[" << i << "] = " << (*this)[i] << std::endl;
                std::cout << "trit[" << i+1 << "] = " << (*this)[i+1] << std::endl;
                std::cout << "i = " << i << std::endl;*/
                size_of_new_vector = (i / 16) + 1;      //типо выбираем нужное количество ячеек в векторе
                break;
            }

        }

        this->values.resize(size_of_new_vector);
    }

    size_t TritSet::cardinality(Trit value) {
        int number = 0;
        for (int i = 0; i < this->values.size()*16; ++i) {
            if ((*this)[i] == value) {
                number++;
            }
        }
        return number;
    }

    std::unordered_map<Trit, int, std::hash<int> > TritSet::cardinality() {
        std::unordered_map <Trit, int, std::hash<int> > my_map;
        my_map[TRUE] = cardinality(TRUE);
        my_map[FALSE] = cardinality(FALSE);
        my_map[UNKNOWN] = cardinality(UNKNOWN);
        return my_map;
    }

    void TritSet::trim(size_t lastIndex) {

        this->values.resize((lastIndex)/16 + 1);

        for (int i = lastIndex; i < this->values.size() * 16; ++i) {
            (*this)[i] = UNKNOWN;
        }
    }


    TritSet::Refference &TritSet::Refference::operator=(Trit new_trit) {

        //std::cout << "operator = for trit with index:"<< _index << std::endl;

        proxy_triset->setTrit(_index, new_trit);
        return *this;
    }

    TritSet::Refference &TritSet::Refference::operator=(TritSet::Refference new_trit) {

        //std::cout << "operator = for trit with index:"<< _index << std::endl;
        // достаю нужный трит из rvalue
        proxy_triset->setTrit(_index, new_trit.proxy_triset->getTrit(new_trit._index));
        return *this;
    }

    // перегрузка для вывода трита в std::cout
    std::ostream &operator<<(std::ostream &out, const Trit &trit) {
        if (trit == UNKNOWN) {
            out << "UNKNOWN";
        } else if (trit == TRUE) {
            out << "TRUE";
        }
        else {
            out << "FALSE";
        }
        return out;
    }
}