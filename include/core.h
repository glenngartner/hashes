//
// Created by glenn on 9/14/2017.
//

#include <string>
#include <vector>

#ifndef HASHES_CORE_H
#define HASHES_CORE_H

void printCharsOfString(std::string key, int *inputValue, int *stringSum, bool printSum);

void resizeForLargerIndex(std::vector<std::string> *simpleHash, int *stringSum);

void fillOneDimensionalHash(std::vector<std::string> *simpleHash, int *stringSum, std::string *value,
                            bool printHashSize);

#endif //HASHES_CORE_H
