#include "../include/morse_tree.hpp"

node::node(char v) {
    value = v;
    left = nullptr;
    right = nullptr;
}

node* initMorseTree() {
    node* root = new node('\0');

    root->left = new node('e');
    root->right = new node('t');

    root->left->left = new node('i');
    root->left->right = new node('a');
    root->right->left = new node('n');
    root->right->right = new node('m');

    root->left->left->left = new node('s');
    root->left->left->right = new node('u');
    root->left->right->left = new node('r');
    root->left->right->right = new node('w');
    root->right->left->left = new node('d');
    root->right->left->right = new node('k');
    root->right->right->left = new node('g');
    root->right->right->right = new node('o');

    root->left->left->left->left = new node('h');
    root->left->left->left->right = new node('v');
    root->left->left->right->left = new node('f');
    root->left->right->left->left = new node('l');
    root->left->right->right->left = new node('p');
    root->left->right->right->right = new node('j');
    root->right->left->left->left = new node('b');
    root->right->left->left->right = new node('x');
    root->right->left->right->left = new node('c');
    root->right->left->right->right = new node('y');
    root->right->right->left->left = new node('z');
    root->right->right->left->right = new node('q');

    root->left->left->left->left->left = new node('5');
    root->left->left->left->left->right = new node('4');
    root->left->left->left->right->right = new node('3');
    root->left->left->right->right = new node('2');
    root->left->right->right->right->right = new node('1');

    root->right->left->left->left->left = new node('6');
    root->right->right->left->left->left = new node('7');
    root->right->right->right->left = new node('8');
    root->right->right->right->right = new node('9');
    root->right->right->right->right->right = new node('0');

    return root;
}

