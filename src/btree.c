#include"btree.h"


Node* create_node(Row row) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->row = row;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void insert_node(Node** root, Row row) {
    if (*root == NULL) {
        *root = create_node(row);
        return;
    }
    if (row.id < (*root)->row.id) {
        insert_node(&((*root)->left), row);
    } else if (row.id > (*root)->row.id) {
        insert_node(&((*root)->right), row);
    } else {
        printf("Error: Duplicate ID %d not allowed.\n", row.id);
    }
}

void print_tree(Node* root) {
    if (root == NULL) return;
    print_tree(root->left);
    printf("ID: %d, Name: %s, Email: %s\n", root->row.id, root->row.name, root->row.email);
    print_tree(root->right);
}

Node* delete_node(Node* root, int id) {
    if (root == NULL) return NULL;

    if (id < root->row.id) {
        root->left = delete_node(root->left, id);
    } else if (id > root->row.id) {
        root->right = delete_node(root->right, id);
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = root->right;
        while (temp->left != NULL) temp = temp->left;
        root->row = temp->row;
        root->right = delete_node(root->right, temp->row.id);
    }

    return root;
}

Node* find_node(Node* root, int id) {
    if (root == NULL || root->row.id == id) return root;

    if (id < root->row.id) return find_node(root->left, id);

    return find_node(root->right, id);
}
