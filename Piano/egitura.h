#ifndef EGITURA_H
#define EGITURA_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DoP "doPiano.wav"
#define PIANO '1'
#define FLAUTA '2'
#define BIOLIN '3'
#define GITARRA '4'
#define TROMPETA '5'

typedef struct Nota
{
	double denbSak;
	double denbnext;
	char key;
	char* instrumentu;
	struct Nota * ptrPrev;
	struct Nota * ptrNext;
}NOTA;
//, char instrumentua[]
void menu_principal(NOTA ** burua);
char* menu_instrumentos();
void notaJo(char aukera, char* instrumentua);
void notakGrabatu(NOTA ** burua, char* instrumentu);
NOTA * notaSortu(char key, char* instrumentu);
void sartuGrabaketan(NOTA ** burua, NOTA * aux);
void playRec(NOTA * burua);
void playRecRev(NOTA * burua);
void freePlay(char* instrumentu);
void NotakSartu();
char myGetch(void);
#endif
