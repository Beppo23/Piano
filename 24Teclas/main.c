/*
 * main.c
 *
 *  Created on: May 26, 2018
 *      Author: uesandi
 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "egitura.h"
#include "menua.h"
#include <stdlib.h>
#include <string.h>

int main(int argc, char ** argv)
{
	NOTA * burua = NULL;
	int menua = 0;
	int instrumentua = PIANO;
	//aNotakSartu();
	//notakGrabatu(&burua);

	//playRecRev(burua);
	do
	{
	menua = menu_principal(&burua, &instrumentua);
	} while (menua!= 6);

	printf("Sakatu return amaitzeko...");
	getchar();
	return 0;
}

