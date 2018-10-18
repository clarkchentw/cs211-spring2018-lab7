/* filename: max1.c */ 

/* include the .h header file for the program              */
/* NOTE: the header file is enclosed in DOUBLE QUOTES not  */
/*   angle brackets                                        */ 
#include "max.h"

int main( )
{
	int x = 37;
	int y = 52;

        int result = calcMax (x, y);

	printf ("Max is %d\n",  result );

	return 0;
}
