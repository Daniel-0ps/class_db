#ifndef TABLE_H
#define TABLE_H

#include "btree.h"

// Représente une table avec un arbre binaire
typedef struct {
    Node* root;
} Table;

// Fonctions pour la table
Table* create_table();
void table_insert(Table* table, Row row);
void table_select(Table* table);
void table_delete(Table* table, int id);

#endif // TABLE_H
