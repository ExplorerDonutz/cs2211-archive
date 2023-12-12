#ifndef MOVIETHEATREDB_ACTOR_H
#define MOVIETHEATREDB_ACTOR_H

struct ActorNode {
    struct Actor *actor;
    struct ActorNode *prev;
    struct ActorNode *next;
};

// Functions used in the main class
void actorControls();
void freeActorDatabase();
#endif //MOVIETHEATREDB_ACTOR_H
