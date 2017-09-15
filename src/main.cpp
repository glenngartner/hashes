#include <iostream>
#include <unordered_map>
#include <string>
#include <cstring>
#include <vector>
#include "core.h"

int main() {

    bool run = true;
    std::string key;
    std::string value;
    std::vector<std::string> simpleHash;
    std::vector<linkedListItem> linkedListHash;

    // main program loop
    while (run) {

        // reset values for each loop
        int inputValue = 0;
        int stringSum = 0;

        // prompt the user
        puts("What's the name of your key? ('x' to escape)");
        std::cin >> key;

        // evaluate the input
        if (checkForProgramClose(&key, &run)) break;
        printCharsOfString(key, &inputValue, &stringSum, true);

        // prompt the user for more input
        printf("What's the value?\n");
        std::cin >> value;

        // add linked list item to the deep hash
        resizeForLargerIndexL(&linkedListHash, &stringSum);
        linkedListItem item;
        fillDeepHash(&item, &linkedListHash, &key, &value, &stringSum);

        // add key and value to the one-dimensional hash
        resizeForLargerIndex(&simpleHash, &stringSum);
        fillOneDimensionalHash(&simpleHash, &stringSum, &value, true);
    }

    exit(EXIT_SUCCESS);
}
