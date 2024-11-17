CC = gcc
CFLAGS = -Wall -std=c11

LIB_NAME = liblinkedlist.a
MAIN_EXEC = main

LIB_SRC = linkedList.c
CONTACTS_SRC = contacts.c
MAIN_SRC = main.c
OBJS = linkedList.o contacts.o

$(LIB_NAME): $(LIB_SRC)
	$(CC) $(CFLAGS) -c $(LIB_SRC)
	ar rcs $(LIB_NAME) linkedList.o

$(MAIN_EXEC): $(MAIN_SRC) $(CONTACTS_SRC) $(LIB_NAME)
	$(CC) $(CFLAGS) -c $(CONTACTS_SRC)
	$(CC) $(CFLAGS) -c $(MAIN_SRC)
	$(CC) -o $(MAIN_EXEC) main.o contacts.o -L. -llinkedlist

clean:
	rm -f *.o $(LIB_NAME) $(MAIN_EXEC)
