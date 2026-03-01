#include "../include/encoder.hpp"
#include "../include/morse_tree.hpp"

#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    node* root = initMorseTree();
    string message = "hello world";
    vector<string> encoded = encode(message, root);

    for (const auto& part : encoded) cout << part;

    cout << endl;

    return 0;
}

