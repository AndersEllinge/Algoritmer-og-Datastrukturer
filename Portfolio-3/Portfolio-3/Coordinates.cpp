#include "Coordinates.h"



Coordinates::Coordinates()
{
	//coordinates.resize(100);
	for (size_t i = 0; i < 30; i++)
	{
		for (size_t j = 0; j < 30; j++)
		{
			coordinates.push_back({ new Coordinates(i, j) });
		}
	}
	//removeDublicateCoordinates();

	for (size_t k = 0; k < coordinates.size(); k++) {
		for (size_t j = 0; j < coordinates.size(); j++) {
			if (!(j == k)) { // if j == k, then its the same coordinate
				coordinates[k].push_back(new Coordinates(coordinates[j][0]->coordinateX, coordinates[j][0]->coordinateY));
			}
		}
	}
}

Coordinates::Coordinates(int n)
{
	coordinates.resize(n);
	for (size_t i = 0; i < n; i++)
	{
		coordinates[i].push_back(new Coordinates(randomNumber(), randomNumber())); // Create the coordinates
	}
	removeDublicateCoordinates();

	for (size_t k = 0; k < coordinates.size(); k++) {
		for (size_t j = 0; j < coordinates.size(); j++) {
			if (!(j == k)) { // if j == k, then its the same coordinate
				coordinates[k].push_back(new Coordinates(coordinates[j][0]->coordinateX, coordinates[j][0]->coordinateY)); // These coordinates are related to the coordinates in the previous for loop.
			}																											   // Its to make a list of slopes for every coordinate.
		}																												   // coordinate[][{coordinate, slope1, slope2, slope3 ... slopeN}].
	}																													   // These are going to be sorted, so having the x y information aswell is needed,
}																														   // therefore all these objects. (tried to do this without objects and could not
																														   // determine which coordinates a slope was associated with after the sort)
Coordinates::Coordinates(int x, int y)
{
	coordinateX = x;
	coordinateY = y;
	slope;
}

Coordinates::~Coordinates()
{
}

void Coordinates::printCoordinates()
{
	std::cout << "Coordinates are: " << std::endl;
	for (size_t i = 0; i < coordinates.size(); i++)
		/*for (size_t j = 0; j < coordinates[i].size(); j++)*/
			std::cout << "(" << coordinates[i][0]->getCoordinateX() << ", " << coordinates[i][0]->getCoordinateY() << ")" << " ";
	std::cout << std::endl;
	std::cout << std::endl;
}

void Coordinates::printSlopes()
{
	std::cout << "Slopes are: " << std::endl;
	for (size_t i = 0; i < coordinates.size(); i++) {
		std::cout << "(" << coordinates[i][0]->getCoordinateX() << ", " << coordinates[i][0]->getCoordinateY() << ")" << std::endl;
		for (size_t j = 1; j < coordinates[i].size(); j++)
			std::cout << coordinates[i][j]->getSlope() << ", ";
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void Coordinates::printCollinearPoints()
{
	for (size_t i = 0; i < fourOrMoreCollinear.size(); i++) {
		std::cout << "Group of collinear coordinates with slope: " << fourOrMoreCollinear[i][0]->getSlope() << std::endl;
		for (size_t j = 0; j < fourOrMoreCollinear[i].size(); j++)
		{
			std::cout << "(" << fourOrMoreCollinear[i][j]->getCoordinateX() << ", " << fourOrMoreCollinear[i][j]->getCoordinateY() << ")" << " ";
		}
		std::cout << std::endl;
	}
}

void Coordinates::setMap(Image * inputMap)
{
	map = inputMap;
}

void Coordinates::drawGroups()
{
	for (size_t i = 0; i < fourOrMoreCollinear.size(); i++)
	{
		for (size_t k = 1; k < fourOrMoreCollinear[i].size(); k++)
		{
			drawStraightLine(fourOrMoreCollinear[i][k]->coordinateX, fourOrMoreCollinear[i][k]->coordinateY, fourOrMoreCollinear[i][k - 1]->coordinateX, fourOrMoreCollinear[i][k-1]->coordinateY);
		}
	}

	for (size_t i = 0; i < coordinates.size(); i++)
	{
		map->setPixel8U(coordinates[i][0]->coordinateX, coordinates[i][0]->coordinateY, 0);
	}

	map->saveAsPGM("Map1.pgm");
}

void Coordinates::findCollinearPoints()
{
	determineSlopes(); // Calculate the slopes 

	for (size_t i = 0; i < coordinates.size(); i++)
	{
		std::sort(coordinates[i].begin()+1, coordinates[i].end(), & Coordinates::compareSlopes); // Now sort the slopes
	}
	
	int tmp = 0;
	for (size_t i = 0; i < coordinates.size(); i++)
	{
		for (size_t j = 2; j < coordinates[i].size(); j++)
		{
			if (coordinates[i][j]->getSlope() == coordinates[i][j - 1]->getSlope()) { // If current slope is equal to previous slope, we increment tmp.
				tmp++;
			}
			else {
				tmp = 0; // else we start over, since we need atleast 3 equal slopes in a row to have 4 collinear points. (which is tmp = 2) 
			}
			if (tmp > 2) { // if tmp is larger than 2, then we have more than 4 and we just pushback the coordinate.
				fourOrMoreCollinear[fourOrMoreCollinear.size()-1].push_back(coordinates[i][j]);
			}
			else if (tmp > 1) // if tmp is larger then 1, then we have found a group of 4 collinear points, i.e. 3 slopes are equal.
			{
				fourOrMoreCollinear.resize(fourOrMoreCollinear.size() + 1); // we increase the size of the vector holding the groups of collinear points
				fourOrMoreCollinear[fourOrMoreCollinear.size()-1].push_back(coordinates[i][j - 2]); // pushback the first, the current and last 2 coordinates.
				fourOrMoreCollinear[fourOrMoreCollinear.size()-1].push_back(coordinates[i][j - 1]); // we need the first, because its the coordinate related to the 3 slopes.
				fourOrMoreCollinear[fourOrMoreCollinear.size()-1].push_back(coordinates[i][j]);
				fourOrMoreCollinear[fourOrMoreCollinear.size()-1].push_back(coordinates[i][0]);
			}
		}
		tmp = 0;
	}
}

void Coordinates::determineSlopes()
{
	double inf = std::numeric_limits<double>::infinity(); // define infinity
	for (size_t k = 0; k < coordinates.size(); k++) {
		for (size_t j = 1; j < coordinates.size(); j++) {
			/*coordinates[k][j]->setSlope(round((((double)coordinates[k][j]->getCoordinateY() - (double)coordinates[k][0]->getCoordinateY())
				/ ((double)coordinates[k][j]->getCoordinateX() - (double)coordinates[k][0]->getCoordinateX()))* 1000.0) / 1000.0);*/
			if (((double)coordinates[k][j]->getCoordinateX() - (double)coordinates[k][0]->getCoordinateX()) == 0 ) // if x2-x1 is zero
			{
				coordinates[k][j]->setSlope(inf); // infinity slope when dividing by 0
			}
			else
			{
				coordinates[k][j]->setSlope(((double)coordinates[k][j]->getCoordinateY() - (double)coordinates[k][0]->getCoordinateY())
				/ ((double)coordinates[k][j]->getCoordinateX() - (double)coordinates[k][0]->getCoordinateX())); // This calculates and stores the slope in the coordinate
			}			
		}
	}
}

bool Coordinates::compareSlopes(const Coordinates * x1y1, const Coordinates * x2y2)
{
	return x1y1->slope < x2y2->slope;
}

int Coordinates::randomNumber()
{
	std::random_device rd; // obtain a random number from hardware
	std::mt19937 eng(rd()); // seed the generator
	std::uniform_int_distribution<> distr(0, 199); // define the range

	return distr(eng);
}

void Coordinates::drawStraightLine(int x0, int y0, int x1, int y1)
{
	if (x0 < x1) {
		int deltaX = x1 - x0;
		int deltaY = y1 - y0;

		if (y0 > y1)
			deltaY = y0 - y1;

		if (x0 > x1)
			deltaX = x0 - x1;

		if (deltaY < deltaX) {
			int deltaErr = deltaY - deltaX;
			int y = y0;

			for (int x = x0; x < x1; x++)
			{
				map->setPixel8U(x, y, 100);

				if (deltaErr >= 0) {
					if (y1 > y0)
						y = y + 1;
					else
						y = y - 1;
					deltaErr = deltaErr - deltaX;
				}

				deltaErr = deltaErr + deltaY;

			}
		}

		else {

			int deltaErr = deltaX - deltaY;

			if (y0 > y1) {
				int x = x1;
				for (int y = y1; y < y0; y++)
				{
					map->setPixel8U(x, y, 100);

					if (deltaErr >= 0) {
						if (x1 > x0)
							x = x - 1;
						else
							x = x + 1;
						deltaErr = deltaErr - deltaY;
					}

					deltaErr = deltaErr + deltaX;

				}
			}
			else {
				int x = x0;
				for (int y = y0; y < y1; y++)
				{
					map->setPixel8U(x, y, 100);

					if (deltaErr >= 0) {
						if (x1 > x0)
							x = x + 1;
						else
							x = x - 1;
						deltaErr = deltaErr - deltaY;
					}

					deltaErr = deltaErr + deltaX;

				}
			}
		}


	}

	else {
		int deltaX = x0 - x1;
		int deltaY = y0 - y1;
		int y = y1;

		if (y1 > y0)
			deltaY = y1 - y0;

		int deltaErr = deltaY - deltaX;

		if (deltaY < deltaX) {
			for (int x = x1; x < x0; x++)
			{

				map->setPixel8U(x, y, 100);

				if (deltaErr >= 0) {
					if (y1 > y0)
						y = y - 1;
					else
						y = y + 1;
					deltaErr = deltaErr - deltaX;
				}

				deltaErr = deltaErr + deltaY;

			}
		}

		else {

			int deltaErr = deltaX - deltaY;

			if (y0 > y1) {
				int x = x1;
				for (int y = y1; y < y0; y++)
				{
					map->setPixel8U(x, y, 100);

					if (deltaErr >= 0) {
						if (x1 > x0)
							x = x - 1;
						else
							x = x + 1;
						deltaErr = deltaErr - deltaY;
					}

					deltaErr = deltaErr + deltaX;

				}
			}
			else {
				int x = x0;
				for (int y = y0; y < y1; y++)
				{
					map->setPixel8U(x, y, 100);

					if (deltaErr >= 0) {
						if (x1 > x0)
							x = x + 1;
						else
							x = x - 1;
						deltaErr = deltaErr - deltaY;
					}

					deltaErr = deltaErr + deltaX;

				}
			}
		}
	}
}

int Coordinates::getCoordinateX()
{
	return coordinateX;
}

int Coordinates::getCoordinateY()
{
	return coordinateY;
}

double Coordinates::getSlope()
{
	return slope;
}

void Coordinates::setSlope(double a)
{
	slope = a;
}

void Coordinates::removeDublicateCoordinates()
{
	for (size_t i = 0; i < coordinates.size(); i++)
	{
		for (size_t j = i + 1; j < coordinates.size(); j++)
		{
			if ((coordinates[i][0]->getCoordinateX() == coordinates[j][0]->getCoordinateX()) && (coordinates[i][0]->getCoordinateY() == coordinates[j][0]->getCoordinateY()))
			{
				std::cout << "Had a dublicate! Tried to create a new random coordinate.";
				std::cout << "(" << coordinates[i][0]->getCoordinateX() << ", " << coordinates[i][0]->getCoordinateY() << ")" << 
					" = " << "(" << coordinates[j][0]->getCoordinateX() << ", " << coordinates[j][0]->getCoordinateY() << ")" << std::endl;

				coordinates[i][0] = new Coordinates(randomNumber(), randomNumber());
				removeDublicateCoordinates(); // Keep trying to make a uniqe random number, this can go on forever if you are not carefull when constructing random coordinates.
			}
		}
	}
}