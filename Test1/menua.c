/*
 * menua.c
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
#include <stdlib.h>
#include <string.h>
#include "menua.h"
#include "define.h"

int menu_principal(NOTA ** burua,int *instrumentua, int *egoera)
{
	int aukera = 0;
	
	sleep(0.5);

	if(*egoera!=LIBREJO){
		//if(aukera2 == '1')	Instrumentuz_aldatu(instrumentua);
		//if(aukera2 == '2')	Egoeraz_aldatu(egoera);
		switch(*egoera)
		{
			case GRABATU:
				printf("Grabatzen");
				if (*burua != NULL)
				{
					grabaketaEzabatu(*burua);
					*burua = NULL;
				}
				notakGrabatu(burua, karpetaLortu(instrumentua));
				Egoeraz_aldatu(egoera);
				break;
			case ERREPRODUZITU:
				playRec(*burua, karpetaLortu(instrumentua));
				Egoeraz_aldatu(egoera);
				break;
			case AERREPRODUZITU:
				playRecRev(*burua, karpetaLortu(instrumentua));
				Egoeraz_aldatu(egoera);
				break;
		}
	}
	else
	{

	printf("\nMENU\n");
	printf("\n");
	printf("1) Jokatu nahi duzun instrumentua\n");
	printf("2) Egoeraz aldatu\n");
	printf("6) Programatik irten\n");
	printf("Sartu zure aukera: ");

	aukera = pinIrakurri();

	if(aukera != -1)
	{
		if(aukera <= 24 && aukera >= 1) forkFuntzioa(aukera,karpetaLortu(instrumentua));
		else
		{
			switch (aukera)
			{
				case 25:
					Instrumentuz_aldatu(instrumentua);
					break;
				case 26:
					Egoeraz_aldatu(egoera);
					break;
				default:
					break;
			}
		}

	}
	}
	return aukera;
}
