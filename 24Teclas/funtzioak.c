/*
 * funtzioak.c
 *
 *  Created on: May 26, 2018
 *      Author: uesandi
 */

#include "egitura.h"

//Erabiltzaileak return eman gabe notak jokatu ahal izateko
//#include <termios.h>
#include <stdio.h>
#include <time.h>
//#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void notakGrabatu(NOTA ** burua, char* instrumentu)
{
	int grabatzen = 1;
	NOTA * aux = NULL;
	char aukera;
	clock_t start = -1, end = -1;
	double time;
	char str[128];

	while(grabatzen)
	{

		fgets(str,128,stdin);
		aukera = *str;

		if (aukera >= 'a' && aukera <= 'm')
		{
			if (start != -1)
			{
				end = clock();
				time = ((double)(end - start)) / CLOCKS_PER_SEC;
				aux->denbnext = time;
			}
			aux = notaSortu(aukera, instrumentu);
			forkFuntzioa(aukera, instrumentu);
			sartuGrabaketan(burua, aux);
			start = clock();
		}
		else if (aukera == 'p') grabatzen = 0;

	}
}
void Instrumentuz_aldatu(int *instrumentu){

	if (*instrumentu != 5){
		(*instrumentu)++;
	}else{
		*instrumentu =1;
	}

}
char* karpetaLortu(int *instrumentu){

		char * izena;
		char karpeta[20] = {"notas_"};
		switch(*instrumentu){
		case PIANO:
			strcat(karpeta,"piano");
			break;
		case FLAUTA:
			strcat(karpeta, "flute");
			break;
		case BIOLIN:
			strcat(karpeta, "violin");
			break;
		case GITARRA:
			strcat(karpeta, "guitarra");
			break;
		case TROMPETA:
			strcat(karpeta, "trompeta");
			break;
		default:
			break;
		}
		izena = (char *)malloc(sizeof(char)*(strlen(karpeta) + 1));
			strcpy(izena, karpeta);

			return izena;
}
NOTA * notaSortu(char key, char* instrumentu)
{
	NOTA * aux;

	aux = (NOTA*)malloc(sizeof(NOTA));

	aux->denbSak = - 1;
	aux->denbnext = - 1;
	aux->key = key;
	aux->instrumentu = instrumentu;
	aux->ptrNext = NULL;
	aux->ptrPrev = NULL;

	return aux;
}

void sartuGrabaketan(NOTA ** burua, NOTA * aux)
{
	NOTA * ptr = *burua;

	if(*burua == NULL) *burua = aux;
	else
	{
		while(ptr->ptrNext != NULL) ptr = ptr->ptrNext;

		ptr->ptrNext = aux;
		aux->ptrPrev = ptr;
	}
}
//char instrumentua[]
void notaJo(char aukera, char* instrumentua )
{
	 char ruta[] = {"aplay Media//"};
	 char * name;

	 name = (char *)malloc(sizeof(char)*(strlen(instrumentua) + strlen(ruta) + 1));
	 strcpy(name, ruta);
	 strcat(name, instrumentua);

	switch (aukera)
	{
	case 'a':
		name = realloc(name, sizeof(char) * (strlen(name) + 9));
		strcat(name, "//do.wav");
		system(name);
		break;
	case 'b':
		name = realloc(name, sizeof(char) * (strlen(name) + 12));
		strcat(name, "//doSos.wav");
		system(name);

		break;
	case 'c':
		name = realloc(name, sizeof(char) * (strlen(name) + 9));
		strcat(name, "//re.wav");
		system(name);
		break;
	case 'd':
		name = realloc(name, sizeof(char) * (strlen(name) + 12));
		strcat(name, "//reSos.wav");
		system(name);
		break;
	case 'e':
		name = realloc(name, sizeof(char) * (strlen(name) + 9));
		strcat(name, "//mi.wav");
		system(name);
		break;
	case 'f':
		name = realloc(name, sizeof(char) * (strlen(name) + 9));
		strcat(name, "//fa.wav");
		system(name);
		break;
	case 'g':
		name = realloc(name, sizeof(char) * (strlen(name) + 12));
		strcat(name, "//faSos.wav");
		system(name);
		break;
	case 'h':
		name = realloc(name, sizeof(char) * (strlen(name) + 10));
		strcat(name, "//sol.wav");
		system(name);
		break;
	case 'i':
		name = realloc(name, sizeof(char) * (strlen(name) + 13));
		strcat(name, "//solSos.wav");
		system(name);
		break;
	case 'j':
		name = realloc(name, sizeof(char) * (strlen(name) + 9));
		strcat(name, "//la.wav");
		system(name);
		break;
	case 'k':
		name = realloc(name, sizeof(char) * (strlen(name) + 12));
		strcat(name, "//laSos.wav");
		system(name);
		break;
	case 'l':
		name = realloc(name, sizeof(char) * (strlen(name) + 9));
		strcat(name, "//si.wav");
		system(name);
		break;
	//case 'm':
		//system("aplay ..//Media//%s//doMPiano.wav");
		//break;
	default:
		break;
	}
	free(name);
}

void playRec(NOTA * burua)
{
	while(burua != NULL)
	{
		forkFuntzioa(burua->key, burua->instrumentu);
		sleep(burua->denbnext);
		burua = burua->ptrNext;
	}
}

void playRecRev(NOTA * burua)
{
	while(burua->ptrNext != NULL) burua = burua->ptrNext;

	while(burua != NULL)
	{
		forkFuntzioa(burua->key, burua->instrumentu);
		if(burua->ptrPrev != NULL) sleep(burua->ptrPrev->denbnext);
		burua = burua->ptrPrev;

	}
}

void freePlay(char* instrumentu)
{
	int jotzen = 1;
	char aukera;
	char str[128];

	while(jotzen)
	{

		fgets(str,128,stdin);
		aukera = *str;


		if (aukera >= 'a' && aukera <= 'm') forkFuntzioa(aukera, instrumentu);
		else if (aukera == 'p')jotzen = 0;
	}
	free(instrumentu);
}

void grabaketaEzabatu(NOTA * burua)
{
	NOTA * aux = NULL;

	while (burua != NULL)
	{
		aux = burua->ptrNext;
		free(burua);
		burua = aux;
	}
}

void forkFuntzioa(char aukera, char*instrumentu){
	if (fork() == -1) printf("Errore bat egon da.\n");
	else if (fork() == 0) notaJo(aukera,instrumentu);
}
