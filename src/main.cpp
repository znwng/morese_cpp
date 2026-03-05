#include "../include/decoder.hpp"
#include "../include/encoder.hpp"
#include "../include/morse_tree.hpp"

#include <cctype>
#include <fstream>
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

    if (command == "--encode-file" || command == "-ef") {
        std::string file_path = argv[2];
        std::string output_file = "encoded_file.morse";
        if (argc == 4) {
            output_file = argv[3];
        }
        std::ofstream file(output_file);
        std::ifstream fin(file_path);

        std::string line;

        while (getline(fin, line)) {
            std::vector<std::string> encoded_line = encode(line, root);
            for (size_t i = 0; i < encoded_line.size(); ++i) {
                file << encoded_line[i];
                if (i != encoded_line.size() - 1) file << ' ';
            }
            file << "\n";
            std::cout << line << " => ";
            for (const auto& x : encoded_line) std::cout << x << " ";
            std::cout << std::endl;
        }

        file.close();
        fin.close();
    }

    if (command == "--decode" || command == "-d") {
        std::string message_to_decode = argv[2];
        std::string decoded_message = decode(message_to_decode, root);

        std::cout << decoded_message << std::endl;
    }

    if (command == "--decode-file" || command == "-df") {
        std::string file_path = argv[2];
        std::string output_file = (argc > 3) ? argv[3] : "decoded_file";

        std::ifstream fin(file_path);
        if (!fin) {
            std::cerr << "Error opening input file: " << file_path << std::endl;
            return -1;
        }

        std::ofstream file(output_file);
        if (!file) {
            std::cerr << "Error creating output file: " << output_file << std::endl;
            return -1;
        }

        std::string line;
        while (getline(fin, line)) {
            std::string decoded_line = decode(line, root);
            file << decoded_line << '\n';
            std::cout << decoded_line << std::endl;
        }
    }

    return 0;
}

