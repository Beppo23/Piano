#include <stdio.h>
#include "egitura.h"
#include <stdlib.h>
#include <string.h>

int main(int argc, char ** argv)
{
	NOTA * burua = NULL;

	//aNotakSartu();
	//notakGrabatu(&burua);

	//playRecRev(burua);
	menu_principal(&burua);
	printf("Sakatu return amaitzeko...");
	getchar();
	return 0;
}
void menu_principal(NOTA ** burua)
{
	char str[128];
	int aukera2;

		printf("\nMENU\n");
		printf("\n");
		printf("1) Jokatu nahi duzun instrumentua\n");
		printf("2) Jokatu\n");
		printf("3) Grabatu\n");
		printf("4) Erreproduzitu\n");
		printf("5) Erreproduzitu alderantziz\n");
		printf("5) Programatik irten\n");

		printf("Sartu zure aukera: ");
		fgets(str, 128, stdin);
		sscanf(str, "%d", &aukera2);

		switch(aukera2)
		{
		case 1: menu_instrumentos();
			break;
		case 2: //notaJo();
				freePlay(menu_instrumentos());
			break;
		case 3: notakGrabatu(burua,menu_instrumentos());
			break;
		case 4: playRec(* burua);
			break;
		case 5: playRecRev(* burua);
			break;
}

}

char* menu_instrumentos()
{
	static char instrumentuChar[] = {"notas_"};

	printf("\n");
    printf("1) Jokatu nahi duzun instrumentua\n");
    printf("2) Jokatu\n");
    printf("3) Grabatu\n");
    printf("4) Erreproduzitu\n");
    printf("5) Erreproduzitu alderantziz\n");
    printf("5) Programatik irten\n");



switch (myGetch())
{

	 case PIANO:
	{
		       strcat(instrumentuChar,"piano");
		       break;
	}
	case FLAUTA:
	{
		       strcat(instrumentuChar, "flute");
		       break;
	}
	case BIOLIN:
	{
		       strcat(instrumentuChar, "violin");
		       break;
	}
	case GITARRA:
	{
		       strcat(instrumentuChar, "gitarra");
		       break;
	}
	case TROMPETA:
	{
		    	 strcat(instrumentuChar, "trompeta");
		    	 break;
	}


}
return instrumentuChar;
}
