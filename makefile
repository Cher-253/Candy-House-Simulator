SRC1 = Code6_1001759133.cpp
SRC2 = TrickOrTreater.cpp
SRC3 = House.cpp
SRC4 = CandyHouse.cpp
SRC5 = ToothbrushHouse.cpp

OBJ1 = $(SRC1:.cpp=.o)
OBJ2 = $(SRC2:.cpp=.o)
OBJ3 = $(SRC3:.cpp=.o)
OBJ4 = $(SRC4:.cpp=.o)
OBJ5 = $(SRC5:.cpp=.o)

EXE = $(SRC1:.cpp=.e)

HFILE1 = TrickOrTreater.h
HFILE2 = House.h
HFILE3 = CandyHouse.h
HFILE4 = ToothbrushHouse.h

CFLAGS = -g -std=c++11 -pthread

all: $(EXE)

$(EXE): $(OBJ1) $(OBJ2) $(OBJ3) $(OBJ4) $(OBJ5)  
	g++ $(CFLAGS) $(OBJ1) $(OBJ2) $(OBJ3) -o $(EXE)  

$(OBJ1) : $(SRC1) $(HFILE1) $(HFILE2) $(HFILE3) $(HFILE4)
	g++ -c $(CFLAGS) $(SRC1) -o $(OBJ1) 

$(OBJ2) : $(SRC2) $(HFILE1) $(HFILE2) $(HFILE3) $(HFILE4)
	g++ -c $(CFLAGS) $(SRC2) -o $(OBJ2) 

$(OBJ3) : $(SRC3) $(HFILE1) $(HFILE2) $(HFILE3) $(HFILE4)
	g++ -c $(CFLAGS) $(SRC3) -o $(OBJ3) 

$(OBJ4) : $(SRC4) $(HFILE1) $(HFILE2) $(HFILE3) $(HFILE4)
	g++ -c $(CFLAGS) $(SRC4) -o $(OBJ4) 

$(OBJ5) : $(SRC5) $(HFILE1) $(HFILE2) $(HFILE3) $(HFILE4)
	g++ -c $(CFLAGS) $(SRC5) -o $(OBJ5) 