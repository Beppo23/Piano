#include <stdio.h>
#include "egitura.h"
#include <stdlib.h>

int main(int argc, char ** argv)
{
	NOTA * burua = NULL;


	notakGrabatu(&burua);

	playRec(burua);

	playRecRev(burua);

	printf("Sakatu return amaitzeko...");
	getchar();
	return 0;
}
