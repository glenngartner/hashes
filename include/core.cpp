//
// Created by glenn on 9/14/2017.
//

#include "core.h"

void printcharsOfString(std::string key, int *inputValue, int *stringSum) {
    int i = 0;
    while (key[i] != NULL) {
        *inputValue = (int)(char)key[i];
        printf("%c = %i\n", key[i], inputValue);
        *stringSum += *inputValue;
        i++;
    }

}
