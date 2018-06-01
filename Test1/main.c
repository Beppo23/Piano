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
	//aNotakSartu();
	//notakGrabatu(&burua);
	pinHasieratu();
	//playRecRev(burua);
	do
	{
	menua = menu_principal(&burua, &instrumentua, &egoera);
	} while (menua != 0);

	printf("Sakatu return amaitzeko...");
	getchar();
	return 0;
}
