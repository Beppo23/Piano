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

static volatile int input = 0;

typedef struct Nota
{
	double denbnext;
	int key;
	char* instrumentu;
	struct Nota * ptrPrev;
	struct Nota * ptrNext;
}NOTA;

void Instrumentuz_aldatu(int *instrumentu);
void Egoeraz_aldatu(int *egoera);
char* karpetaLortu(int *instrumentu);
void notaJo(int aukera, char* instrumentua);
void forkFuntzioa(int aukera, char*instrumentu);
void notakGrabatu(NOTA ** burua, char* instrumentu, int * azkenNota);
NOTA * notaSortu(int key, char* instrumentu);
void sartuGrabaketan(NOTA ** burua, NOTA * aux);
void playRec(NOTA * burua, char* instrumentu);
void playRecRev(NOTA * burua, char* instrumentu);
void freePlay(char* instrumentu);
void grabaketaEzabatu(NOTA * burua);

void pinHasieratu();
int pinIrakurri();
void pin8();
void pin9();
//void pin7();
void pin0();
void pin2();
void pin3();
void pin12();
void pin13();
void pin14();
void pin23();
void pin21();
void pin22();
void pin15();
void pin1();
void pin16();
void pin4();
void pin5();
void pin6();
void pin10();
void pin11();
void pin31();
void pin26();
void pin27();
void pin28();
#endif /* EGITURA_H_ */
