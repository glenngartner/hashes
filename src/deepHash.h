//
// Created by glenn on 9/19/2017.
//

#include "hash.h"
#include "core.h"

#ifndef HASHES_DEEPHASH_H
#define HASHES_DEEPHASH_H


class deepHash {
public:
    deepHash(int size);

    bool indexIsOccupied(int index);

    void resizeForLargerIndex(int *index);

    void insertOrLink(linkedListItem *item, int *index, std::string *key, std::string *value);

    void addToEmptyIndex(linkedListItem *item, std::string *key, std::string *value, int *index);

    void linkItemToOccupant(linkedListItem *item, linkedListItem *occupant);

    linkedListItem *findLastInLinkedList(linkedListItem *item);

    linkedListItem *returnItem(std::string *key, std::string *value);

    int calcIndex(int stringSum);

private:
    std::vector<linkedListItem*> array;

    std::vector<linkedListItem> arrayFlatCopy;

    std::vector<int> occupiedIndices;

    int sumOfString(std::string key);

    linkedListItem *findAtIndex(int index);

    linkedListItem *findItemWithValue(int index, std::string value);

    bool checkToResize();

    bool resize();
};


#endif //HASHES_DEEPHASH_H
