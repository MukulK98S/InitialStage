#include "allincludes.h"

Fractal::Fractal()
{
}

Fractal::~Fractal()
{
}

int Fractal::init(PRenderWindow pWin, sf::Vector2f *A, sf::Vector2f *B)
{
	this->pWindow = pWin;
	this->p1 = A;
	this->p2 = B;
	return INIT_SUCCESS;
}

void Fractal::processEvent(sf::Event event)
{

}

void Fractal::update()
{

}

void Fractal::display()
{
	this->line[0].position = *this->p1;
	this->line[1].position = *this->p2;
	this->pWindow->draw(this->line, 2, sf::Lines);
}
