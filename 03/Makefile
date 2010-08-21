CFLAGS = -Werror -Wall -std=c99 -g3

linkedlist.o: linkedlist.c
	gcc $(CFLAGS) -c -o $@ $<
%: %.c 
	gcc $(CFLAGS) -o $@ linkedlist.o $<
