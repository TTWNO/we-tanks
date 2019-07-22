default: linux

linux:
	g++ -c main.cpp -I./SFML-linux/include
	g++ main.o -o we-tanks -L./SFML-linux/lib -lsfml-system -lsfml-graphics -lsfml-window

linux-run:
	LD_LIBRARY_PATH=./SFML-linux/lib ./we-tanks
