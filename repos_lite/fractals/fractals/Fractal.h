#pragma once
#include "allincludes.h"

using util::LineCoords;

class Fractal
{
	PRenderWindow pWindow;
	sf::Vertex line[2];
	sf::Vector2f *p1, *p2;

public:
	Fractal();
	~Fractal();
	int init(PRenderWindow pWin, sf::Vector2f *A, sf::Vector2f *B);
	void processEvent(sf::Event event);
	void update();
	void display();
};

