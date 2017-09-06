#include <iostream>

int main() {

    bool run = true;
    char input;
    while (run) {
        puts("Please type a single character");
        std::cin >> input;
        switch (input) {
            case 'x':
                run = false;
                break;
            default:
                std::cout << "You typed: " << input << " which evaluates to: " << (int) input << std::endl;
                puts("(x) to escape");
                break;
        }
    }
    return 0;
}
