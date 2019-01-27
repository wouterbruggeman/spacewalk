#include "main.h"

int main(int argc, char *argv[]){
	int exitStatus;

	Game *game = new Game();
	game->start();

	while(true){
		//Loop the game
		exitStatus = game->loop();

		//If the game has to be restarted
		if(exitStatus == Game::RESTART){
			//Stop the game and create a new game
			game->stop();
			game = new Game();
			game->start();
		}else if(exitStatus == Game::EXIT){
			//Stop the game, but do not restart
			game->stop();
			break;
		}
	}
	return 0;
}
