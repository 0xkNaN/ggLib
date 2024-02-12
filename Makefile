build:
	g++ ./main.cpp ./framework/*.cpp -lstdc++ -lSDL2 -lSDL2_image -lz -o game

# ./framework/include/*.cpp