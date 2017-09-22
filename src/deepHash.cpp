//
// Created by glenn on 9/19/2017.
//

#include "deepHash.h"
#include "core.h"

deepHash::deepHash(int size) {
    this->array = std::vector<linkedListItem*>(size);
    this->occupiedIndices = {};
}

bool deepHash::indexIsOccupied(int index) {
//    return (this->array[index]->value != "");
    return (this->array[index] != nullptr);
}

void deepHash::insertOrLink(linkedListItem *item, int *index, std::string *key, std::string *value) {
    if (deepHash::indexIsOccupied(*index)) {
        std::cout << "DEEPHASH: " << std::endl;
        printStar(3);
        std::cout << "index " << *index << " is full. Linking to occupant." << std::endl;
        linkedListItem *occupant = deepHash::findLastInLinkedList((this->array)[(*index)]);
        item->key = *key;
        item->value = *value;
        deepHash::linkItemToOccupant(item, occupant);
        std::cout << "occupant " << occupant->key << "-" << occupant->value << " is now linked to "
                  << occupant->next->key << "-" << occupant->next->value << std::endl;
    } else {
        printStar(3);
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

bool deepHash::resize() {
    bool didResize = false;
    // copy contents into arrayCopy
    // null the array
    // resize the array
    // place contents back into new Array
    return didResize;
}

bool deepHash::checkToResize() {

    return false;
}
