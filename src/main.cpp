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

    // main program loop
    while (run) {
        int inputValue = 0;
        int stringSum = 0;
        puts("What's the name of your key? ('x' to escape)");
        std::cin >> key;
        if (key == "x") {
            run = false;
            break;
        }
        printCharsOfString(key, &inputValue, &stringSum, true);

        printf("What's the value?\n");
        std::cin >> value;

        // resize the hash to match the largest index
        resizeForLargerIndex(&simpleHash, &stringSum);
        fillOneDimensionalHash(&simpleHash, &stringSum, &value, true);
//        // if the index is occupied, iterate +1 until it is empty (ie: go to the next one)
//        while (!simpleHash[stringSum].empty()) {
//            stringSum++;
//            resizeForLargerIndex(&simpleHash, &stringSum);
//        }
//        // write the value to the new index in the array
//        simpleHash[stringSum] = value;
//        // print the new length of the array
//        std::cout << "simpleHash size " << simpleHash.size() << std::endl;
    }

    exit(EXIT_SUCCESS);
}
