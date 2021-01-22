#include "allincludes.h"

int init(Fractals* fractals) {
	sf::ContextSettings conSet;
	conSet.antialiasingLevel = 8;
	PRenderWindow pWindow = new sf::RenderWindow(sf::VideoMode(800, 700), "", sf::Style::Close | sf::Style::Resize, conSet);

	pWindow->setVerticalSyncEnabled(true);											//V-sync
	//ShowWindow(GetConsoleWindow(), SW_HIDE);										//Hide Window
	srand((unsigned int)time(NULL));												//non-psuedo random numbers
	
	if (fractals->init(pWindow) != INIT_SUCCESS)
		return EXIT_FAILURE;

	return INIT_SUCCESS;
}

int main()
{
	int returnVal;
	Fractals *fractals;
	{
		fractals = new Fractals();
		if (init(fractals) != INIT_SUCCESS)
			return EXIT_FAILURE;

		returnVal = fractals->run();
		delete fractals;
	}
	return returnVal;
}