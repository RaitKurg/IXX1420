all:
	@echo "Run 'make' with:"
	@echo "\tcompile - normal compile"
	@echo "\trun - start program"
	@echo "\tdebug - switches to branch 'gui-debug', compiles with graphical interface"
	@echo "\tinstall-sdl - installs SDL2 (needed for 'gui-debug')"

compile:
	g++ -std=c++11 main.cpp Base/*.cpp Radar/*.cpp Move/*.cpp Map/*.cpp -o robot

run:
	./robot

debug:
	git checkout gui-debug ;
	@echo "\033[0;32mCompiling with gui debug features\033[0m"
	@echo "Make sure you have -lSDL2 installed"
	@echo "To install SDL2, run 'make install-sdl'"
	g++ -std=c++11 main.cpp Base/*.cpp Radar/*.cpp Move/*.cpp Map/*.cpp GuiTools/*.cpp -w -lSDL2 -o robot

install-sdl:
	sudo apt-cache search libsdl2
	sudo apt-get install libsdl2-dev