/*
 * funtzioak.c
 *
 *      Autoreak: Axel Arrieta,
 *     			  Beñat Clemente,
 *     			  Markel Elorza,
 *     			  Unai Esandi,
 *     			  Markel Gonzalez
 *
 */

#include "egitura.h"
#include "define.h"
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <wiringPi.h>

void pinHasieratu()
{
	wiringPiSetup();

	pinMode(8, INPUT);
	pinMode(9, INPUT);
	pinMode(7, INPUT);
	pinMode(0, INPUT);
	pinMode(2, INPUT);
	pinMode(3, INPUT);
	pinMode(12, INPUT);
	pinMode(13, INPUT);
	pinMode(14, INPUT);
	pinMode(30, INPUT);
	pinMode(21, INPUT);
	pinMode(22, INPUT);

}

int pinIrakurri()
{
	int sakatua = -1;

	//Primera octava
	if(digitalRead(23)) sakatua = 1;
	else if(digitalRead(22)) sakatua = 2;
	else if(digitalRead(21)) sakatua = 3;
	else if(digitalRead(14)) sakatua = 4;
	else if(digitalRead(13)) sakatua = 5;
	else if(digitalRead(12)) sakatua = 6;
	else if(digitalRead(3)) sakatua = 7;
	else if(digitalRead(2)) sakatua = 8;
	else if(digitalRead(0)) sakatua = 9;
	else if(digitalRead(7)) sakatua = 10;
	else if(digitalRead(9)) sakatua = 11;
	else if(digitalRead(8)) sakatua = 12;

	//Segunda octava

	//Botones cambio menu
	else if(digitalRead(24)) sakatua = 25;
	else if(digitalRead(25)) sakatua = 26;
	printf("%d", sakatua);

	return sakatua;
}
void notakGrabatu(NOTA ** burua, char* instrumentu)
{
	int grabatzen = 1;
	NOTA * aux = NULL;
	int aukera;
	static struct timeval hasi, bukatu;
	long segundu, msegundu;

	while(grabatzen)
	{
		aukera = pinIrakurri();

		if (aukera != -1)
		{
			if (*burua != NULL)
			{
				gettimeofday(&bukatu, NULL);
				segundu = (bukatu.tv_sec - hasi.tv_sec);
				msegundu = ((segundu*1000000) + (bukatu.tv_usec - hasi.tv_usec));
				aux->denbnext = msegundu;
				printf("Time = %ld\n", msegundu);
			}
			aux = notaSortu(aukera, instrumentu);
			gettimeofday(&hasi, NULL);
			forkFuntzioa(aukera, instrumentu);
			sartuGrabaketan(burua, aux);
		}
		else if(aukera == '2'){
			grabatzen = 0;
		}

	}
}
void Instrumentuz_aldatu(int *instrumentu){

	if (*instrumentu != 5){
		(*instrumentu)++;
	}else{
		*instrumentu =1;
	}

}
void Egoeraz_aldatu(int *egoera){

	if (*egoera != 4){
		(*egoera)++;
	}else{
		*egoera =1;
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
NOTA * notaSortu(int key, char* instrumentu)
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
void notaJo(int aukera, char* instrumentua )
{
	 char ruta[] = {"aplay Media//"};
	 char * name;

	 name = (char *)malloc(sizeof(char)*(strlen(instrumentua) + strlen(ruta) + 1));
	 strcpy(name, ruta);
	 strcat(name, instrumentua);

	switch (aukera)
	{
	case 1:
		name = realloc(name, sizeof(char) * (strlen(name) + 9));
		strcat(name, "//do.wav");
		system(name);
		break;
	case 2:
		name = realloc(name, sizeof(char) * (strlen(name) + 12));
		strcat(name, "//doSos.wav");
		system(name);

		break;
	case 3:
		name = realloc(name, sizeof(char) * (strlen(name) + 9));
		strcat(name, "//re.wav");
		system(name);
		break;
	case 4:
		name = realloc(name, sizeof(char) * (strlen(name) + 12));
		strcat(name, "//reSos.wav");
		system(name);
		break;
	case 5:
		name = realloc(name, sizeof(char) * (strlen(name) + 9));
		strcat(name, "//mi.wav");
		system(name);
		break;
	case 6:
		name = realloc(name, sizeof(char) * (strlen(name) + 9));
		strcat(name, "//fa.wav");
		system(name);
		break;
	case 7:
		name = realloc(name, sizeof(char) * (strlen(name) + 12));
		strcat(name, "//faSos.wav");
		system(name);
		break;
	case 8:
		name = realloc(name, sizeof(char) * (strlen(name) + 10));
		strcat(name, "//sol.wav");
		system(name);
		break;
	case 9:
		name = realloc(name, sizeof(char) * (strlen(name) + 13));
		strcat(name, "//solSos.wav");
		system(name);
		break;
	case 10:
		name = realloc(name, sizeof(char) * (strlen(name) + 9));
		strcat(name, "//la.wav");
		system(name);
		break;
	case 11:
		name = realloc(name, sizeof(char) * (strlen(name) + 12));
		strcat(name, "//laSos.wav");
		system(name);
		break;
	case 12:
		name = realloc(name, sizeof(char) * (strlen(name) + 9));
		strcat(name, "//si.wav");
		system(name);
		break;
	default:
		break;
	}
	free(name);
}

void playRec(NOTA * burua, char* instrumentu)
{
	while(burua != NULL)
	{
		forkFuntzioa(burua->key, instrumentu);
		if(burua->ptrNext != NULL) usleep(burua->denbnext);
		burua = burua->ptrNext;
	}
}

void playRecRev(NOTA * burua, char* instrumentu)
{
	while(burua->ptrNext != NULL) burua = burua->ptrNext;

	while(burua != NULL)
	{
		forkFuntzioa(burua->key, instrumentu);
		if(burua->ptrPrev != NULL) usleep(burua->ptrPrev->denbnext);
		burua = burua->ptrPrev;
	}
}

void freePlay(char* instrumentu)
{
	int jotzen = 1;
	int aukera;

	while(jotzen)
	{
		aukera = pinIrakurri();

		if (aukera != -1) forkFuntzioa(aukera, instrumentu);
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

void forkFuntzioa(int aukera, char*instrumentu){
	int pid = fork();
	if (pid == -1) printf("Errore bat egon da.\n");
	else if (pid == 0) {
		notaJo(aukera,instrumentu);
		exit(0);
	}
}
