//
// Created by glenn on 9/14/2017.
//

#include "core.h"
#include <iostream>
#include <vector>

void printCharsOfString(std::string key, int *inputValue, int *stringSum, bool printSum) {
    int i = 0;
    while (key[i] != '\0') {
        *inputValue = (int) (char) key[i];
        printf("%c = %i\n", key[i], *inputValue);
        *stringSum += *inputValue;
        i++;
    }
    if (printSum) printf("The sum of your string is %i\n", *stringSum);
}

//template<typename type, typename allocator>
//void resizeForLargerIndex(std::vector<type, allocator> *hash, int *stringSum) {
//    if ((*hash).size() <= *stringSum) { // if the hash size is smaller than the new value
//        (*hash).resize(*stringSum + 1); // resize the array to match the new value
//    }
//}

void resizeForLargerIndex(std::vector<std::string> *hash, int *stringSum) {
    if ((*hash).size() <= *stringSum) { // if the hash size is smaller than the new value
        (*hash).resize(*stringSum + 1); // resize the array to match the new value
        puts("SIMPLEHASH::Expanded Size");
    }
}

void resizeForLargerIndexL(std::vector<linkedListItem> *hash, int *stringSum) {
    if ((*hash).size() <= *stringSum) { // if the hash size is smaller than the new value
        (*hash).resize(*stringSum + 1); // resize the array to match the new value
        puts("DEEPHASH::Expanded Size");
    }
}

void fillOneDimensionalHash(std::vector<std::string> *simpleHash, int *stringSum, std::string *value,
                            bool printHashSize) {
    // if the index is occupied, iterate +1 until it is empty (ie: go to the next one)
    while (!(*simpleHash)[(*stringSum)].empty()) {
        (*stringSum)++;
        resizeForLargerIndex(simpleHash, stringSum);
    }
    // write the value to the new index in the array
    (*simpleHash)[(*stringSum)] = *value;
    // print the new length of the array
    std::cout << "simpleHash size " << simpleHash->size() << std::endl;
}

bool checkForProgramClose(std::string *key, bool *run) {
    if (*key == "x") {
        *run = false;
    };
}

void fillDeepHash(linkedListItem *item, std::vector<linkedListItem> *linkedListHash, std::string *key, std::string *value,
                  int *stringSum) {
    (*item).key = *key;
    (*item).value = *value;
    (*linkedListHash)[(*stringSum)] = *item;
    std::cout << "Deephash size " << linkedListHash->size() << std::endl;
}

bool isDeepArrayIndexOccuppied(std::vector<linkedListItem> *linkedListHash, int stringSum) {
//    (*linkedListHash)[stringSum] == NULL ? return false : return true;
}
