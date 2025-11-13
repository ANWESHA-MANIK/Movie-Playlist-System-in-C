#ifndef SKIPLIST_H
#define SKIPLIST_H

#include "movie.h"

typedef struct node {
    char genre[30];
    int movieIndex;
    struct node *next;      // normal list
    struct node *express;   // skip pointer
} SNode;

SNode* buildSkipList();
void searchByGenre(SNode* head, char* genre);

#endif
