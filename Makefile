CXXFLAGS=-O2 -march=native

OBJS=tank.o
INCS=-I./SFML-linux-gcc/include
LIBS=-lsfml-system -lsfml-graphics -lsfml-window
CXXC=g++

default: linux

linux:
	$(CXXC) $(CXXFLAGS) -c tank.cpp $(INCS)
	$(CXXC) $(CXXFLAGS) -c main.cpp $(INCS)
	$(CXXC) $(CXXFLAGS) $(OBJS) main.o -L./SFML-linux-gcc/lib $(LIBS) -o we-tanks

linux-run: linux
	LD_LIBRARY_PATH=./SFML-linux-gcc/lib ./we-tanks
