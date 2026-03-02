#include "../include/encoder.hpp"
#include "../include/morse_tree.hpp"

#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cout << "HELP PRINT// TODO\n";
        return -1;
    }

    node* root = initMorseTree();

    std::string command = argv[1];

    if (command == "--encode" || command == "-e") {
        std::string message_to_encode = argv[2];
        std::vector<std::string> encoded_message = encode(message_to_encode, root);

        for (std::string enc : encoded_message) {
            std::cout << enc << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

