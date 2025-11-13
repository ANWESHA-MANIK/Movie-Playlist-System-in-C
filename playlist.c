#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "playlist.h"

void createPlaylist() {
    PNode* head = NULL, *temp;
    char name[50];
    char choice = 'y';

    while (choice == 'y') {
        printf("Enter movie title to add: ");
        scanf(" %[^\n]", name);

        for (int i = 0; i < movieCount; i++) {
            if (strcmp(movies[i].title, name) == 0) {
                PNode* node = (PNode*)malloc(sizeof(PNode));
                node->movie = movies[i];
                node->next = head;
                head = node;
                break;
            }
        }

        printf("Add more? (y/n): ");
        scanf(" %c", &choice);
    }

    // Print playlist in table format
    printf("\n+------------------------------+----------------------+---------------+--------+\n");
    printf("| %-28s | %-20s | %-13s | %-6s |\n", "Title", "Director", "Genre", "Rating");
    printf("+------------------------------+----------------------+---------------+--------+\n");

    temp = head;
    while (temp) {
        printf("| %-28s | %-20s | %-13s | %-6.1f |\n",
            temp->movie.title,
            temp->movie.director,
            temp->movie.genre,
            temp->movie.rating);
        temp = temp->next;
    }

    printf("+------------------------------+----------------------+---------------+--------+\n");

    FILE *fp = fopen("playlist.txt", "w");
    if (fp == NULL) {
        printf("Error creating playlist.txt\n");
        return;
    }

    temp = head;
    while (temp) {
        fprintf(fp, "%s\n%s\n%s\n%.1f\n\n",
            temp->movie.title,
            temp->movie.director,
            temp->movie.genre,
            temp->movie.rating);
        temp = temp->next;
    }

    fclose(fp);
    printf("\nPlaylist saved to playlist.txt successfully!\n");
}
