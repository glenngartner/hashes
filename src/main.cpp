#include <iostream>
#include <unordered_map>
#include <string>
#include <cstring>
#include <vector>
#include "core.h"
#include "hash.h"
#include "deepHash.h"

int main() {

    bool run = true;
    std::string key;
    std::string value;
    std::vector<std::string> simpleHash;
    std::vector<linkedListItem> linkedListHash;
    deepHash linkedHash{15};

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

        // show the user what you're entering
        puts("");
        std::cout << "ADDING: [\"" << key << "\"] = \"" << value << "\"" << std::endl;
        printStar(2);
        std::cout << "Trying at index: " << stringSum << std::endl;
        puts("");

        // add linked list item to the deep hash
        printCharAsLine('-', 45);
        linkedHash.resizeForLargerIndex(&stringSum);
//        resizeForLargerIndexL(&linkedListHash, &stringSum);
        linkedListItem *item = new linkedListItem; // create an empty linked list item
        linkedHash.insertOrLink(item, &stringSum, &key, &value);
//        insertOrLinkIntoDeepArray(&linkedListHash, &item, &stringSum, &key, &value);

        // add key and value to the one-dimensional hash
        printCharAsLine('-', 45);
        resizeForLargerIndex(&simpleHash, &stringSum);
        fillOneDimensionalHash(&simpleHash, &stringSum, &value, true);
        printCharAsLine('-', 45);
    }

    exit(EXIT_SUCCESS);
}
