#ifndef BST_H
#define BST_H

#include "movie.h"

typedef struct bstNode {
    Movie movie;
    struct bstNode *left, *right;
} BSTNode;

BSTNode* insertBST(BSTNode* root, Movie m);
void searchAboveRating(BSTNode* root, float rating);

#endif
