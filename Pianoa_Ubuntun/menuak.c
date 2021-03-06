/*
 * menuak.c
 *
 *  Created on: May 25, 2018
 *      Author: root
 */
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "egitura.h"
#include <stdlib.h>
#include <string.h>
#include "menuak.h"
int menu_principal(NOTA ** burua)
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

	switch (aukera2)
	{
	case 1:
		menu_instrumentos();
		break;
	case 2: //notaJo();
		freePlay(menu_instrumentos());
		break;
	case 3:
		notakGrabatu(burua, menu_instrumentos());
		break;
	case 4:
		playRec(*burua);
		break;
	case 5:
		playRecRev(*burua);
		break;
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


