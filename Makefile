default: linux

linux:
	g++ -c main.cpp -I./SFML-linux-gcc/include
	g++ main.o -L./SFML-linux-gcc/lib -lsfml-system -lsfml-graphics -lsfml-window -lsfml-window -o we-tanks

linux-run:
	LD_LIBRARY_PATH=./SFML-linux/lib ./we-tanks
