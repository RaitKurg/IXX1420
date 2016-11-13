compile:
	g++ -std=c++11 main.cpp Base/*.cpp Radar/*.cpp Move/*.cpp Map/*.cpp -o robot

run:
	./robot

debug:
	@echo "\033[0;32mCompiling with gui debug features\033[0m"
	@echo "Make sure you are on a branch \033[0;33mgui-debug\033[0m and have -lSDL2 installed"
	@echo "To install SDL2, run 'make install-sdl'"
	g++ -std=c++11 main.cpp Base/*.cpp Radar/*.cpp Move/*.cpp Map/*.cpp -w -lSDL2 -o robot

install-sdl:
	sudo apt-cache search libsdl2
	sudo apt-get install libsdl2-dev