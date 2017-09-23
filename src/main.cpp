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
    std::vector<simpleItem> simpleHash;
    std::vector<linkedListItem> linkedListHash;
    deepHash linkedHash{11};
    bool hasRunOnce = false;
    char userInput;

    // main program loop
    while (run) {

        // reset values for each loop
        int inputValue = 0;
        int stringSum = 0;

        // what would you like to do?
        if (hasRunOnce) {
            puts("What would you like to do?");
            puts("");
            puts("(e) Enter a key - value pair");
            puts("(p) Print stats for both hashes");
            puts("(s) Search for a key - value pair");
            puts("(x) to Exit");
            puts("");
            std::cin >> userInput;
        } else {
            // if this is the first time running
            // ask the user for a key-value pair
            userInput = 'e';
        }


        switch (userInput) {
            case 'x': {
                run = false;
                break;
            }
            case 's': {
                bool itemNotExist = false;
                puts("What key are you looking for?");
                std::cin >> key;
                puts("What value are you looking for?");
                std::cin >> value;
                printCharAsLine('-', 45);
                // check if the search key and value exist
                for (int i = 0; i < simpleHash.size(); i++) {
                    // if they are not found
                    if (simpleHash[i].key == key && simpleHash[i].value == value) {
                        itemNotExist = false;
                        break;
                    } else {
                        itemNotExist = true;
                    }
                }
                // if the item isn't found, alert the user
                if (itemNotExist) {
                    printCharAsLine('x', 45);
                    puts("Sorry, that item doesn't exist.");
                    printCharAsLine('x', 45);
                    puts("");
                } else {
                    linkedListItem *itemWithValue = linkedHash.returnItem(&key, &value);
                    puts("Found: ");
                    std::cout << "[" << itemWithValue->key << "]=[" << itemWithValue->value << "]" << std::endl;
                    printCharAsLine('=', 45);
                    std::cout << "DEEPHASH index: " << linkedHash.indexOfItem(&key, &value) << std::endl;
                    if (itemWithValue->next != nullptr) {
                        std::cout << "DEEPHASH neighbor: " << "[" << itemWithValue->next->key << "]= ["
                                  << itemWithValue->next->value << "]" << std::endl;
                    }
                    printCharAsLine('-', 45);
                    int sum = linkedHash.sumOfString(key);
                    int index = linkedHash.calcIndex(sum);
                    if (simpleHash[index].value == value && simpleHash[index].key == key) {
                        std::cout << "SIMPLEHASH index: " << index << std::endl;
                    } else {
                        int i = index;
                        while (simpleHash[i].value != value && simpleHash[i].key != key) {
                            i++;
                        }
                        std::cout << "SIMPLEHASH index: " << i << std::endl;
                    }
                    printCharAsLine('-', 45);
                }
                break;
            }
            case 'p': {
                printCharAsLine('-', 45);
                std::cout << "DEEPHASH: " << std::endl;
                std::cout << "length: " << linkedHash.array.size() << std::endl;
                std::cout << "indices occupied: ";
                for (int i = 0; i < linkedHash.occupiedIndices.size(); i++) {
                    std::cout << linkedHash.occupiedIndices[i] << ", ";
                }
                std::cout << std::endl;
                printCharAsLine('-', 45);
                puts("");
                std::cout << "SIMPLEHASH: " << std::endl;
                std::cout << "length: " << simpleHash.size() << std::endl;
                std::cout << "indices occupied: ";
                for (int i = 0; i < simpleHash.size(); i++) {
                    if (simpleHash[i].value != "") {
                        std::cout << i << ", ";
                    }
                }
                std::cout << std::endl;
                printCharAsLine('-', 45);
                puts("");
                break;
            }
            case 'e': {
                // prompt the user
                puts("What's the name of your key? ('x' to escape)");
                std::cin >> key;
                printCharsOfString(key, &inputValue, &stringSum, false);

                // prompt the user for more input
                printf("What's the value?\n");
                std::cin >> value;

                // evaluate the input
//                if (checkForProgramClose(&key, &run)) break;


                // show the user what you're entering
                puts("");
                std::cout << "ADDING: [\"" << key << "\"] = \"" << value << "\"" << std::endl;
                puts("");

                // add linked list item to the deep hash
                printCharAsLine('-', 45);
                stringSum = linkedHash.calcIndex(stringSum);

                auto *item = new linkedListItem; // create an empty linked list item
                linkedHash.insertOrLink(item, &stringSum, &key, &value);
                if (linkedHash.getDepthOfIndex(5) > 3) {
                    linkedHash.resize(17);
                }

                // add key and value to the one-dimensional hash
                printCharAsLine('-', 45);
                std::cout << "SIMPLEHASH:" << std::endl;
                resizeForLargerIndex(&simpleHash, &stringSum);
                fillOneDimensionalHash(&simpleHash, &stringSum, &key, &value, true);
                printCharAsLine('-', 45);
                break;
            }
            default:
                puts("That's not an option. Please try again");
        }

        hasRunOnce = true;

    }

    exit(EXIT_SUCCESS);
}
