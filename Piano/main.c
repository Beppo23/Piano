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
void menu_principal()
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
		case "1": menu_instrumentos();
			break;
		case "2": notaJo();
			break;
		case "3": notakGrabatu();
			break;
		case "4": playRec();
			break;
		case "5": playRecRev();
			break;
}

}

void menu_instrumentos()
{
	char str[128];
	int instrumentua;
	char instrumentuIzena[128];
	char instrumentuChar = "notas_";

	printf("\n");
    printf("1) Jokatu nahi duzun instrumentua\n");
    printf("2) Jokatu\n");
    printf("3) Grabatu\n");
    printf("4) Erreproduzitu\n");
    printf("5) Erreproduzitu alderantziz\n");
    printf("5) Programatik irten\n");

switch (instrumentua)
{

	 case PIANO:
	{
		       instrumentuIzena = "piano";
		       strcat(instrumentuChar,instrumentuIzena);
		       break;
	}
	case FLAUTA:
	{
		       instrumentuIzena = "flute";
		       strcat(instrumentuChar, instrumentuIzena);
		       break;
	}
	case BIOLIN:
	{
		       instrumentuIzena = "violin"
		       strcat(instrumentuChar, instrumentuIzena);
		       break;
	}
	case GITARRA:
	{
		       instrumentuIzena = "guitarra";
		       strcat(instrumentuChar, instrumentuIzena);
		       break;
	}
	case TROMPETA:
	{
		    	 instrumentuIzena= "trompeta";
		    	 strcat(instrumentuChar, instrumentuIzena);
		    	 break;
	}


	}


