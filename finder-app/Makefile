CC=$(CROSS_COMPILE)gcc
writer: writer.o
	$(CC) -o writer writer.o
writer.o: writer.c
	$(CC) -o writer.o -c writer.c
clean:
	rm -f writer
	rm -f *.o
