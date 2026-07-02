#include "decoder.hpp"

#include <sstream>
#include <vector>

// Traverses the Morse tree according to the given Morse code.
//   '.' -> move to the left child
//   '-' -> move to the right child
// Returns the corresponding character, or '\0' if the
// Morse sequence is invalid.
char getMorseChar(const std::string& morse, node* root) {
    // Empty tree.
    if (!root)
        return '\0';

    node* curr = root;

    // Follow each symbol in the Morse sequence.
    for (char dir : morse) {
        if (dir == '.') {
            curr = curr->left;
        } else if (dir == '-') {
            curr = curr->right;
        }

        // Invalid path.
        if (!curr)
            return '\0';
    }

    return curr->value;
}

// Decodes a Morse code message into plain text.
// Assumes:
//   - Two spaces separate letters.
//   - Six spaces separate words.
std::string decode(const std::string& message, node* root) {
    // Stores each word as a vector of Morse letters.
    std::vector<std::vector<std::string>> groups;

    size_t start = 0;

    // Split the message into words using six spaces.
    while (true) {
        size_t pos = message.find("      ", start); // Six spaces = new word.
        std::string chunk = message.substr(start, pos - start);

        // Split each word into individual Morse letters.
        std::vector<std::string> letters;
        std::istringstream iss(chunk);
        std::string morseLetter;

        while (iss >> morseLetter) {
            letters.push_back(morseLetter);
        }

        if (!letters.empty())
            groups.push_back(letters);

        if (pos == std::string::npos)
            break;

        start = pos + 6;
    }

    std::string decoded;

    // Convert each Morse letter back to its character.
    for (const auto& word : groups) {
        for (const auto& letter : word) {
            char c = getMorseChar(letter, root);
            if (c != '\0')
                decoded.push_back(c);
        }

        // Separate decoded words with a space.
        decoded.push_back(' ');
    }

    // Remove the trailing space after the final word.
    if (!decoded.empty())
        decoded.pop_back();

    return decoded;
}

