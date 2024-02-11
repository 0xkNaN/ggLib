build:
	g++ ./main.cpp ./framework/*.cpp -lstdc++ -lSDL2 -lz -o game

# ./framework/include/*.cpp