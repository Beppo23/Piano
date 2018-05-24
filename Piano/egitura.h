#ifndef EGITURA_H
#define EGITURA_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DoP "doPiano.wav"

typedef struct Nota
{
	double denbSak;
	double denbnext;
	char key;
	struct Nota * ptrPrev;
	struct Nota * ptrNext;
}NOTA;

void notaJo(char aukera);
void notakGrabatu(NOTA ** burua);
NOTA * notaSortu(char key);
void sartuGrabaketan(NOTA ** burua, NOTA * aux);
void playRec(NOTA * burua);
void playRecRev(NOTA * burua);
void freePlay();
#endif
