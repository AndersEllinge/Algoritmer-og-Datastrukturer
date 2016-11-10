#include "GudeKlassen.h"


GudeKlassen::GudeKlassen()
{
}

GudeKlassen::GudeKlassen(int n, int b, int c) // if b = 1, then we work with a bool vector. if c = 1 then work with coordinates
{
	if (b) {
		inputVector.resize(n);
		for (size_t i = 0; i < n; i++)
		{
			inputVector[i] = randomNumberTrueFalse();
		}
	}
	else if (c)
	{
		coordinates.resize(n);
		for (int i = 0; i < n; i++)
		{
			coordinates[i].resize(2+n-1); // 2 slots for x and y, and -1 because we dont need a slope towards the same point
		}
		for (size_t i = 0; i < n; i++)
		{
			coordinates[i][0] = randomNumber();
			coordinates[i][1] = randomNumber();
		}
		removeDublicateCoordinates();
	}
	else {
		inputVector.resize(n);
		for (size_t i = 0; i < n; i++)
		{
			inputVector[i] = randomNumber();
		}
	}
}

int GudeKlassen::exercise753a(int k)
{
	for (size_t i = 0; i < inputVector.size(); i++) {			// Nested for loop, this means the list is run through 2 times, which is N^2.
		for (size_t j = 0; j < inputVector.size(); j++) {
			if ((inputVector[i] + inputVector[j]) == k) {
				std::cout << "Exercise 753a found: " << std::endl;
				std::cout << inputVector[i] << " + " << inputVector[j] << " = " << k << std::endl;
				printInputVector(); std::cout << std::endl;
				return 1;
			}
		}
	}
	return 0;
}

int GudeKlassen::exercise753b(int k)
{
	std::sort(inputVector.begin(), inputVector.end());	// A standard C++ NlogN sort in ascending order.
	
	int left = 0;	// left index
	int right = inputVector.size()-1;	// right index

	while (left <= right) // Break criteria, indexes have met.
	{
		if ((inputVector[left] + inputVector[right]) == k) { // print and return 1 if a valid sum is found.
			std::cout << "Exercise 753b found: " << std::endl;
			std::cout << inputVector[left] << " + " << inputVector[right] << " = " << k << std::endl;
			printInputVector(); std::cout << std::endl;
			return 1;
		}
		if ((inputVector[left] + inputVector[right]) < k) // if the sum is less than k, then we increase the lowest value, which is an increment of the left index.
			left++;
		if ((inputVector[left] + inputVector[right]) > k) // if the sum is greater than k, then we decrease the highest value, which is a decrement of the right index.
			right--;
	}
	return 0;
}

void GudeKlassen::exercise744()
{
	int left = 0;	// left index
	int right = inputVector.size() - 1;	// right index

	while (left <= right) {
		if (inputVector[left] > inputVector[right])
			std::swap(inputVector[left], inputVector[right]);
		if (inputVector[left] == 0)
			left++;
		if (inputVector[right] == 1)
			right--;
	}
}

int GudeKlassen::exercise738(int k)
{
	findCollinearPoints();
	findCollinearGroups();
	//std::cout << "canse ludrer"<<fourOrMoreCollinear.size() << std::endl;
	return 0;
}

void GudeKlassen::printInputVector()
{
	std::cout << "InputVector is: ";
	for (size_t i = 0; i < inputVector.size(); i++)
			std::cout << inputVector[i] << " ";
	std::cout << std::endl;
}

void GudeKlassen::printCoordinates()
{
	std::cout << "Coordinates are: " << std::endl;
	for (size_t i = 0; i < coordinates.size(); i++)
		std::cout << "(" << coordinates[i][0] << ", " << coordinates[i][1] << ")" << " " ;
	std::cout << std::endl;
}

void GudeKlassen::printSlopes()
{
	for (size_t i = 0; i < coordinates.size(); i++) {
		std::cout << "Slopes for " << "(" << coordinates[i][0] << ", " << coordinates[i][1] << ")" << std::endl;
		for (size_t j = 2; j < coordinates[i].size(); j++)
		{
			std::cout << coordinates[i][j] << " " ;
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void GudeKlassen::printFourCollinearGroups()
{
	for (size_t i = 0; i < fourOrMoreCollinear.size(); i++) {
		std::cout << "Slope: " << fourOrMoreCollinear[i][0] << " ";
		std::cout << "Intersection: " << fourOrMoreCollinear[i][1] << " ";
		for (size_t j = 2; j < fourOrMoreCollinear[i].size(); j++)
		{
			std::cout << "Coordinate: " << "(" << coordinates[fourOrMoreCollinear[i][j]][0] << ", " << coordinates[fourOrMoreCollinear[i][j]][1] << ")" << std::endl;
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void GudeKlassen::removeDublicateCoordinates()
{
	for (size_t i = 0; i < coordinates.size(); i++)
	{
		for (size_t j = i+1; j < coordinates.size(); j++)
		{
			if ((coordinates[i][0] == coordinates[j][0]) && (coordinates[i][1] == coordinates[j][1]))
			{
				std::cout << "Had a dublicate! Tried to create a new random coordinate.";
				std::cout << "(" << coordinates[i][0] << ", " << coordinates[i][1] << ")" << " = " << "(" << coordinates[j][0] << ", " << coordinates[j][1] << ")" << std::endl;
				
				coordinates[i][0] = randomNumber();
				coordinates[i][1] = randomNumber();
				removeDublicateCoordinates();
			}
		}
	}
}

void GudeKlassen::findCollinearPoints()
{
	for (size_t i = 0; i < coordinates.size(); i++)
	{
		determineSlopes(i);
		std::sort(coordinates[i].begin()+2, coordinates[i].end());
	}
	//printSlopes();
}

int GudeKlassen::determineSlopes(size_t i)
{
	int k = 0;	// This is the iterator for the differnet coordinates
	for (size_t j = 2; j < coordinates[i].size(); j++)
	{
		if (!(i == k)){ // if i == k, then its the same coordinate
			if (((coordinates[k][0] - coordinates[i][0])) == 0) // cant divide by zero
				coordinates[i][j] = 10000; // This value now means a infinite slope, aka slope in y-direction
			else
				coordinates[i][j] = (coordinates[k][1] - coordinates[i][1]) / (coordinates[k][0] - coordinates[i][0]);
				
				//coordinates[i][j] = (coordinates[k][1] - coordinates[i][1]) / (coordinates[k][0] - coordinates[i][0]); // slope is (y2-y1)/(x2-x1), rounding to the 3. decimal.
		}
		if (i == k)
			j--;
		k++;
	}
	return 0;
}

float GudeKlassen::determineIntersection(int i, int j)
{
	if (coordinates[i][j] == 10000)
		return coordinates[i][0];

	int tmp = (coordinates[i][1] - (coordinates[i][j] * coordinates[i][0]));

	/*std::cout << "b is: " << tmp << std::endl;
	std::cout << "y is: " << coordinates[i][1] << std::endl;
	std::cout << "a is: " << coordinates[i][j] << std::endl;
	std::cout << "x is: " << coordinates[i][0] << std::endl;*/
	
	
	return  (coordinates[i][1] - (coordinates[i][j] * coordinates[i][0])); // b = y-(a*x)
}

void GudeKlassen::findCollinearGroups()
{
	int tmp = 0;
	for (size_t i = 0; i < coordinates.size(); i++)
	{
		for (size_t j = 2; j < coordinates[i].size(); j++)
		{
			if (j == 2) {
				tmp++;
			}
			else if (coordinates[i][j] == coordinates[i][j - 1]) {
				tmp++;
			/*	std::cout << std::endl;
				std::cout << "spasser " << coordinates[i][j] << " diller " << coordinates[i][j - 1] << " mongol " << tmp << std::endl;*/
				
			}
			else {
				tmp = 0;
			}
			if (tmp == 4){
				fourOrMoreCollinear.push_back({coordinates[i][j], determineIntersection(i,j), (float) i}); // push back slope and intersection and the index coordinate.
				
			/*	std::cout << "x " << coordinates[i][0] << " y " << coordinates[i][1] << std::endl;*/
			}
		}
		tmp = 0;
	}

	//printFourCollinearGroups();

	for (size_t i = 0; i < fourOrMoreCollinear.size(); i++)
	{
		for (size_t j = i + 1; j < fourOrMoreCollinear.size(); j++)
		{
			if ((fourOrMoreCollinear[i][0] == fourOrMoreCollinear[j][0]) && (fourOrMoreCollinear[i][1] == fourOrMoreCollinear[j][1]))
			{
				//std::cout << "Had a dublicate! Moving coordinate to another group" << std::endl;
				fourOrMoreCollinear[i].push_back(fourOrMoreCollinear[j][2]); // Add the coordinate to the first group with this slope and intersection
				fourOrMoreCollinear.erase(fourOrMoreCollinear.begin() + j); // Delete the entry afterwards
				j--; // if we erase, we dont want index to increment.
			}
		}
	}
}

void GudeKlassen::drawShit()
{
	sf::Vertex vertex;								// create a new vertex
	sf::Vertex vertex1(sf::Vector2f(1, 1), sf::Color::Blue);
	sf::VertexArray graph(sf::Points, coordinates.size());
	sf::VertexArray lines(sf::Lines, 1000); 
	
	int k = 0;
	for (int i = 0; i < fourOrMoreCollinear.size(); i++)
	{
		for (size_t j = 2; j < fourOrMoreCollinear[i].size(); j++)
		{
			lines[k].position = sf::Vector2f(coordinates[fourOrMoreCollinear[i][j]][0] * 10, coordinates[fourOrMoreCollinear[i][j]][1] * 10);
			lines[k].color = sf::Color::Blue;
			/*if (j != fourOrMoreCollinear[i].size()-1){
				
			}*/
			/*else {
				lines[k].position = sf::Vector2f(coordinates[fourOrMoreCollinear[i][j-1]][0] * 10, coordinates[fourOrMoreCollinear[i][j-1]][1] * 10);
				lines[k].color = sf::Color::Blue;
			}	*/
			k++;
		}
		//lines[k].position = sf::Vector2f(coordinates[fourOrMoreCollinear[i][fourOrMoreCollinear[i].size()-1]][0] * 10, coordinates[fourOrMoreCollinear[i][fourOrMoreCollinear[i].size()-1]][1] * 10);
		
	}

	for (int i = 0; i < coordinates.size(); i++)
	{
		graph[i].position = sf::Vector2f(coordinates[i][0] * 10, coordinates[i][1] * 10);
		graph[i].color = sf::Color::Red;
	}
	sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");

	while (window.isOpen())
	{
		sf::Event event;
		window.clear();
		window.draw(lines);
		window.draw(graph);
		
		window.display();
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}


	}
}

int GudeKlassen::randomNumber()
{
	std::random_device rd; // obtain a random number from hardware
	std::mt19937 eng(rd()); // seed the generator
	std::uniform_int_distribution<> distr(0, 50); // define the range

	return distr(eng);
}

int GudeKlassen::randomNumberTrueFalse()
{
	std::random_device rd; // obtain a random number from hardware
	std::mt19937 eng(rd()); // seed the generator
	std::uniform_int_distribution<> distr(0, 1); // define the range

	return distr(eng);
}

GudeKlassen::~GudeKlassen()
{
}
