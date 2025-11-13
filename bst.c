#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

BSTNode* newNode(Movie m) {
    BSTNode* temp = (BSTNode*)malloc(sizeof(BSTNode));
    temp->movie = m;
    temp->left = temp->right = NULL;
    return temp;
}

BSTNode* insertBST(BSTNode* root, Movie m) {
    if(!root) return newNode(m);
    if(m.rating < root->movie.rating)
        root->left = insertBST(root->left, m);
    else
        root->right = insertBST(root->right, m);
    return root;
}

void searchAboveRating(BSTNode* root, float rating) {
    if(!root) return;
    searchAboveRating(root->left, rating);
    if(root->movie.rating >= rating)
        printf("%s (%.1f)\n", root->movie.title, root->movie.rating);
    searchAboveRating(root->right, rating);
}
