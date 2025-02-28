
TARGET = zverc

CC = g++

$(TARGET) : main.o zverc.o
	$(CC) $^ -o $@

main.o : main.cpp zverc.h
	$(CC) -Iinclude -c $< -o $@

zverc.o : zverc.cpp zverc.h
	$(CC) -Iinclude -c $< -o $@

clean : 
	rm -f zverc zverc.o main.o
