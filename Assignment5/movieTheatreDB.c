/**
 * @author Michael Quick 251287228
 * @date 23/11/28
 * Creates a database for actors and movies that can complete multiple tasks for the user
 */

#include <stdio.h>
#include "movieTheatreDB_movie.h"
#include "movieTheatreDB_actor.h"
#include "movieTheatreDB.h"

/**
 * The main function with the program's loop
 * @return the end of the program
 */
int main(void) {
    char choice;
    int running = TRUE;
    while (running == TRUE) {
        printf("Please input a command. Type h for help.\n");
        scanf(" %c", &choice);
        switch (choice) {
            case 'h':
                printf("Commands:\nh - Help: shows a list of commands\nq - Quit: Exits the program\n"
                       "m - Movie Control: Edit/Add/Remove movies in the Movie database\na - Actor Control: Edit/Add/Remove actors in the actor database\n");
                break;
            case 'q':
                running = FALSE;
                break;
            case 'm':
                movieControls();
                break;
            case 'a':
                actorControls();
                break;
            default:
                printf("Please input a valid command. Input 'h' for a list of commands\n");
        }

        // Clear the input buffer
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }

    // Free the nodes before ending the program
    freeMovieDatabase();
    freeActorDatabase();
    return 0;
}