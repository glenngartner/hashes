//
// Created by glenn on 9/14/2017.
//

#include <string>
#include <vector>

#ifndef HASHES_CORE_H
#define HASHES_CORE_H

struct linkedListItem {
    std::string key = "";
    std::string value = "";
    linkedListItem *next = nullptr;
};

bool checkForProgramClose(std::string *key, bool *run);

void printCharsOfString(std::string key, int *inputValue, int *stringSum, bool printSum);

//template<typename type, typename allocator>allocator
//void resizeForLargerIndex(std::vector<type, allocator> *hash, int *stringSum);

void resizeForLargerIndex(std::vector<std::string> *hash, int *stringSum);
void resizeForLargerIndexL(std::vector<linkedListItem, std::allocator<linkedListItem>> *hash, int *stringSum);

void fillOneDimensionalHash(std::vector<std::string> *simpleHash, int *stringSum, std::string *value,
                            bool printHashSize);

void addToEmptyDeepArrayIndex(linkedListItem *item, std::vector<linkedListItem> *linkedListHash, std::string *key,
                              std::string *value,
                              int *stringSum);

bool deepArrayIndexIsOccupied(std::vector<linkedListItem> *linkedListHash, int stringSum);

void insertOrLinkIntoDeepArray(std::vector<linkedListItem> *linkedListHash, linkedListItem *item, int *stringSum,
                               std::string *key, std::string *value);

void linkItemToOccupant(linkedListItem* newItem, linkedListItem* occupant);

void printStar(int quantity);

void printCharAsLine(char character, int quantity);

#endif //HASHES_CORE_H
