#pragma once
#include <vector>
#include <random>
#include <iostream>
#include <algorithm>
#include "GudeKlassen.h"
#include "Image.hpp"
#include "PPMLoader.hpp"

using namespace rw::sensor;
using namespace rw::loaders;

class Coordinates
{
public:
	Coordinates();
	Coordinates(int n);
	Coordinates(int x, int y);
	~Coordinates();

	/*This function finds collinear points*/
	void findCollinearPoints();

	/*This function prints all the coordinates*/
	void printCoordinates();

	/*This prints all coordinates and the slope each coordinate has to another coordinate*/
	void printSlopes();

	/*This prints the groups of collinear points*/
	void printCollinearPoints();
	
	/*This function is for drawing purposes, it has been out commented because it requires some setup to work*/
	/*void setMap(Image * inputMap);*/

	/*This function is for drawing purposes, it has been out commented because it requires some setup to work*/
	/*void drawGroups();*/

	double slope;

private:
	std::vector<std::vector<Coordinates*>> coordinates;
	std::vector<std::vector<Coordinates*>> fourOrMoreCollinear;

	/*This function calculate each slope a Coordinate has to another*/
	void determineSlopes();

	/*This is a help function to std::sort, it sorts a coordinates slopes in ascending order*/
	static bool compareSlopes(const Coordinates * x1y1, const Coordinates * x2y2);

	/*This returns x-coordinate of a coordinate*/
	int getCoordinateX();

	/*This returns y-coordinate of a coordinate*/
	int getCoordinateY();

	/*This returns a slope of a coordinate*/
	double getSlope();

	/*This sets a slope of a coordinate*/
	void setSlope(double a);

	/*This function is used in the Coordinate constructor, and it removes dublicate coordinates and tries to generate a new*/
	void removeDublicateCoordinates();

	/*This is a random numer generator*/
	int randomNumber();

	/*This function is for drawing purposes, it has been out commented because it requires some setup to work*/
	/*void drawStraightLine(int x0, int y0, int x1, int y1);*/
	
	Image* map;
	int coordinateX;
	int coordinateY;
};

