/**
 * @author Michael Quick 251287228
 * @date 23/11/28
 * Contains all the functions for actors and the actor database
 */

#include "movieTheatreDB_actor.h"
#include "movieTheatreDB.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The first and last actors in the node are set to NULL to start
struct ActorNode *firstActor = NULL;
struct ActorNode *lastActor = NULL;

/**
 * An actor that can be added to the database
 */
struct Actor {
    int code;
    char name[50];
    int age;
    char IMDB[50];
};

/**
 * Adds an actor to the linked list database
 * @param actor the actor to be added to the database
 */
void addActorNode(struct Actor actor) {
    struct ActorNode *newNode = malloc(sizeof(struct ActorNode));
    if (newNode == NULL) {
        // Allocation failure
        return;
    }

    newNode->actor = malloc(sizeof(struct Actor));
    if (newNode->actor == NULL) {
        // Allocation failure
        free(newNode);
        return;
    }

    // Copy the contents of the passed Actor struct into the node's Actor struct
    newNode->actor->code = actor.code;
    strcpy(newNode->actor->name, actor.name);
    strcpy(newNode->actor->IMDB, actor.IMDB);
    newNode->actor->age = actor.age;

    newNode->next = NULL;

    if (firstActor == NULL) {
        // There is no first node in the database
        newNode->prev = NULL;
        firstActor = newNode;
        lastActor = newNode;
    } else {
        // Make newNode the last node in the list
        lastActor->next = newNode;
        newNode->prev = lastActor;
        lastActor = newNode;
    }
}

/**
 * Creates an actor with user input and then calls addActorNode to add it to the database
 */
void insertActor() {
    struct Actor newActor;

    // Clear the input stream
    fgetc(stdin);

    // Prompt user for the actor's code
    printf("Please enter the actor's code: ");
    scanf("%d", &newActor.code);

    struct ActorNode *n = firstActor;
    while (n != NULL) {
        if (n->actor->code == newActor.code) {
            printf("Code already exists! Please enter a new code!\n");
            return;
        }
        n = n->next;
    }

    // If the code given is not greater than zero, then print an error
    if (newActor.code < 0) {
        printf("Invalid code! Please enter a positive digit\n");
        return;
    }

// Clear the input buffer
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    // Prompt user for the actor's name
    printf("Please enter the actor's name: ");
    fgets(newActor.name, MAX_NAME_LEN, stdin);

    // Clear the input buffer again
    if (strchr(newActor.name, '\n') == NULL) {
        while ((c = getchar()) != '\n' && c != EOF);
    }

    // Prompt user for the actor's IMDB profile page
    printf("Please enter the actor's IMDB profile: ");
    fgets(newActor.IMDB, MAX_LINK_LEN, stdin);

    // Clear the input buffer again
    if (strchr(newActor.IMDB, '\n') == NULL) {
        while ((c = getchar()) != '\n' && c != EOF);
    }

    // Prompt user for the actor's age
    printf("Please enter the actor's age: ");
    scanf(" %d", &newActor.age);

    // If the age is not between 0 and 120, produce an error
    if (newActor.age < 0 || newActor.age > 120) {
        printf("Invalid age! Please enter an age between 0 and 120!\n");
        return;
    }

    // Add the movie to the database
    addActorNode(newActor);
}

/**
 * Searches for a selected actor
 */
void searchActor() {
    int code;
    int found = 0;

    // Prompt user for the actor code
    printf("Please enter the actor's code: ");
    scanf(" %d", &code);

    // Search for the actor in database
    struct ActorNode *n = firstActor;
    while (n != NULL) {
        if (n->actor->code == code) {
            // Actor found, update integer and print the actor's info
            found = 1;
            printf("Actor Code: %d\nActor Name: %sActor Age: %dActor IMDB: %s\n", n->actor->code,
                   n->actor->name, n->actor->age, n->actor->IMDB);
            break;
        }

        n = n->next;
    }

    // Inform user if the actor wasn't found
    if (found == 0) {
        printf("Actor not found! Please try another code!\n");
    }
}

/**
 * Erases a selected actor
 */
void eraseActor() {
    int code;
    printf("Please type the code of the actor that is being erased:\n");
    scanf(" %d", &code);

    struct ActorNode *n = firstActor;
    while (n != NULL && n->actor->code != code) {
        n = n->next;
    }

    if (n == NULL) {
        printf("Actor not found! Please try another code!\n");
        return;
    }

    if (firstActor == n) {
        firstActor = n->next;
        if (firstActor != NULL) {
            firstActor->prev = NULL;
        }
    } else if (lastActor == n) {
        lastActor = n->prev;
        if (lastActor != NULL) {
            lastActor->next = NULL;
        }
    } else {
        n->prev->next = n->next;
        n->next->prev = n->prev;
    }

    free(n);

    // Make n null to prevent accidental calls
    n = NULL;
}

/**
 * Updated a selected actor
 */
void updateActor() {
    int code;
    int found = FALSE;

    // Prompt user for movie code
    printf("Please enter the actor code: ");
    scanf(" %d", &code);

    // Search for an actor in database
    struct ActorNode *n = firstActor;
    while (n != NULL) {
        if (n->actor->code == code) {
            // Actor found, update integer
            found = TRUE;

            // Create a temp actor with the actor code
            struct Actor temp;

            // Clear the input stream
            fgetc(stdin);

            // Prompt user for the actor's name
            printf("Please enter the actor's name: ");
            fgets(temp.name, MAX_NAME_LEN, stdin);

            // Prompt user for the actor's IMDB profile page
            printf("Please enter the actor's IMDB profile: ");
            fgets(temp.IMDB, MAX_LINK_LEN, stdin);

            // Prompt user for the actor's age
            printf("Please enter the actor's age: ");
            scanf(" %d", &temp.age);

            // If the age is not between 0 and 120 then print an error and don't update the actor
            if (n->actor->age < 0 || n->actor->age > 120) {
                printf("Invalid age! Please enter between 0 and 120!\n");
                break;
            } else {
                // If no errors then update the movie
                strcpy(n->actor->name, temp.name);
                strcpy(n->actor->IMDB, temp.IMDB);
                n->actor->age = temp.age;
            }
            break;
        }
    }

    // If the actor is not found, print an error
    if (found == FALSE) {
        printf("Movie not found! Please try another code!\n");
    }
}

/**
 * Prints information about the actors in the database
 */
void printActors() {
    struct ActorNode *n = firstActor;

    while (n != NULL) {
        printf("Actor Code: %d\nActor Name: %sActor IMDB: %sActor Age: %d\n\n", n->actor->code, n->actor->name,
               n->actor->IMDB, n->actor->age);
        n = n->next;
    }
}

/**
 * Takes in user input and determines the correct function to use
 */
void actorControls() {
    char choice;
    printf("--------------------\nActor Controls:\n");
    printf("i - Insert a new actor\ns - Search for an actor\nu - Update an actor\np - Print actor list\ne - Erase an actor\n");
    printf("Please type an Actor command:\n");
    scanf(" %c", &choice);
    printf("--------------------\n");


    switch (choice) {
        case 'i':
            insertActor();
            break;
        case 's':
            searchActor();
            break;
        case 'u':
            updateActor();
            break;
        case 'p':
            printActors();
            break;
        case 'e':
            eraseActor();
            break;
        default:
            printf("Invalid command, please input a valid command!\n");
    }

    printf("--------------------\n");
}

/**
 * Frees the actors and their nodes
 */
void freeActorDatabase() {
    struct ActorNode *current = firstActor;

    while (current != NULL) {
        struct ActorNode *temp = current;
        current = current->next;

        free(temp->actor); // Free the Actor data within the node
        free(temp); // Free the node itself
    }

    firstActor = NULL; // Reset the first pointer to indicate an empty list
    lastActor = NULL; // Reset the last pointer to indicate an empty list
}