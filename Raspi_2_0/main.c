/*
 * main.c
 *
 *      Autoreak: Axel Arrieta,
 *     			  Beñat Clemente,
 *     			  Markel Elorza,
 *     			  Unai Esandi,
 *     			  Markel Gonzalez
 *
 */
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "egitura.h"
#include "menua.h"
#include "define.h"
#include <stdlib.h>
#include <string.h>

int main(int argc, char ** argv)
{
	NOTA * burua = NULL;
	int menua = 0;
	int instrumentua = PIANO;
	int egoera = LIBREJO;
	int azkenNota = 0;

	pinHasieratu();

	do
	{
	menua = menu_principal(&burua, &instrumentua, &egoera, &azkenNota);
	sleep(0.01);
	} while (menua != 0);

	printf("Programaren amaiera\n");
	return 0;
}
