#ifndef EGITURA_H
#define EGITURA_H
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>
#include <dos.h>

#define PIANO '1'
#define FLAUTA '2'
#define BIOLIN '3'
#define GITARRA '4'
#define TROMPETA '5'

typedef struct Nota
{
	double denbSak;
	DWORD denbnext;
	char key;
	char* instrumentu;
	struct Nota * ptrPrev;
	struct Nota * ptrNext;
}NOTA;

void notaJo(char aukera, char* instrumentua);
void notakGrabatu(NOTA ** burua, char* instrumentu);
NOTA * notaSortu(char key, char* instrumentu);
void sartuGrabaketan(NOTA ** burua, NOTA * aux);
void playRec(NOTA * burua);
void playRecRev(NOTA * burua);
void freePlay(char* instrumentu);
//void NotakSartu();
//char myGetch(void);
#endif
