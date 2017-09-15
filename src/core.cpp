//
// Created by glenn on 9/14/2017.
//

#include "core.h"
#include <iostream>
#include <vector>

void printCharsOfString(std::string key, int *inputValue, int *stringSum, bool printSum) {
    int i = 0;
    while (key[i] != '\0') {
        *inputValue = (int)(char)key[i];
        printf("%c = %i\n", key[i], *inputValue);
        *stringSum += *inputValue;
        i++;
    }
    if (printSum) printf("The sum of your string is %i\n", *stringSum);
}

void resizeForLargerIndex(std::vector<std::string> *simpleHash, int *stringSum) {
    if ((*simpleHash).size() <= *stringSum) { // if the hash size is smaller than the new value
        (*simpleHash).resize(*stringSum + 1); // resize the array to match the new value
    }
}

void fillOneDimensionalHash(std::vector<std::string> *simpleHash, int *stringSum, std::string *value,
                            bool printHashSize) {
    // if the index is occupied, iterate +1 until it is empty (ie: go to the next one)
//    int sum = *stringSum;
    while (!(*simpleHash)[(*stringSum)].empty()) {
        (*stringSum)++;
//        sum = *stringSum;
        resizeForLargerIndex(simpleHash, stringSum);
    }
    // write the value to the new index in the array
//    sum = *stringSum;
    (*simpleHash)[(*stringSum)] = *value;
    // print the new length of the array
    std::cout << "simpleHash size " << simpleHash->size() << std::endl;
}
