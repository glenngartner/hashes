//
// Created by glenn on 9/19/2017.
//

#include "deepHash.h"

deepHash::deepHash(int size) : hash(size) {
    this->array = std::vector<linkedListItem>(size);
}

bool deepHash::indexIsOccupied(int index) {
    return (this->array[index].value == "");
}

void deepHash::insertOrLink(linkedListItem *item, int *index, std::string *key, std::string *value) {
    if (deepHash::indexIsOccupied(*index)) {
        printStar(3);
        std::cout << "index " << *index << " is empty. Filling" << std::endl;
        deepHash::addToEmptyIndex(item, key, value, index);
    } else {
        std::cout << "DEEPHASH: " << std::endl;
        printStar(3);
        std::cout << "index " << *index << " is full. Linking to occupant." << std::endl;
        linkedListItem occupant = (this->array)[(*index)];
        item->key = *key;
        item->value = *value;
        deepHash::linkItemToOccupant(item, &occupant);
        std::cout << "occupant " << occupant.key << " is now linked to " << occupant.next->key << std::endl;
    }

}

void deepHash::addToEmptyIndex(linkedListItem *item, std::string *key, std::string *value, int *index) {
    (*item).key = *key;
    (*item).value = *value;
    this->array[(*index)] = *item;
    std::cout << "Added to index " << *index << std::endl;
}

void deepHash::linkItemToOccupant(linkedListItem *item, linkedListItem *occupant) {
    occupant->next = item;
}
