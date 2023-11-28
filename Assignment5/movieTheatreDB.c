#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct MovieNode {
    struct movie *movie;
    struct MovieNode *prev;
    struct MovieNode *next;
};

struct ActorNode {
    struct Actor *actor;
    struct ActorNode *prev;
    struct ActorNode *next;
};

struct MovieNode *firstMovie = NULL;
struct MovieNode *lastMovie = NULL;

struct ActorNode *firstActor = NULL;
struct ActorNode *lastActor = NULL;

struct movie {
    int code;
    char title[100];
    char genre[25];
    float rating;
};

struct actor {

};

void addMovieNode(struct movie movie) {
    struct MovieNode *newNode = malloc(sizeof(struct MovieNode));
    if (newNode == NULL) {
        // Allocation failure
        return;
    }

    newNode->movie = malloc(sizeof(struct movie));
    if (newNode->movie == NULL) {
        // Allocation failure
        free(newNode);
        return;
    }

    // Copy the contents of the passed movie struct into the node's movie struct
    newNode->movie->code = movie.code;
    strcpy(newNode->movie->title, movie.title);
    strcpy(newNode->movie->genre, movie.genre);
    newNode->movie->rating = movie.rating;

    newNode->next = NULL;

    if (firstMovie == NULL) {
        // There is no first node in the database
        newNode->prev = NULL;
        firstMovie = newNode;
        lastMovie = newNode;
    } else {
        // Make newNode the last node in the list
        lastMovie->next = newNode;
        newNode->prev = lastMovie;
        lastMovie = newNode;
    }
}

void insertMovie() {
    struct movie newMovie;

    // Clear the input stream
    fgetc(stdin);

    // Prompt user for movie code
    printf("Please enter the movie code: ");
    scanf("%d", &newMovie.code);

    struct MovieNode *n = firstMovie;
    while (n != NULL) {
        if (n->movie->code == newMovie.code) {
            printf("Code already exists! Please enter a new code!\n");
            return;
        }
        n = n->next;
    }

    // If the code given is not greater than zero, then print an error
    if (newMovie.code < 0) {
        printf("Invalid code! Please enter a positive digit\n");
        return;
    }

// Clear the input buffer
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    // Prompt user for movie name
    printf("Please enter the movie name: ");
    fgets(newMovie.title, 100, stdin);

    // Clear the input buffer again
    if (strchr(newMovie.title, '\n') == NULL) {
        while ((c = getchar()) != '\n' && c != EOF);
    }

    // Prompt user for movie genre
    printf("Please enter the movie genre: ");
    fgets(newMovie.genre, 25, stdin);

    // Clear the input buffer again
    if (strchr(newMovie.genre, '\n') == NULL) {
        while ((c = getchar()) != '\n' && c != EOF);
    }

    // Prompt user for movie rating
    printf("Please enter the movie rating: ");
    scanf("%f", &newMovie.rating);

    // If the rating given is not within 0.0 - 10.0 then print an error
    if (newMovie.rating < 0.0 || newMovie.rating > 10.0) {
        printf("Invalid rating! Please enter between 0.0 and 10.0!\n");
        return;
    }

    // Add the movie to the database
    addMovieNode(newMovie);
}

void searchMovie() {
    int code;
    int found = 0;

    // Prompt user for movie code
    printf("Please enter the movie code: ");
    scanf(" %d", &code);

    // Search for movie in database
    struct MovieNode *n = firstMovie;
    while (n != NULL) {
        if (n->movie->code == code) {
            // Movie found, update integer and print the movie info
            found = 1;
            printf("Movie Code: %d\nMovie Name: %sMovie Genre: %sMovie Rating: %.1f\n", n->movie->code,
                   n->movie->title, n->movie->genre, n->movie->rating);
            break;
        }

        n = n->next;
    }

    // Inform user if movie wasn't found
    if (found == 0) {
        printf("Movie not found! Please try another code!\n");
    }
}

void eraseMovie() {
    int code;
    printf("Please type the code of the movie that is being erased:\n");
    scanf(" %d", &code);

    struct MovieNode *n = firstMovie;
    while (n != NULL && n->movie->code != code) {
        n = n->next;
    }

    if (n == NULL) {
        printf("Movie not found! Please try another code!\n");
        return;
    }

    if (firstMovie == n) {
        firstMovie = n->next;
        if (firstMovie != NULL) {
            firstMovie->prev = NULL;
        }
    } else if (lastMovie == n) {
        lastMovie = n->prev;
        if (lastMovie != NULL) {
            lastMovie->next = NULL;
        }
    } else {
        n->prev->next = n->next;
        n->next->prev = n->prev;
    }

    free(n);

    // Make n null to prevent accidental calls
    n = NULL;
}

void updateMovie() {
    int code;
    int found = 0;

    // Prompt user for movie code
    printf("Please enter the movie code: ");
    scanf(" %d", &code);

    // Search for movie in database
    struct MovieNode *n = firstMovie;
    while (n != NULL) {


        if (n->movie->code == code) {
            // Movie found, update integer
            found = 1;

            // Create a temp movie with the movie code
            struct movie temp;

            // Clear the input stream
            fgetc(stdin);

            // Prompt user for movie name
            printf("Please enter the movie name: ");
            fgets(temp.title, 100, stdin);

            // Prompt user for movie genre
            printf("Please enter the movie genre: ");
            fgets(temp.genre, 25, stdin);

            // Prompt user for movie rating
            printf("Please enter the movie rating: ");
            scanf("%f", &temp.rating);

            // If the rating given is not within 0.0 - 10.0 then print an error and don't update the movie
            if (n->movie->rating < 0.0 && n->movie->rating > 10.0) {
                printf("Invalid rating! Please enter between 0.0 and 10.0!\n");
                break;
            } else {
                // If no errors then update the movie
                strcpy(n->movie->title, temp.title);
                strcpy(n->movie->genre, temp.genre);
                n->movie->rating = temp.rating;
            }
            break;
        }
    }

// If movie not found, print an error
    if (found == 0) {
        printf("Movie not found! Please try another code!\n");
    }
}

void printMovies() {
    struct MovieNode *n = firstMovie;

    while (n != NULL) {
        printf("Movie Code: %d\nMovie Name: %sMovie Genre: %sMovie Rating %.1f\n\n", n->movie->code, n->movie->title,
               n->movie->genre, n->movie->rating);
        n = n->next;
    }
}

void movie_controls() {
    char choice;
    printf("--------------------\nMovie Controls:\n");
    printf("i - Insert a new movie\ns - Search for a movie\nu - Update a movie\np - Print movie list\ne - Erase a movie\n");
    printf("Please type a movie command:\n");
    scanf(" %c", &choice);
    printf("--------------------\n");


    switch (choice) {
        case 'i':
            insertMovie();
            break;
        case 's':
            searchMovie();
            break;
        case 'u':
            updateMovie();
            break;
        case 'p':
            printMovies();
            break;
        case 'e':
            eraseMovie();
            break;
        default:
            printf("Invalid command, please input a valid command!\n");
    }

    printf("--------------------\n");

}

void actor_controls() {
    char choice;
    printf("--------------------\nActor Controls:\n");
    printf("i - Insert a new actor\ns - Search for an actor\nu - Update an actor\np - Print actor list\ne - Erase an actor\n");
    printf("Please type a movie command:\n");
    scanf(" %c", &choice);
    printf("--------------------\n");


    switch (choice) {
        case 'i':
            insertMovie();
            break;
        case 's':
            searchMovie();
            break;
        case 'u':
            updateMovie();
            break;
        case 'p':
            printMovies();
            break;
        case 'e':
            eraseMovie();
            break;
        default:
            printf("Invalid command, please input a valid command!\n");
    }

    printf("--------------------\n");
}

void freeDatabases() {
    struct MovieNode *current = firstMovie;

    while (current != NULL) {
        struct MovieNode *temp = current;
        current = current->next;

        free(temp->movie); // Free the movie data within the node
        free(temp); // Free the node itself
    }

    firstMovie = NULL; // Reset the first pointer to indicate an empty list
    lastMovie = NULL; // Reset the last pointer to indicate an empty list
}

int main(void) {
    char choice;
    int running = 1;
    while (running == 1) {
        printf("Please input a command. Type h for help.\n");
        scanf(" %c", &choice);
        switch (choice) {
            case 'h':
                printf("Commands:\nh - Help: shows a list of commands\nq - Quit: Exits the program\n"
                       "m - Movie Control: Edit/Add/Remove movies in the movie database\na - Actor Control: Edit/Add/Remove actors in the actor database\n");
                break;
            case 'q':
                running = 0;
                break;
            case 'm':
                movie_controls();
                break;
            case 'a':
                actor_controls();
                break;
            default:
                printf("Please input a valid command. Input 'h' for a list of commands\n");
        }

        // Clear the input buffer
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }

    // Free the nodes before ending the program
    freeDatabases();
    return 0;
}