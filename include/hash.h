//
// Created by glenn on 9/16/2017.
//

#ifndef HASHES_HASH_H
#define HASHES_HASH_H

#include <iostream>
#include <vector>
#include "core.h"

class hash {
public:
    hash(int size);

    void resizeForLargerIndex(int *index);

    std::vector<int> array;
};


#endif //HASHES_HASH_H
