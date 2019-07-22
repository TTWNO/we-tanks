default: linux

linux:
	g++ main.cpp -L./SFML-linux-gcc/lib -I./SFML-linux-gcc/include -lsfml-system -lsfml-graphics -lsfml-window -o main.out

linux-run:
	LD_LIBRARY_PATH=./SFML-linux-gcc/lib ./main.out
