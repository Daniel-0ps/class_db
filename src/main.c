#include "table.h"
#include <stdio.h>

int main() {
    Table* table = create_table();

    // Insertion de la table
    Row row1 = {1, "Daniel", "daniel@code.com"};
    Row row2 = {2, "Thierry", "Thierry@code.com"};
    Row row3 = {3, "Isaac", "Isaac@code.com"};

    table_insert(table, row1);
    table_insert(table, row2);
    table_insert(table, row3);

    printf("Table content after inserts:\n");
    table_select(table);

    // Suppression d'une table
    table_delete(table, 2);
    printf("\nTable content after deleting ID 2:\n");
    table_select(table);

    return 0;
}
