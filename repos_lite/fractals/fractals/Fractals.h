#pragma once
#include "allincludes.h"
class Fractals
{
	unsigned long long frameCounter;
	PRenderWindow pWindow{};
	std::string Title;
	sf::Event event{};
	clock_t frameTime;
	float dt;

	std::vector< std::vector<Fractal> > fractalHolder;
	std::vector< sf::Vector2f > allPoints;

	int oneToMany;
	int levels;
	int angleSpan;

public:
	Fractals();
	~Fractals();
	int init(PRenderWindow pWin);
	int run();
	void processEvent(sf::Event event);
	void update();
	void display();
	void countFrameTime();
	
	void addNewFractal();
};

