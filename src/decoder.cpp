#include "../include/decoder.hpp"

#include <sstream>
#include <vector>

char getMorseChar(const std::string& morse, node* root) {
    if (!root) return '\0';

    node* curr = root;

    for (char dir : morse) {
        if (dir == '.') {
            curr = curr->left;
        } else if (dir == '-') {
            curr = curr->right;
        }

        if (!curr) return '\0';
    }

    return curr->value;
}

std::string decode(const std::string& message, node* root) {
    std::vector<std::vector<std::string>> groups;

    size_t start = 0;

    while (true) {
        size_t pos = message.find("  ", start); // double space = new word
        std::string chunk = message.substr(start, pos - start);

        std::vector<std::string> letters;
        std::istringstream iss(chunk);
        std::string morseLetter;

        while (iss >> morseLetter) {
            letters.push_back(morseLetter);
        }

        if (!letters.empty()) groups.push_back(letters);

        if (pos == std::string::npos) break;

        start = pos + 2;
    }

    std::string decoded;

    for (const auto& word : groups) {
        for (const auto& letter : word) {
            char c = getMorseChar(letter, root);
            if (c != '\0') decoded.push_back(c);
        }
        decoded.push_back(' '); // space between words
    }

    if (!decoded.empty()) decoded.pop_back(); // remove trailing space

    return decoded;
}

