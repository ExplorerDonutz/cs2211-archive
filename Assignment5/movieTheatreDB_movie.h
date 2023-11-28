#ifndef MOVIETHEATREDB_MOVIE_H
#define MOVIETHEATREDB_MOVIE_H

#include <stddef.h>  // Include this for NULL

struct MovieNode {
    struct Movie *movie;
    struct MovieNode *prev;
    struct MovieNode *next;
};

// Functions used in the main class
void movieControls();
void freeMovieDatabase();

#endif // MOVIETHEATREDB_MOVIE_H
