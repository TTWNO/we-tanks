CC=g++

default: all

all:
	$(CC) main.cpp -L./SFML-2.5.1/lib -I./SFML-2.5.1/include -lsfml-system -lsfml-graphics -lsfml-window -o main.out

run:
	LD_LIBRARY_PATH=./SFML-2.5.1/lib ./main.out
