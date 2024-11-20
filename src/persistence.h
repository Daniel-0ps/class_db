#ifndef PERSISTENCE_H
#define PERSISTENCE_H

#include "btree.h"

void persist_to_disk(Node* root, const char* filename);
void load_from_disk(Node** root, const char* filename);

#endif // PERSISTENCE_H
