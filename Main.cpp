#include <iostream>
#include "Game.h"

//using namespace sf;

int main()
{
	//Init srand
	srand(static_cast<unsigned>(time(NULL)));

	//init game engine
	Game game;

	//Game Loop
	while (game.running() && !game.getEndGame())
	{

		//update
		game.update();

		//Render
		game.render();

	}
	//end of application
	return 0;
}