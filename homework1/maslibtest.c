#include <stdio.h>
#include "maslib.h"


int main()
{
	printf("%i\n", sumIntegers(1, 2));
	printf("%f\n", sumFloats(2.24, 2.35));
	printf("%f\n", sumDoubles(4.55, 1.55));
	printf("Maximum size: %i\n", MAX_SIZE);
	
	return 0;
}
