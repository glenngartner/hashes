//
// Created by glenn on 9/19/2017.
//

#include "deepHash.h"

deepHash::deepHash(int size) {
    this->array = std::vector<linkedListItem>(size);
}

bool deepHash::indexIsOccupied(int index) {
    return (this->array[index].value != "");
}

void deepHash::insertOrLink(linkedListItem *item, int *index, std::string *key, std::string *value) {
    if (deepHash::indexIsOccupied(*index)) {
        std::cout << "DEEPHASH: " << std::endl;
        printStar(3);
        std::cout << "index " << *index << " is full. Linking to occupant." << std::endl;
        linkedListItem *occupant = deepHash::findLastInLinkedList(&(this->array)[(*index)]);
        item->key = *key;
        item->value = *value;
        deepHash::linkItemToOccupant(item, occupant);
        std::cout << "occupant " << occupant->key << " is now linked to " << occupant->next->key << std::endl;
    } else {
        printStar(3);
        std::cout << "index " << *index << " is empty. Filling" << std::endl;
        deepHash::addToEmptyIndex(item, key, value, index);
    }

}

void deepHash::addToEmptyIndex(linkedListItem *item, std::string *key, std::string *value, int *index) {
    (*item).key = *key;
    (*item).value = *value;
    (*item).next = nullptr;
    this->array[(*index)] = *item;
    std::cout << "Added to index " << *index << std::endl;
}

void deepHash::linkItemToOccupant(linkedListItem *item, linkedListItem *occupant) {
    occupant->next = item;
}

void deepHash::resizeForLargerIndex(int *index) {
    if (this->array.size() <= *index) {
        this->array.resize(*index + 1);
    }
    std::cout << "HASH::Expanded Size to << " << this->array.size() << std::endl;
}

linkedListItem * deepHash::findLastInLinkedList(linkedListItem *item) {
    linkedListItem *tempItem = item;
    while (tempItem->next != nullptr){
        tempItem = tempItem->next;
    }
    return tempItem;
}
