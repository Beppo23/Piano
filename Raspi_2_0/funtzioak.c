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

	if(wiringPiISR(8, INT_EDGE_RISING, &pin8) < 0) printf("Errorea egon da 8. pinean.\n");
	if(wiringPiISR(9, INT_EDGE_RISING, &pin9) < 0) printf("Errorea egon da 9. pinean.\n");
//	if(wiringPiISR(7, INT_EDGE_RISING, &pin7) < 0) printf("Errorea egon da 7. pinean.\n");
	if(wiringPiISR(0, INT_EDGE_RISING, &pin0) < 0) printf("Errorea egon da 0. pinean.\n");
	if(wiringPiISR(2, INT_EDGE_RISING, &pin2) < 0) printf("Errorea egon da 2. pinean.\n");
	if(wiringPiISR(3, INT_EDGE_RISING, &pin3) < 0) printf("Errorea egon da 3. pinean.\n");
	if(wiringPiISR(12, INT_EDGE_RISING, &pin12) < 0) printf("Errorea egon da 12. pinean.\n");
	if(wiringPiISR(13, INT_EDGE_RISING, &pin13) < 0) printf("Errorea egon da 13. pinean.\n");
	if(wiringPiISR(14, INT_EDGE_RISING, &pin14) < 0) printf("Errorea egon da 14. pinean.\n");
	if(wiringPiISR(23, INT_EDGE_RISING, &pin23) < 0) printf("Errorea egon da 23. pinean.\n");
	if(wiringPiISR(21, INT_EDGE_RISING, &pin21) < 0) printf("Errorea egon da 21. pinean.\n");
	if(wiringPiISR(22, INT_EDGE_RISING, &pin22) < 0) printf("Errorea egon da 22. pinean.\n");

	if(wiringPiISR(15, INT_EDGE_RISING, &pin15) < 0) printf("Errorea egon da 15. pinean.\n");
	if(wiringPiISR(1, INT_EDGE_RISING, &pin1) < 0) printf("Errorea egon da 1. pinean.\n");
	if(wiringPiISR(16, INT_EDGE_RISING, &pin16) < 0) printf("Errorea egon da 16. pinean.\n");
	if(wiringPiISR(4, INT_EDGE_RISING, &pin4) < 0) printf("Errorea egon da 4. pinean.\n");
	if(wiringPiISR(5, INT_EDGE_RISING, &pin5) < 0) printf("Errorea egon da 5. pinean.\n");
	if(wiringPiISR(6, INT_EDGE_RISING, &pin6) < 0) printf("Errorea egon da 6. pinean.\n");
	if(wiringPiISR(10, INT_EDGE_RISING, &pin10) < 0) printf("Errorea egon da 10. pinean.\n");
	if(wiringPiISR(11, INT_EDGE_RISING, &pin11) < 0) printf("Errorea egon da 11. pinean.\n");
	if(wiringPiISR(31, INT_EDGE_RISING, &pin31) < 0) printf("Errorea egon da 31. pinean.\n");
	if(wiringPiISR(26, INT_EDGE_RISING, &pin26) < 0) printf("Errorea egon da 26. pinean.\n");
	if(wiringPiISR(27, INT_EDGE_RISING, &pin27) < 0) printf("Errorea egon da 27. pinean.\n");
	if(wiringPiISR(28, INT_EDGE_RISING, &pin28) < 0) printf("Errorea egon da 28. pinean.\n");
	/*pinMode(8, INPUT);
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

	pinMode(15, INPUT);
	pinMode(16, INPUT);
	pinMode(1, INPUT);
	pinMode(4, INPUT);
	pinMode(5, INPUT);
	pinMode(6, INPUT);
	pinMode(10, INPUT);
	pinMode(11, INPUT);
	pinMode(31, INPUT);
	pinMode(26, INPUT);
	pinMode(27, INPUT);
	pinMode(28, INPUT);*/
}

void pin16()
{
	input = 14;
	printf("Input = %d\n", input);
}
void pin4()
{
	input = 16;
	printf("Input = %d\n", input);
}
void pin8()
{
	input = 12;
	printf("Input = %d\n", input);
}
void pin9()
{
	input = 11;
	printf("Input = %d\n", input);
}
/*void pin7()
{
	input = 10;
	printf("Input = %d\n", input);
}*/
void pin0()
{
	input = 9;
	printf("Input = %d\n", input);
}
void pin2()
{
	input = 8;
	printf("Input = %d\n", input);
}
void pin3()
{
	input = 7;
	printf("Input = %d\n", input);
}
void pin12()
{
	input = 6;
	printf("Input = %d\n", input);
}
void pin13()
{
	input = 5;
	printf("Input = %d\n", input);
}
void pin14()
{
	input = 4;
	printf("Input = %d\n", input);
}
void pin23()
{
	input = 1;
	printf("Input = %d\n", input);
}
void pin21()
{
	input = 3;
	printf("Input = %d\n", input);
}
void pin22()
{
	input = 2;
	printf("Input = %d\n", input);
}
void pin15()
{
	input = 26;
	printf("Input = %d\n", input);
}
void pin1()
{
	input = 25;
	printf("Input = %d\n", input);
}
void pin5()
{
	input = 17;
	printf("Input = %d\n", input);
}
void pin6()
{
	input = 18;
	printf("Input = %d\n", input);
}
void pin10()
{
	input = 19;
	printf("Input = %d\n", input);
}
void pin11()
{
	input = 20;
	printf("Input = %d\n", input);
}
void pin31()
{
	input = 21;
	printf("Input = %d\n", input);
}
void pin26()
{
	input = 22;
	printf("Input = %d\n", input);
}
void pin27()
{
	input = 23;
	printf("Input = %d\n", input);
}
void pin28()
{
	input = 24;
	printf("Input = %d\n", input);
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
	else if(!digitalRead(9)) sakatua = 11;
	else if(!digitalRead(8)) sakatua = 12;

	//Segunda octava
	else if(digitalRead(15)) sakatua = 26;
	else if(digitalRead(16)) sakatua = 14;
	else if(digitalRead(1)) sakatua = 25;
	else if(digitalRead(4)) sakatua = 16;
	else if(digitalRead(5)) sakatua = 17;
	else if(digitalRead(6)) sakatua = 18;
	else if(digitalRead(10)) sakatua = 19;
	else if(digitalRead(11)) sakatua = 20;
	else if(digitalRead(31)) sakatua = 21;
	else if(digitalRead(26)) sakatua = 22;
	else if(digitalRead(27)) sakatua = 23;
	else if(digitalRead(28)) sakatua = 24;

	//Botones cambio menu
	else if(digitalRead(24)) sakatua = 25;
	else if(digitalRead(25)) sakatua = 26;
	//printf("%d\n", sakatua);

	return sakatua;
}
void notakGrabatu(NOTA ** burua, char* instrumentu, int * azkenNota)
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
			if(aukera <= 24 && aukera >= 1)
			{
				if(aukera != *azkenNota)
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
					*azkenNota = aukera;
				}
			}
			else if(aukera == 26) grabatzen = 0;
		}
		else *azkenNota = 0;
	}
}

void Instrumentuz_aldatu(int *instrumentu)
{
	if (*instrumentu != 5) (*instrumentu)++;
	else *instrumentu = 1;
}

void Egoeraz_aldatu(int *egoera){

	if (*egoera == LIBREJO) *egoera = GRABATU;
	else if(*egoera == GRABATU) *egoera = ERREPRODUZITU;
	else if(*egoera == ERREPRODUZITU) *egoera = AERREPRODUZITU;
	else if(*egoera == AERREPRODUZITU) *egoera = LIBREJO;
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
	case 13:
		name = realloc(name, sizeof(char) * (strlen(name) + 10));
		strcat(name, "//do.wav");
		system(name);
		break;
	case 14:
		name = realloc(name, sizeof(char) * (strlen(name) + 13));
		strcat(name, "//doMSos.wav");
		system(name);
		break;
	case 15:
		name = realloc(name, sizeof(char) * (strlen(name) + 10));
		strcat(name, "//reM.wav");
		system(name);
		break;
	case 16:
		name = realloc(name, sizeof(char) * (strlen(name) + 13));
		strcat(name, "//reMSos.wav");
		system(name);
		break;
	case 17:
		name = realloc(name, sizeof(char) * (strlen(name) + 10));
		strcat(name, "//miM.wav");
		system(name);
		break;
	case 18:
		name = realloc(name, sizeof(char) * (strlen(name) + 10));
		strcat(name, "//faM.wav");
		system(name);
		break;
	case 19:
		name = realloc(name, sizeof(char) * (strlen(name) + 13));
		strcat(name, "//faMSos.wav");
		system(name);
		break;
	case 20:
		name = realloc(name, sizeof(char) * (strlen(name) + 11));
		strcat(name, "//solM.wav");
		system(name);
		break;
	case 21:
		name = realloc(name, sizeof(char) * (strlen(name) + 14));
		strcat(name, "//solMSos.wav");
		system(name);
		break;
	case 22:
		name = realloc(name, sizeof(char) * (strlen(name) + 10));
		strcat(name, "//laM.wav");
		system(name);
		break;
	case 23:
		name = realloc(name, sizeof(char) * (strlen(name) + 13));
		strcat(name, "//laMSos.wav");
		system(name);
		break;
	case 24:
		name = realloc(name, sizeof(char) * (strlen(name) + 10));
		strcat(name, "//siM.wav");
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
	if(burua != NULL)
	{
	while(burua->ptrNext != NULL) burua = burua->ptrNext;

	while(burua != NULL)
	{
		forkFuntzioa(burua->key, instrumentu);
		if(burua->ptrPrev != NULL) usleep(burua->ptrPrev->denbnext);
		burua = burua->ptrPrev;
	}
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


