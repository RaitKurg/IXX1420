compile:
	g++ -std=c++11 main.cpp Base/*.cpp Radar/*.cpp Move/*.cpp Map/*.cpp -o robot

run:
	./robot