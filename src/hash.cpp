//
// Created by glenn on 9/16/2017.
//

#include "hash.h"

hash::hash(int size) {
    this->array = std::vector<int>(size);
};

void hash::resizeForLargerIndex(int *index) {
    if (this->array.size() <= *index) {
        this->array.resize(*index + 1);
    }
    std::cout << "HASH::Expanded Size to << " << this->array.size() << std::endl;
}
