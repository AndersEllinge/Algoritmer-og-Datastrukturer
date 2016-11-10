#include "GudeKlassen.h"


int main()
{
	GudeKlassen test(100, 0, 0);

	test.exercise753a(36);

	test.exercise753b(6);

	GudeKlassen test1(100, 1, 0);

	test1.printInputVector();
	test1.exercise744();
	test1.printInputVector();


	GudeKlassen test2(100, 0, 1);

	//test2.printCoordinates();
	test2.exercise738(1);
	//test2.printSlopes();
	test2.printFourCollinearGroups();
	test2.drawShit();


	return 0;
}
