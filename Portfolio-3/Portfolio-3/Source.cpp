#include "GudeKlassen.h"
#include "Coordinates.h"

int main()
{
	/* Exercise 7.53 */
	GudeKlassen test(100, 0); // 100 random numbers between 0 and 99
							  // You can choose another amount in the constructor, though the range does not change, you can change the range in GudeKlassen::randomNumber();
	test.exercise753a(36);

	test.exercise753b(6);

	/*---------------*/

	/* Exercise 7.44 */

	GudeKlassen test1(100, 1); // 100 random statements between 0 and 1
							   // You can choose another amount in the constructor, though the range does not change, you can change the range GudeKlassen::randomNumberTrueFalse();
	test1.printInputVector();
	test1.exercise744();
	test1.printInputVector();

	/*----------------*/

	/* Exercise 7.38 */

	Coordinates coordinates(200); // 200 uniqe random coordinates between (0,0) and (199,199) 
								  // You can choose another amount in the constructor, though the range does not change, you can change the range in int Coordinates::randomNumber();
	coordinates.printCoordinates();
	coordinates.findCollinearPoints();
	coordinates.printCollinearPoints();
	Image* map = PPMLoader::load("map.pgm");
	coordinates.setMap(map);
	coordinates.drawGroups();
	return 0;
}
