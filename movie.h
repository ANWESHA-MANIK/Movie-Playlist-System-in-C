#ifndef MOVIE_H
#define MOVIE_H

typedef struct {
    char title[50];
    char director[50];
    char genre[30];
    float rating;
} Movie;

extern Movie movies[200];
extern int movieCount;

void loadMovies();
void saveMoviesToFile();
void displayAllMovies();
void sortMoviesByTitle();
void deleteMovie();

#endif
