#include "main.h"



int main(int argc, char *argv[]){
	Game game = Game();
	game.start();

	while(game.isRunning()){
		game.loop();
	}
	return 0;
}
