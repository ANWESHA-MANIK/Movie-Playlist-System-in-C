#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "movie.h"

typedef struct pnode {
    Movie movie;
    struct pnode* next;
} PNode;

void createPlaylist();

#endif
