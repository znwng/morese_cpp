#include "decoder.hpp"
#include "encoder.hpp"
#include "morse_tree.hpp"

#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Entry point of the Morse code application.
//
// Supported commands:
//   --encode (-e)        Encode a string.
//   --encode-file (-ef)  Encode a text file.
//   --decode (-d)        Decode a Morse string.
//   --decode-file (-df)  Decode a Morse file.
int main(int argc, char* argv[]) {
    // Ensure a command and input are provided.
    if (argc < 3) {
        std::cout << "HELP PRINT// TODO\n";
        return -1;
    }

    // Build the Morse code binary tree.
    node* root = initMorseTree();

    std::string command = argv[1];

    // Encode a message passed through the command line.
    if (command == "--encode" || command == "-e") {
        std::string message_to_encode = argv[2];
        std::vector<std::string> encoded_message = encode(message_to_encode, root);

        // Print the encoded Morse message.
        for (std::string enc : encoded_message) {
            std::cout << enc << " ";
        }
        std::cout << std::endl;
    }

    // Encode the contents of a text file.
    if (command == "--encode-file" || command == "-ef") {
        std::string file_path = argv[2];

        // Use the provided output filename, or a default one.
        std::string output_file = "encoded_file.morse";
        if (argc == 4) {
            output_file = argv[3];
        }

        std::ofstream file(output_file);
        std::ifstream fin(file_path);

        std::string line;

        // Encode each line independently.
        while (getline(fin, line)) {
            std::vector<std::string> encoded_line = encode(line, root);

            for (size_t i = 0; i < encoded_line.size(); ++i) {
                file << encoded_line[i];

                // Separate encoded letters with a space.
                if (i != encoded_line.size() - 1)
                    file << ' ';
            }

            file << "\n";
        }

        file.close();
        fin.close();
    }

    // Decode a Morse message passed through the command line.
    if (command == "--decode" || command == "-d") {
        std::string message_to_decode = argv[2];
        std::string decoded_message = decode(message_to_decode, root);

        std::cout << decoded_message << std::endl;
    }

    // Decode a Morse code file.
    if (command == "--decode-file" || command == "-df") {
        std::string file_path = argv[2];
        std::string output_file = (argc > 3) ? argv[3] : "decoded_file";

        // Open the input file.
        std::ifstream fin(file_path);
        if (!fin) {
            std::cerr << "Error opening input file: " << file_path << std::endl;
            return -1;
        }

        // Create the output file.
        std::ofstream file(output_file);
        if (!file) {
            std::cerr << "Error creating output file: " << output_file << std::endl;
            return -1;
        }

        std::string line;

        // Decode each line and write it to the output file.
        while (getline(fin, line)) {
            std::string decoded_line = decode(line, root);
            file << decoded_line << '\n';
        }
    }

    return 0;
}

