#include "persistence.h"
#include <stdio.h>

void save_tree(Node* root, FILE* file) {
    if (root == NULL) return;
    fwrite(&(root->row), sizeof(Row), 1, file);
    save_tree(root->left, file);
    save_tree(root->right, file);
}

void load_tree(Node** root, FILE* file) {
    Row row;
    while (fread(&row, sizeof(Row), 1, file)) {
        insert_node(root, row);
    }
}

void persist_to_disk(Node* root, const char* filename) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        printf("Error opening file for writing.\n");
        return;
    }
    save_tree(root, file);
    fclose(file);
}

void load_from_disk(Node** root, const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        printf("No existing database file found.\n");
        return;
    }
    load_tree(root, file);
    fclose(file);
}
