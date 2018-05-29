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
	char str[128];
	char aukera2;
	if(*egoera!=LIBREJO){
		//if(aukera2 == '1')	Instrumentuz_aldatu(instrumentua);
		//if(aukera2 == '2')	Egoeraz_aldatu(egoera);
		switch(*egoera){
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
	}else{

	printf("\nMENU\n");
	printf("\n");
	printf("1) Jokatu nahi duzun instrumentua\n");
	printf("2) Egoeraz aldatu\n");

	printf("6) Programatik irten\n");
	printf("Sartu zure aukera: ");
	fgets(str, 128, stdin);
	aukera2 = *str;

	if(aukera2<='m'&& aukera2>='a'){
		forkFuntzioa(aukera2,karpetaLortu(instrumentua));
	}
	else{
		switch (aukera2)
		{
			case '1':
				Instrumentuz_aldatu(instrumentua);
				break;
			case '2':
				Egoeraz_aldatu(egoera);
				break;
			case '6':

				aukera2 = 6;
				break;
			default:
				break;
		}
	}
	}
	return aukera2;
}

