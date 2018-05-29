/*
 * egitura.h
 *
 *      Autoreak: Axel Arrieta,
 *     			  Beñat Clemente,
 *     			  Markel Elorza,
 *     			  Unai Esandi,
 *     			  Markel Gonzalez
 *
 */

#ifndef EGITURA_H_
#define EGITURA_H_
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>


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
void Egoeraz_aldatu(int *egoera);
char* karpetaLortu(int *instrumentu);
void notaJo(char aukera, char* instrumentua);
void forkFuntzioa(char aukera, char*instrumentu);
void notakGrabatu(NOTA ** burua, char* instrumentu);
NOTA * notaSortu(char key, char* instrumentu);
void sartuGrabaketan(NOTA ** burua, NOTA * aux);
void playRec(NOTA * burua, char* instrumentu);
void playRecRev(NOTA * burua, char* instrumentu);
void freePlay(char* instrumentu);
void grabaketaEzabatu(NOTA * burua);



#endif /* EGITURA_H_ */
