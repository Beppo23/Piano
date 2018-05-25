/*
 * main.c
 *
 *  Created on: May 25, 2018
 *      Author: root
 */
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "egitura.h"
#include "menuak.h"
#include <stdlib.h>
#include <string.h>

int main(int argc, char ** argv)
{
	NOTA * burua = NULL;
	int menua = 0;
	//aNotakSartu();
	//notakGrabatu(&burua);

	//playRecRev(burua);
	do
	{
	menua = menu_principal(&burua);
	} while (menua!= 6);

	printf("Sakatu return amaitzeko...");
	getchar();
	return 0;
}


