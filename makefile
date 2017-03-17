CC = gcc
CFLAGS = -g -Wall -std=c11
TARGET =
DEPS =

default: $(TARGET)

$(TARGET): $(TARGET).c $(DEPS)
	$(CC) $(CFLAGS) $(TARGET).c $(DEPS) -o $(TARGET)

graph.o: src/graph.c include/graph.h linked_list.o hash_table.o
	$(CC) $(CFLAGS) -c src/graph.c

hash_table.o: src/hash_table.c include/hash_table.h linked_list.o
	$(CC) $(CFLAGS) -c src/hash_table.c

linked_list.o: src/linked_list.c include/linked_list.h
	$(CC) $(CFLAGS) -c src/linked_list.c

priority_queue.o: src/priority_queue.c include/priority_queue.h
	$(CC) $(CFLAGS) -c src/priority_queue.c

queue.o: src/queue.c include/queue.h
	$(CC) $(CFLAGS) -c src/queue.c

stack.o: src/stack.c include/stack.h
	$(CC) $(CFLAGS) -c src/stack.c

clean:
	rm *.o $(TARGET)