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
    std::vector<int> array;
    void resizeForLargerIndex(int *index);

private:
};


#endif //HASHES_HASH_H
