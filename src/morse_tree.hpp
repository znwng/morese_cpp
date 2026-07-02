#ifndef MORSETREE_H
#define MORSETREE_H

struct node {
    char value;
    node* left;
    node* right;

    node(char v);
};

node* initMorseTree();

#endif

