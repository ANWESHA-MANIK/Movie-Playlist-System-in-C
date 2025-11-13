#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "skiplist.h"
#include "movie.h"

SNode* buildSkipList() {
    SNode *head = NULL, *tail = NULL;
    SNode *prevExpress = NULL;
    int counter = 0;

    for (int i = 0; i < movieCount; i++) {
        SNode* n = malloc(sizeof(SNode));
        strcpy(n->genre, movies[i].genre);
        n->movieIndex = i;
        n->next = NULL;
        n->express = NULL;

        if (!head) head = n;
        else tail->next = n;

        tail = n;

        // express link every 4th node
        if (counter % 4 == 0) {
            if (prevExpress) prevExpress->express = n;
            prevExpress = n;
        }
        counter++;
    }
    return head;
}

void searchByGenre(SNode* head, char* genre) {
    SNode* cur = head;

    // jump with express pointers first
    while (cur->express && strcmp(cur->express->genre, genre) <= 0)
        cur = cur->express;

    // then linear search
    while (cur && strcmp(cur->genre, genre) == 0) {
        int i = cur->movieIndex;
        printf("%s (%s, %.1f)\n",
               movies[i].title,
               movies[i].director,
               movies[i].rating);
        cur = cur->next;
    }
}
