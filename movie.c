#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie.h"

Movie movies[200];
int movieCount = 0;

void loadMovies() {
    FILE *fp = fopen("movies.txt", "r");
    if (!fp) {
        printf("movies.txt not found!\n");
        return;
    }

    movieCount = 0;
    while (!feof(fp)) {
        Movie m;
        if (fscanf(fp, " %[^\n]\n %[^\n]\n %[^\n]\n %f\n",
                   m.title, m.director, m.genre, &m.rating) == 4) {
            movies[movieCount++] = m;
        }
    }
    fclose(fp);
}

void saveMoviesToFile() {
    FILE *fp = fopen("movies.txt", "w");
    if (!fp) {
        printf("Error writing to movies.txt!\n");
        return;
    }

    for (int i = 0; i < movieCount; i++) {
        fprintf(fp, "%s\n%s\n%s\n%.1f\n",
                movies[i].title,
                movies[i].director,
                movies[i].genre,
                movies[i].rating);

        if (i < movieCount - 1)
            fprintf(fp, "\n");
    }

    fclose(fp);
}

void displayAllMovies() {

    if (movieCount == 0) {
        printf("\nNo movies available!\n");
        return;
    }

    printf("\n------------------------------------------------------------------------------\n");
    printf("%-30s %-20s %-15s %-6s\n",
           "TITLE", "DIRECTOR", "GENRE", "RATING");
    printf("------------------------------------------------------------------------------\n");

    for (int i = 0; i < movieCount; i++) {
        printf("%-30s %-20s %-15s %.1f\n",
               movies[i].title,
               movies[i].director,
               movies[i].genre,
               movies[i].rating);
    }

    printf("------------------------------------------------------------------------------\n");
}

void sortMoviesByTitle() {
    Movie temp;

    for (int i = 0; i < movieCount - 1; i++) {
        for (int j = i + 1; j < movieCount; j++) {
            if (strcasecmp(movies[i].title, movies[j].title) > 0) {
                temp = movies[i];
                movies[i] = movies[j];
                movies[j] = temp;
            }
        }
    }

    printf("\nMovies sorted alphabetically!\n");
    displayAllMovies();

    FILE *fp = fopen("sorted_movies.txt", "w");
    if (!fp) {
        printf("Error creating sorted_movies.txt!\n");
        return;
    }

    for (int i = 0; i < movieCount; i++) {
        fprintf(fp, "%s\n%s\n%s\n%.1f\n\n",
                movies[i].title,
                movies[i].director,
                movies[i].genre,
                movies[i].rating);
    }

    fclose(fp);

    printf("\nSorted movies saved to sorted_movies.txt\n");
}

void deleteMovie() {
    int choice;
    char value[50];
    float rate;
    int found = 0;

    printf("\nDelete Movie By:\n");
    printf("1. Title\n2. Director\n3. Genre\n4. Rating\nChoice: ");
    scanf("%d", &choice);

    if (choice >= 1 && choice <= 3) {
        printf("Enter value: ");
        scanf(" %[^\n]", value);
    } else if (choice == 4) {
        printf("Enter Rating: ");
        scanf("%f", &rate);
    } else {
        printf("Invalid choice!\n");
        return;
    }

    for (int i = 0; i < movieCount; i++) {
        int match = 0;

        switch (choice) {
            case 1:
                if (strcasecmp(movies[i].title, value) == 0) match = 1;
                break;
            case 2:
                if (strcasecmp(movies[i].director, value) == 0) match = 1;
                break;
            case 3:
                if (strcasecmp(movies[i].genre, value) == 0) match = 1;
                break;
            case 4:
                if (movies[i].rating == rate) match = 1;
                break;
        }

        if (match) {
            printf("\nDeleting: %s  (%s / %s / %.1f)",
                   movies[i].title,
                   movies[i].director,
                   movies[i].genre,
                   movies[i].rating);

            // Shift left
            for (int j = i; j < movieCount - 1; j++)
                movies[j] = movies[j + 1];

            movieCount--;
            found = 1;
            i--;
        }
    }

    if (found) {
        saveMoviesToFile();
        printf("\nMovie(s) deleted and updated in movies.txt\n");
    } else {
        printf("\nNo matching movie found!\n");
    }
}
