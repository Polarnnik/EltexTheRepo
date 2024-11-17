TARGET = main

SRCS = main.c linkedList.c contacts.c

OBJS = $(SRCS:.c=.o)

main: $(OBJS)
	gcc $(OBJS) -o $(TARGET)

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

