//
// Created by glenn on 9/19/2017.
//

#include "deepHash.h"
#include "core.h"

deepHash::deepHash(int size) {
    this->array = std::vector<linkedListItem *>(size);
    this->arrayFlatCopy = {};
    this->occupiedIndices = {};
}

bool deepHash::indexIsOccupied(int index) {
//    return (this->array[index]->value != "");
    return (this->array[index] != nullptr);
}

void deepHash::insertOrLink(linkedListItem *item, int *index, std::string *key, std::string *value) {
    if (deepHash::indexIsOccupied(*index)) {
        std::cout << "DEEPHASH: " << std::endl;
        std::cout << "index " << *index << " is full. Linking to occupant." << std::endl;
        linkedListItem *occupant = deepHash::findLastInLinkedList((this->array)[(*index)]);
        item->key = *key;
        item->value = *value;
        deepHash::linkItemToOccupant(item, occupant);
        std::cout << "occupant " << occupant->key << "-" << occupant->value << " is now linked to "
                  << occupant->next->key << "-" << occupant->next->value << std::endl;
    } else {
        std::cout << "DEEPHASH: " << std::endl;
        std::cout << "index " << *index << " is empty. Filling" << std::endl;
        deepHash::addToEmptyIndex(item, key, value, index);
        this->occupiedIndices.push_back(*index);
    }

}

void deepHash::addToEmptyIndex(linkedListItem *item, std::string *key, std::string *value, int *index) {
    (*item).key = *key;
    (*item).value = *value;
    (*item).next = nullptr;
    this->array[(*index)] = item;
    std::cout << "Added to index " << *index << std::endl;
}

void deepHash::linkItemToOccupant(linkedListItem *item, linkedListItem *occupant) {
    occupant->next = item;
}

void deepHash::resizeForLargerIndex(int *index) {
    if (this->array.size() <= *index) {
        this->array.resize(*index + 1);
        std::cout << "HASH::Expanded Size to << " << this->array.size() << std::endl;
    }
}

linkedListItem *deepHash::findLastInLinkedList(linkedListItem *item) {
    linkedListItem *tempItem = item;
    while (tempItem->next != nullptr) {
        tempItem = tempItem->next;
    }
    return tempItem;
}

int deepHash::sumOfString(std::string key) {
    int stringSum = 0;
    int charValue = 0;
    int i = 0;
    while (key[i] != '\0') {
        charValue = (int) (char) key[i];
        stringSum += charValue;
        i++;
    }
    return stringSum;
}

linkedListItem *deepHash::findAtIndex(int index) {
    return this->array[index];
}

linkedListItem *deepHash::findItemWithValue(int index, std::string value) {
    linkedListItem *item = deepHash::findAtIndex(index);
    while (item->value != value) {
        item = item->next;
    }
    return item;
}

linkedListItem *deepHash::returnItem(std::string *key, std::string *value) {
    int sum = deepHash::sumOfString(*key);
    int index = deepHash::calcIndex(sum);
    return deepHash::findItemWithValue(index, *value);
}

int deepHash::calcIndex(int stringSum) {
    int size = this->array.size();
    return (stringSum % size);
}

void deepHash::resize(int newSize) {
    // copy the existing contents
    deepHash::transferArrayToCopy();
    // resize the array
    this->array.resize(newSize);
    // copy contents back into new Array
    deepHash::transferCopyToArray();
}

bool deepHash::checkToResize() {

    return false;
}

int deepHash::getDepthOfIndex(int index) {
    int i = 0;
    // start at the index passed-in
    // if this index is occupied
    if (this->array[index] != nullptr) {
        // give me a count of 1 for making it this far
        i++;
        // store a reference to the next item for this item
        linkedListItem *nextItem = this->array[index]->next;
        // if the next item exists
        while (nextItem != nullptr) {
            // count up for each time it's not empty
            i++;
            // over-write the next item reference, and continue down the chain
            nextItem = nextItem->next;
        }
    }
    return i;
}

void deepHash::transferArrayToCopy() {
    // search through each index of this->array
    this->arrayFlatCopy = {};
    for (int i = 0; i < this->array.size(); i++) {
        // for every index that's occupied
        if (this->array[i] != nullptr) {
            // copy the contents of the first item into the copy array
            this->arrayFlatCopy.push_back(this->array[i]);
            // while there's a "next" item referenced (it's not null)
            linkedListItem *nextItem = this->array[i]->next;
            while (nextItem != nullptr) {
                // dig down, and copy every next item into the copy array
                linkedListItem *holdNextItem = nextItem->next;
                // clear the next reference to your neighbor, since this is an artifact of the previous hash size
                nextItem->next = nullptr;
                this->arrayFlatCopy.push_back(nextItem);
                // set the next item to be the next of next :)
                nextItem = holdNextItem;
            }
            // clear the next reference for the current index
            this->array[i]->next = nullptr;
            this->occupiedIndices = {};
        }
    }
    // null the array
    this->array = {};
}

void deepHash::transferCopyToArray() {
    for (int i = 0; i < this->arrayFlatCopy.size(); i++) {
        int sum = deepHash::sumOfString(this->arrayFlatCopy[i]->key);
        int index = deepHash::calcIndex(sum);
        std::string *key = &(this->arrayFlatCopy[i]->key);
        std::string *value = &(this->arrayFlatCopy[i]->value);
        deepHash::insertOrLink(this->arrayFlatCopy[i], &index, key, value);
    }
    this->arrayFlatCopy = {};
}

int deepHash::indexOfItem(std::string *key, std::string *value) {
    int sum = deepHash::sumOfString(*key);
    int index = deepHash::calcIndex(sum);
    return index;
}
