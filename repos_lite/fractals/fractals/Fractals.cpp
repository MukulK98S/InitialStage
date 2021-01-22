#include "allincludes.h"

Fractals::Fractals() {
	
}

Fractals::~Fractals() {
	//delete stuff;
}

int Fractals::init(PRenderWindow pWin) {
	this->pWindow = pWin;
	this->frameCounter = 0;
	Title = "Fractals";
	this->allPoints;

	std::vector<Fractal> tmpVec;
	Fractal tmpFract;
	tmpFract.init(
		this->pWindow, 
		sf::Vector2f((float)(this->pWindow->getSize().x / 2), 0.0), 
		sf::Vector2f((float)(this->pWindow->getSize().x / 2), (float)(this->pWindow->getSize().y / 4)));

	tmpVec.push_back(tmpFract);
	//this->fractalHolder.push_back(;

	this->oneToMany = 3;
	this->levels = 3;
	this->angleSpan = 30;

	//game = new Game();

	return INIT_SUCCESS;
}
//don't touch
int Fractals::run() {

	clock_t frameStart = 1, frameEnd = 2, counter = 0;
	int frames = 0;

	while (pWindow->isOpen())
	{
		frameStart = clock();

		while (pWindow->pollEvent(event))
		{
			processEvent(event);
		}
		update();
		display();

		frameEnd = clock();
		frameCounter++;
		frameTime = frameEnd - frameStart;
		dt = (float)frameTime / 100;
		countFrameTime();
	}

	return EXIT_SUCCESS;
}

void Fractals::processEvent(sf::Event event) {
	if (event.type == sf::Event::Closed)
	{
		this->pWindow->close();
	}
	if (event.type == sf::Event::Resized)
	{
		//cout << pWindow->getSize().x << "," << pWindow->getSize().y << endl;
		this->pWindow->setSize(sf::Vector2u(pWindow->getSize().x, pWindow->getSize().y));
	}
	//.processEcent()
}

void Fractals::update() {
	//.update()
}

void Fractals::display() {
	this->pWindow->clear(sf::Color::Color(0, 0, 0, 255));

	//for (auto f : this->fractalVector) {
	//	f.display();
	//}
	
	this->pWindow->display();
}

void Fractals::countFrameTime() {

	static int frames = 0;
	static clock_t counter = 0;
	counter += frameTime;
	frames++;
	if (counter > 500) {
		// *N: no need to check for divide by 0, frames always atleast 1 in this block
		this->pWindow->setTitle(Title + "# frame time : " + std::to_string((float)counter / frames) + " ms"
			+ "# FPS : " + std::to_string(1000.0 * frames / (float)counter)
			+ "# dt : " + std::to_string(dt));
		//testMessage.setString(std::to_string(frameStart) + ", " + std::to_string(frameEnd));
		counter = 0;
		frames = 0;
	}
}

void Fractals::addNewFractal()
{
}
