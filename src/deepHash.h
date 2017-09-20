//
// Created by glenn on 9/19/2017.
//

#include "hash.h"
#include "core.h"

#ifndef HASHES_DEEPHASH_H
#define HASHES_DEEPHASH_H


class deepHash : public hash {
public:
    deepHash(int size);
    std::vector<linkedListItem> array;
    bool indexIsOccupied(int index);
    void insertOrLink(linkedListItem *item, int *index, std::string *key, std::string *value);
    void addToEmptyIndex(linkedListItem *item, std::string *key, std::string *value, int *index);
    void linkItemToOccupant(linkedListItem *item, linkedListItem *occupant);
};


#endif //HASHES_DEEPHASH_H
