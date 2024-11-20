#ifndef BTREE_H
#define BTREE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Structure représentant une ligne (row) de la table
typedef struct {
    int id;
    char name[32];
    char email[255];
} Row;

// Nœud de l'arbre binaire
typedef struct Node {
    int id;
    Row row;
    struct Node* left;
    struct Node* right;
} Node;


// Fonctions liées à l'arbre binaire
Node* create_node(Row row);
void insert_node(Node** root, Row row);
void print_tree(Node* root);
Node* delete_node(Node* root, int id);
Node* find_node(Node* root, int id);

#endif // BTREE_H
