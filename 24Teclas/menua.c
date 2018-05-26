/*
 * menua.c
 *
 *  Created on: May 26, 2018
 *      Author: uesandi
 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "egitura.h"
#include <stdlib.h>
#include <string.h>
#include "menua.h"
int menu_principal(NOTA ** burua,int *instrumentua)
{
	char str[128];
	char aukera2;


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
	aukera2 = *str;

	if(aukera2<='m'&& aukera2>='a'){
		forkFuntzioa(aukera2,karpetaLortu(instrumentua));
		//freePlay(karpetaLortu(instrumentua));
	}
	else{
		switch (aukera2)
		{
			case '1':
				Instrumentuz_aldatu(instrumentua);
				break;
			case '2': //notaJo();
				//AQUI IRIA EL METODO DE FUNTZIOZ ALDATU (Grabatu, etc.)
				//freePlay(menu_instrumentos());
				break;
			case '3':
				if (*burua != NULL)
				{
				grabaketaEzabatu(*burua);
				*burua = NULL;
				}
				notakGrabatu(burua, karpetaLortu(instrumentua));
				break;
			case '4':
				playRec(*burua);
				break;
			case '5':
				playRecRev(*burua);
				break;
		}
	}


	return aukera2;
}

char* menu_instrumentos()
{
	char * izena;
	char instrumentuChar[20] = { "notas_" };
	char str[128];
	char aukera;
	printf("\n");
	printf("1) Piano\n");
	printf("2) Flauta\n");
	printf("3) Violin\n");
	printf("4) Guitarra\n");
	printf("5) Trompeta\n");
	fgets(str,128,stdin);
	aukera = *str;
	switch (aukera)
	{
	case PIANO:
		strcat(instrumentuChar, "piano");
		break;
	case FLAUTA:
		strcat(instrumentuChar, "flute");
		break;
	case BIOLIN:
		strcat(instrumentuChar, "violin");
		break;
	case GITARRA:
		strcat(instrumentuChar, "gitarra");
		break;
	case TROMPETA:
		strcat(instrumentuChar, "trompeta");
		break;
	default:
		break;
	}

	izena = (char *)malloc(sizeof(char)*(strlen(instrumentuChar) + 1));
	strcpy(izena, instrumentuChar);

	return izena;
}

