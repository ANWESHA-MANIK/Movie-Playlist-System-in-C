#include <stdio.h>
#include <stdlib.h>
#include "movie.h"
#include "bst.h"
#include "skiplist.h"
#include "playlist.h"

int main() {

    loadMovies();

    // build BST
    BSTNode* bst = NULL;
    for (int i = 0; i < movieCount; i++)
        bst = insertBST(bst, movies[i]);

    // build skiplist
    SNode* genreList = buildSkipList();

    int choice;
    char genre[30];
    float rate;

    while (1) {
        printf("\n========= MENU =========");
        printf("\n1. Display All Movies");
        printf("\n2. Search by Genre");
        printf("\n3. Search by Rating");
        printf("\n4. Create Playlist");
        printf("\n5. Delete Movie");
        printf("\n6. Sort Movies Alphabetically");
        printf("\n7. Exit");
        printf("\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                displayAllMovies();
                break;

            case 2:
                printf("Enter Genre: ");
                scanf(" %[^\n]", genre);
                searchByGenre(genreList, genre);
                break;

            case 3:
                printf("Rating above: ");
                scanf("%f", &rate);
                searchAboveRating(bst, rate);
                break;

            case 4:
                createPlaylist();
                break;

            case 5:
                deleteMovie();
                break;

            case 6:
                sortMoviesByTitle();
                break;

            case 7:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
