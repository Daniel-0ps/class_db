#include "table.h"

Table* create_table() {
    Table* table = (Table*)malloc(sizeof(Table));
    table->root = NULL;
    return table;
}

void table_insert(Table* table, Row row) {
    insert_node(&(table->root), row);
}

void table_select(Table* table) {
    print_tree(table->root);
}

void table_delete(Table* table, int id) {
    table->root = delete_node(table->root, id);
}
