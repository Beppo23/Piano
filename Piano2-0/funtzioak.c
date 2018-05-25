#include "egitura.h"

//Erabiltzaileak return eman gabe notak jokatu ahal izateko
//#include <termios.h>
#include <stdio.h>
#include <time.h>
//#include <unistd.h>
#include <string.h>
#include <stdlib.h>
//Erabiltzaileak return eman gabe notak jokatu ahal izateko erabilitako metodoa

//Funtzio honek sakatutako karaktereak bueltatzen ditu 'return' sakatu gabe
//char myGetch(void)
//{
//  char buf = 0;
//  struct termios old = {0};
//  if (tcgetattr(0, &old) < 0)
//  {
//    perror("tcsetattr()");
//  }
//  old.c_lflag &= ~ICANON;
//  old.c_lflag &= ~ECHO;
//  old.c_cc[VMIN] = 1;
//  old.c_cc[VTIME] = 0;
//  if (tcsetattr(0, TCSANOW, &old) < 0)
//  {
//    perror("tcsetattr ICANON");
//  }
//  if (read(0, &buf, 1) < 0)
//  {
//    perror ("read()");
//  }
//  old.c_lflag |= ICANON;
//  old.c_lflag |= ECHO;
//  if (tcsetattr(0, TCSADRAIN, &old) < 0)
//  {
//    perror ("tcsetattr ~ICANON");
//  }
//  return (buf);
//}


void notakGrabatu(NOTA ** burua, char* instrumentu)
{
	int grabatzen = 1;
	NOTA * aux = NULL;
	char aukera;
	clock_t start = -1, end = -1;
	DWORD time;


	while(grabatzen)
	{
		aukera = _getch();

		if (aukera >= 'a' && aukera <= 'm')
		{
			if (start != -1)
			{
				end = clock();
				time = ((DWORD)(end - start)) / CLOCKS_PER_SEC;
				aux->denbnext = time;
			}
			aux = notaSortu(aukera, instrumentu);
			notaJo(aukera, instrumentu);
			sartuGrabaketan(burua, aux);
			start = clock();
		}
		else if (aukera == 'p') grabatzen = 0;

	}
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
	 char ruta[] = {"aplay ..//Media//"};
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
		notaJo(burua->key, burua->instrumentu);
		Sleep(burua->denbnext);
		burua = burua->ptrNext;
	}
}

void playRecRev(NOTA * burua)
{
	while(burua->ptrNext != NULL) burua = burua->ptrNext;

	while(burua != NULL)
	{
		notaJo(burua->key, burua->instrumentu);
		if(burua->ptrPrev != NULL) Sleep(burua->ptrPrev->denbnext);
		burua = burua->ptrPrev;

	}
}

void freePlay(char* instrumentu)
{
	int jotzen = 1;
	char aukera;


	while(jotzen)
	{
		aukera= _getch();

		if (aukera >= 'a' && aukera <= 'm') notaJo(aukera, instrumentu);
		else if (aukera == 'p')jotzen = 0;
	}
	free(instrumentu);
}
