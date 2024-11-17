CC = gcc
CFLAGS = -Wall -fPIC
LDFLAGS = -shared

LIB_NAME = liblinkedlist.so
MAIN_APP = mainApp

LIB_SRC = linkedList.c contacts.c
LIB_OBJ = linkedList.o contacts.o
MAIN_SRC = main.c

$(LIB_NAME): $(LIB_OBJ)
	$(CC) $(LDFLAGS) -o $(LIB_NAME) $(LIB_OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(MAIN_APP): $(MAIN_SRC) $(LIB_NAME)
	$(CC) $(MAIN_SRC) -L. -Wl,-rpath=. -llinkedlist -o $(MAIN_APP)

.PHONY: clean
clean:
	rm -f $(LIB_OBJ) $(LIB_NAME) $(MAIN_APP)
