#pragma once

const int INIT_SUCCESS = 0;
typedef sf::RenderWindow* PRenderWindow;

namespace util {

	//--use sf::vertex
	//typedef struct COORD {
	//	int X;
	//	int Y;
	//}Coord, * PCoord;
	
	typedef struct LINECOORDS {
		sf::Vertex A;
		sf::Vertex B;
	}LineCoords, * PLineCoords;
};