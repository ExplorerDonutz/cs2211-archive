CC=gcc

CFLAGS = -Wall -Wextra

TARGET = movieTheatreDB

SRCS = movieTheatreDB.c movieTheatreDB_movie.c movieTheatreDB_actor.c

OBJS = $(SRCS:.c=.o)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)