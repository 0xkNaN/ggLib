build:
	g++ ./main.cpp ./framework/*.cpp ./framework/include/*.cpp -lstdc++ -lSDL2 -lSDL2_image -lz -o game