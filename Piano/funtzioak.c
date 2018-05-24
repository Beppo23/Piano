#include "egitura.h"

//Erabiltzaileak return eman gabe notak jokatu ahal izateko
#include <termios.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <string.h>

//Erabiltzaileak return eman gabe notak jokatu ahal izateko erabilitako metodoa

//Funtzio honek sakatutako karaktereak bueltatzen ditu 'return' sakatu gabe
char myGetch(void)
{
  char buf = 0;
  struct termios old = {0};
  if (tcgetattr(0, &old) < 0)
  {
    perror("tcsetattr()");
  }
  old.c_lflag &= ~ICANON;
  old.c_lflag &= ~ECHO;
  old.c_cc[VMIN] = 1;
  old.c_cc[VTIME] = 0;
  if (tcsetattr(0, TCSANOW, &old) < 0)
  {
    perror("tcsetattr ICANON");
  }
  if (read(0, &buf, 1) < 0)
  {
    perror ("read()");
  }
  old.c_lflag |= ICANON;
  old.c_lflag |= ECHO;
  if (tcsetattr(0, TCSADRAIN, &old) < 0)
  {
    perror ("tcsetattr ~ICANON");
  }
  return (buf);
}


void notakGrabatu(NOTA ** burua, char* instrumentu)
{
	int grabatzen = 1;
	NOTA * aux;
	char str[128];
	char aukera;
	clock_t start = -1, end = -1;
	double time;


	while(grabatzen)
	{
		fgets(str, 128, stdin);
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
			notaJo(aukera, instrumentu);
			sartuGrabaketan(burua, aux);
			start = clock();
		}
		else grabatzen = 0;

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
	 strcat(ruta, instrumentua);
	switch (aukera)
	{
	case 'a':

		strcat(ruta, "//do.wav");
		system(ruta);
		break;
	case 'b':
		strcat(ruta, "//doSos.wav");
		//system("%s",ruta);

		break;
	case 'c':
		strcat(ruta, "//re.wav");
		//system("%s",ruta);
		break;
	case 'd':
		strcat(ruta, "//reSos.wav");
		//system("%s",ruta);
		break;
	case 'e':
		strcat(ruta, "//miwav");
		//system("%s",ruta);
		break;
	case 'f':
		strcat(ruta, "//fa.wav");
		//system("%s",ruta);
		break;
	case 'g':
		strcat(ruta, "//faSos.wav");
		//system("%s",ruta);
		break;
	case 'h':
		strcat(ruta, "//sol.wav");
	//	system("%s",ruta);
		break;
	case 'i':
		strcat(ruta, "//solSos.wav");
		//system("%s",ruta);
		break;
	case 'j':
		strcat(ruta, "//la.wav");
		//system("%s",ruta);
		break;
	case 'k':
		strcat(ruta, "//laSos.wav");
		//system("%s",ruta);
		break;
	case 'l':
		strcat(ruta, "//si.wav");
		//system("%s",ruta);
		break;
	//case 'm':
		//system("aplay ..//Media//%s//doMPiano.wav");
		//break;
	default:
		break;

	}
}

void playRec(NOTA * burua)
{
	while(burua != NULL)
	{
		notaJo(burua->key, burua->instrumentu);
		sleep(burua->denbnext);
		burua = burua->ptrNext;
	}
}

void playRecRev(NOTA * burua)
{
	while(burua->ptrNext != NULL) burua = burua->ptrNext;

	while(burua != NULL)
	{
		notaJo(burua->key, burua->instrumentu);
		if(burua->ptrPrev != NULL) sleep(burua->ptrPrev->denbnext);
		burua = burua->ptrPrev;

	}
}

void freePlay(char* instrumentu)
{
	int jotzen = 1;
	char aukera;


	while(jotzen)
	{
		aukera= myGetch();

		if (aukera >= 'a' && aukera <= 'm') notaJo(aukera, instrumentu);
		else if (aukera == 'p')jotzen = 0;
	}
}
