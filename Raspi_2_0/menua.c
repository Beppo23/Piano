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

int menu_principal(NOTA ** burua,int *instrumentua, int *egoera, int * azkenNota)
{
	int aukera = - 1;
	int hurrengoa = 0;
	if((*egoera) != LIBREJO)
	{
		switch(*egoera)
		{
			case GRABATU:
				printf("Grabatzen\t");
				printf("Sakatu berriz hurrengo 3 segunduetan aldatzeko.\n");
				hurrengoa = waitForInterrupt(15, 3000);
				printf("%d\n", hurrengoa);
				if(hurrengoa == 1) Egoeraz_aldatu(egoera);
				else if (hurrengoa == 0)
				{
					printf("Grabatzen");
					if (*burua != NULL)
					{
						grabaketaEzabatu(*burua);
						*burua = NULL;
					}
					notakGrabatu(burua, karpetaLortu(instrumentua), azkenNota);
				}
				break;

			case ERREPRODUZITU:
				printf("Jotzen\t");
				printf("Sakatu berriz hurrengo 3 segunduetan aldatzeko.\n");
				hurrengoa = waitForInterrupt(15, 3000);
				printf("%d\n", hurrengoa);
				if(hurrengoa == 1) Egoeraz_aldatu(egoera);
				else if(hurrengoa == 0) playRec(*burua, karpetaLortu(instrumentua));
				break;

			case AERREPRODUZITU:
				printf("Alderantziz jotzen\t");
				printf("Sakatu berriz hurrengo 3 segunduetan aldatzeko.\n");
				hurrengoa = waitForInterrupt(15, 3000);
				printf("%d\n", hurrengoa);
				if(hurrengoa == 1) Egoeraz_aldatu(egoera);
				else if (hurrengoa == 0) playRecRev(*burua, karpetaLortu(instrumentua));
				break;
		}
	}
	else
	{
	//printf("Sartu zure aukera: ");

	aukera = pinIrakurri();

	if(aukera != -1)
	{
		if(aukera != *azkenNota)
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
			*azkenNota = aukera;
		}
	}
	else *azkenNota = 0;
	}
	return aukera;
}
