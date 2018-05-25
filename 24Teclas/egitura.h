/*
 * egitura.h
 *
 *  Created on: May 25, 2018
 *      Author: root
 */

#ifndef EGITURA_H_
#define EGITURA_H_
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
/*#include <conio.h>
#include <Windows.h>
#include <dos.h>*/

#define PIANO 1
#define FLAUTA 2
#define BIOLIN 3
#define GITARRA 4
#define TROMPETA 5

typedef struct Nota
{
	double denbSak;
	double denbnext;
	char key;
	char* instrumentu;
	struct Nota * ptrPrev;
	struct Nota * ptrNext;
}NOTA;
void Instrumentuz_aldatu(int *instrumentu);
char* karpetaLortu(int *instrumentu);
void notaJo(char aukera, char* instrumentua);
void notakGrabatu(NOTA ** burua, char* instrumentu);
NOTA * notaSortu(char key, char* instrumentu);
void sartuGrabaketan(NOTA ** burua, NOTA * aux);
void playRec(NOTA * burua);
void playRecRev(NOTA * burua);
void freePlay(char* instrumentu);
void grabaketaEzabatu(NOTA * burua);
//void NotakSartu();
//char myGetch(void);



#endif /* EGITURA_H_ */
