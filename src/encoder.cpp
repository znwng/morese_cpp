#include "../include/encoder.hpp"

#include <cctype>

bool getCharMorse(char target, node* root, std::string& path) {
    if (!root) return false;
    if (root->value == target) return true;

    path.push_back('.');
    if (getCharMorse(target, root->left, path)) return true;
    path.pop_back();

    path.push_back('-');
    if (getCharMorse(target, root->right, path)) return true;
    path.pop_back();

    return false;
}

std::vector<std::string> encode(const std::string& message, node* root) {
    std::vector<std::string> encodedMessage;
    for (char c : message) {
        if (c == ' ') {
            encodedMessage.push_back("   ");
            continue;
        }

        c = tolower(c);

        std::string path;
        if (getCharMorse(c, root, path)) {
            encodedMessage.push_back(path + " ");
        }
    }

    return encodedMessage;
}

