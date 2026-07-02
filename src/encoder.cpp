#include "encoder.hpp"

#include <cctype>

// Recursively searches the Morse tree for the target character.
// As the recursion moves:
//   - Left child  -> '.' is added to the path
//   - Right child -> '-' is added to the path
// Returns true if the character is found, leaving `path`
// containing its Morse code.
bool getCharMorse(char target, node* root, std::string& path) {
    // Base case: reached an empty node.
    if (!root)
        return false;

    // Character found.
    if (root->value == target)
        return true;

    // Explore the left subtree (dot).
    path.push_back('.');
    if (getCharMorse(target, root->left, path))
        return true;
    path.pop_back(); // Backtrack if not found.

    // Explore the right subtree (dash).
    path.push_back('-');
    if (getCharMorse(target, root->right, path))
        return true;
    path.pop_back(); // Backtrack if not found.

    // Character does not exist in this subtree.
    return false;
}

// Encodes an entire message into Morse code using the Morse tree.
// Returns a vector where each element is the Morse representation
// of one character (or three spaces for a word separator).
std::vector<std::string> encode(const std::string& message, node* root) {
    std::vector<std::string> encodedMessage;

    // Process each character in the input message.
    for (char c : message) {
        // Separate words with three spaces in Morse code.
        if (c == ' ') {
            encodedMessage.push_back("   ");
            continue;
        }

        // Morse code is case-insensitive.
        c = tolower(c);

        // Find the Morse path for the current character.
        std::string path;
        if (getCharMorse(c, root, path)) {
            // Append a space after each encoded letter.
            encodedMessage.push_back(path + " ");
        }
        // Characters not present in the tree are ignored.
    }

    return encodedMessage;
}

