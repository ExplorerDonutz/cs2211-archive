/**
 * @author Michael Quick (251287228)
 * @date 2023/11/14
 * Allows a user to create, update, search for, and print movies in a database
 */

#include <stdio.h>
#include <stdlib.h>

const int MAX_TITLE_SIZE = 100;
const int MAX_GENRE_SIZE = 25;

/**
 * Holds the details of the movie
 */
struct movie {
    int code;
    char title[100];
    char genre[25];
    float rating;
};

struct movie *movies = NULL;
int movieCount = 0;

/**
 * Create the database with a size of one movie
 */
void initDatabase() {
    // Create a new pointer that will act as a dynamic array
    movies = (struct movie *) malloc(sizeof(struct movie));

    // Check if the memory was allocated
    if (movies == NULL) {
        printf("Memory not allocated to database!\n");
        exit(EXIT_FAILURE);
    }
}

/**
 * A function to add a movie to the database
 * @param newMovie the movie to be added to the database
 */
void addToDatabase(struct movie newMovie) {
    // Create a temporary pointer
    struct movie *temp = realloc(movies, (movieCount + 1) * sizeof(struct movie));

    // Check if memory was allocated to the temporary pointer
    if (temp == NULL) {
        printf("Memory reallocation failed!\n");
        free(movies);
        exit(EXIT_FAILURE);
    }

    // Replace the database with the temporary database
    movies = temp;

    // Add the new movie to the database and update the movie count
    movies[movieCount] = newMovie;
    movieCount++;
}

/**
 * A function to create new movies to add to the database
 */
void addMovie() {
    struct movie newMovie;

    // Clear the input stream
    fgetc(stdin);

    // Prompt user for movie code
    printf("Please enter the movie code: ");
    scanf("%d", &newMovie.code);


    for (int i = 0; i < movieCount; i++) {
        if (movies[i].code == newMovie.code) {
            printf("Code already exists! Please enter a new code!\n");
            return;
        }
    }

    // If the code given is not greater than zero, then print an error
    if (newMovie.code < 0) {
        printf("Invalid code! Please enter a positive digit\n");
        return;
    }

    // Clear the input stream
    fgetc(stdin);

    // Prompt user for movie name
    printf("Please enter the movie name: ");
    fgets(newMovie.title, MAX_TITLE_SIZE, stdin);

    // Prompt user for movie genre
    printf("Please enter the movie genre: ");
    fgets(newMovie.genre, MAX_GENRE_SIZE, stdin);

    // Prompt user for movie rating
    printf("Please enter the movie rating: ");
    scanf("%f", &newMovie.rating);

    // If the rating given is not within 0.0 - 10.0 then print an error
    if (newMovie.rating < 0.0 && newMovie.rating > 10.0) {
        printf("Invalid rating! Please enter between 0.0 and 10.0!\n");
        return;
    }

    // Clear the input stream
    fgetc(stdin);

    // Add the movie to the database
    addToDatabase(newMovie);

    // Add a space
    printf("\n");
}

/**
 * A function that searches the movie database for a given movie code
 */
void findMovie() {
    int code;
    int found = 0;

    // Prompt user for movie code
    printf("Please enter the movie code: ");
    scanf(" %d", &code);

    // Search for movie in database
    for (int i = 0; i < movieCount; i++) {
        if (movies[i].code == code) {
            // Movie found, update integer and print the movie info
            found = 1;
            printf("Movie Code: %d\nMovie Name: %sMovie Genre: %sMovie Rating: %.1f\n", movies[i].code,
                   movies[i].title, movies[i].genre, movies[i].rating);
            break;
        }
    }

    // Inform user if movie wasn't found
    if (found == 0) {
        printf("Movie not found! Please try another code!\n");
    }

    // Add a space
    printf("\n");
}

/**
 * A function for updating movie details
 */
void updateMovie() {
    int code;
    int found = 0;

    // Prompt user for movie code
    printf("Please enter the movie code: ");
    scanf(" %d", &code);

    // Search for movie in database
    for (int i = 0; i < movieCount; i++) {
        if (movies[i].code == code) {
            // Movie found, update integer
            found = 1;

            // Create a temp movie with the movie code
            struct movie temp = {movies[i].code};

            // Clear the input stream
            fgetc(stdin);

            // Prompt user for movie name
            printf("Please enter the movie name: ");
            fgets(temp.title, MAX_TITLE_SIZE, stdin);

            // Prompt user for movie genre
            printf("Please enter the movie genre: ");
            fgets(temp.genre, MAX_GENRE_SIZE, stdin);

            // Prompt user for movie rating
            printf("Please enter the movie rating: ");
            scanf("%f", &temp.rating);

            // If the rating given is not within 0.0 - 10.0 then print an error and don't update the movie
            if (movies[i].rating < 0.0 && movies[i].rating > 10.0) {
                printf("Invalid rating! Please enter between 0.0 and 10.0!\n");
                break;
            } else {
                // If no errors then update the movie
                movies[i] = temp;
            }
            break;
        }
    }

    // If movie not found, print an error
    if (found == 0) {
        printf("Movie not found! Please try another code!\n");
    }

    // Add a space
    printf("\n");
}

/**
 * A function that prints all the movies in the database
 */
void printDatabase() {
    // Print all the movies and their details
    for (int i = 0; i < movieCount; i++) {
        printf("Movie Code: %d\nMovie Name: %sMovie Genre: %sMovie Rating %f\n\n", movies[i].code, movies[i].title,
               movies[i].genre, movies[i].rating);
    }
}

int main(void) {

    // Prepare input and initialize database
    char input = 0;
    initDatabase();

    // Main loop
    while (input != 'q') {
        // Prompt user for a command
        printf("Please type a command: ");
        scanf(" %c", &input);

        // Add a space
        printf("\n");

        // Use a function for the given command
        switch (input) {
            case 'i':
                addMovie();
                break;
            case 's':
                findMovie();
                break;
            case 'u':
                updateMovie();
                break;
            case 'p':
                printDatabase();
                break;
            case 'q':
                break;
            default:
                // Give user an error if they input an invalid command
                printf("Invalid input! Please use a valid code:\n"
                       "i - Insert new movie\n"
                       "s - Search for a movie in the database\n"
                       "u - Update a movie in the database\n"
                       "p - Print the entire list of movies\n"
                       "q- Quit the program\n\n");
        }
    }

    // Free the memory used by the dynamic array
    free(movies);
    return 0;
}
