#include "GudeKlassen.h"


int main()
{
	GudeKlassen test(100,0);

	test.exercise753a(36);
	test.printInputVector();

	test.exercise753b(6);
	test.printInputVector();

	GudeKlassen test1(100, 1);

	test1.printInputVector();
	test1.exercise744();
	test1.printInputVector();

	return 0;
}
