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
//        printcharsOfString(key, &inputValue, &stringSum);
        int i = 0;
        while (key[i] != NULL) {
            inputValue = (int) (char) key[i];
            printf("%c = %i\n", key[i], inputValue);
            stringSum += inputValue;
            i++;
        }

        printf("The sum of your string is %i\n", stringSum);

        printf("What's the value?\n");
        std::cin >> value;

        // resize the hash to match the largest index
        if (simpleHash.size() <= stringSum) { // if the hash size is smaller than the new value
            simpleHash.resize(stringSum + 1); // resize the array to match the new value
        }
        // if the index is occupied, iterate +1 until it is empty (ie: go to the next one)
        while (!simpleHash[stringSum].empty()) {
            stringSum++;
            if (simpleHash.size() <= stringSum) {
                simpleHash.resize(stringSum + 1);
            } else {
                // do  nothing. resizing at a lower value will delete higher indices
            }
        }
        // write the value to the new index in the array
        simpleHash[stringSum] = value;
        // print the new length of the array
        std::cout << "simpleHash size " << simpleHash.size() << std::endl;
    }

    exit(EXIT_SUCCESS);
}
