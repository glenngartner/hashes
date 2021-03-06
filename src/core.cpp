//
// Created by glenn on 9/14/2017.
//

#include "core.h"
#include <iostream>
#include <vector>
#include <string>

void printCharsOfString(std::string key, int *inputValue, int *stringSum, bool printSum) {
    int i = 0;
    while (key[i] != '\0') {
        *inputValue = (int) (char) key[i];
        printStar(1);
        printf("%c = %i\n", key[i], *inputValue);
        *stringSum += *inputValue;
        i++;
    }
    if (printSum) {
        printStar(2);
        printf("The sum of your string is %i\n", *stringSum);
    }
}

//template<typename type, typename allocator>
//void resizeForLargerIndex(std::vector<type, allocator> *hash, int *stringSum) {
//    if ((*hash).size() <= *stringSum) { // if the hash size is smaller than the new value
//        (*hash).resize(*stringSum + 1); // resize the array to match the new value
//    }
//}

void resizeForLargerIndex(std::vector<simpleItem> *hash, int *stringSum) {
    if ((*hash).size() <= *stringSum) { // if the hash size is smaller than the new value
        (*hash).resize(*stringSum + 1); // resize the array to match the new value
//        puts("SIMPLEHASH::Expanded Size");
        std::cout  << "Expanded Size to " << hash->size() << std::endl;
    }
}

void resizeForLargerIndexL(std::vector<linkedListItem> *hash, int *stringSum) {
    if ((*hash).size() <= *stringSum) { // if the hash size is smaller than the new value
        (*hash).resize(*stringSum + 1); // resize the array to match the new value
//        puts("DEEPHASH::Expanded Size");
        std::cout << "DEEPHASH::Expanded Size to " << hash->size() << std::endl;
    }
}

void fillOneDimensionalHash(std::vector<simpleItem> *simpleHash, int *stringSum, std::string *key, std::string *value,
                            bool printHashSize) {
    // if the index is occupied, iterate +1 until it is empty (ie: go to the next one)
    while (!(*simpleHash)[(*stringSum)].value.empty()) {
        (*stringSum)++;
        resizeForLargerIndex(simpleHash, stringSum);
    }
    // write the value to the new index in the array
    (*simpleHash)[(*stringSum)].key = *key;
    (*simpleHash)[(*stringSum)].value = *value;
    // print the new length of the array
    std::cout << "Added at index " << *stringSum << std::endl;
}

bool checkForProgramClose(std::string *key, bool *run) {
    if (*key == "x") {
        *run = false;
    };
}

void
addToEmptyDeepArrayIndex(linkedListItem *item, std::vector<linkedListItem> *linkedListHash, std::string *key,
                         std::string *value,
                         int *stringSum) {
    (*item).key = *key;
    (*item).value = *value;
    (*linkedListHash)[(*stringSum)] = *item;
    std::cout << "Added at index " << *stringSum << std::endl;
}

bool deepArrayIndexIsOccupied(std::vector<linkedListItem> *linkedListHash, int stringSum) {
    return ((*linkedListHash)[stringSum].value == "");
}

void printStar(int quantity) {
    for (int i = 1; i <= quantity; i++) {
        std::cout << "*";
    }
}

void printCharAsLine(char character, int quantity) {
    for (int i = 1; i <= quantity; i++) {
        std::cout << character;
    }
    std::cout << std::endl;
}

void insertOrLinkIntoDeepArray(std::vector<linkedListItem> *linkedListHash, linkedListItem *item, int *stringSum,
                               std::string *key, std::string *value) {
    if (deepArrayIndexIsOccupied(linkedListHash, *stringSum)) {
        printStar(3);
        std::cout << "index " << *stringSum << " is empty. Filling" << std::endl;
        addToEmptyDeepArrayIndex(item, linkedListHash, key, value, stringSum);
    } else {
        std::cout << "DEEPHASH: " << std::endl;
        printStar(3);
        std::cout << "index " << *stringSum << " is full. Linking to occupant." << std::endl;
        linkedListItem occupant = (*linkedListHash)[(*stringSum)];
        item->key = *key;
        item->value = *value;
        linkItemToOccupant(item, &occupant);
        std::cout << "occupant " << occupant.key << " is now linked to " << occupant.next->key << std::endl;
    }
}

void linkItemToOccupant(linkedListItem* newItem, linkedListItem* occupant) {
    occupant->next = newItem;
}