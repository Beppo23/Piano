#include "egitura.h"

void notakGrabatu(NOTA ** burua)
{
	int grabatzen = 1;
	NOTA * aux;
	char str[128];
	char aukera;
	clock_t start = -1, end = -1;
	double time;


	while(grabatzen)
	{
		fgets(str, 128, stdin);
		aukera = *str;

		if (aukera >= 'a' && aukera <= 'm')
		{
			if (start != -1)
			{
				end = clock();
				time = ((double)(end - start)) / CLOCKS_PER_SEC;
				aux->denbnext = time;
			}
			aux = notaSortu(aukera);
			notaJo(aukera);
			sartuGrabaketan(burua, aux);
			start = clock();
		}
		else grabatzen = 0;
		/*switch (aukera)
		{
		case 'a':
			if (start != -1)
			{
				end = clock();
				time = ((double)(end - start)) / CLOCKS_PER_SEC;
				aux->denbnext = time;
			}
			aux = notaSortu(aukera);
			sartuGrabaketan(burua, aux);
			start = clock();
			break;
		case 'b':
			if (start != -1)
			{
				end = clock();
				time = ((double)(end - start)) / CLOCKS_PER_SEC;
				aux->denbnext = time;
			}
			aux = notaSortu(aukera);
			sartuGrabaketan(burua, aux);
			start = clock();
			break;
		case 'c':
			if (start != -1)
			{
				end = clock();
				time = ((double)(end - start)) / CLOCKS_PER_SEC;
				aux->denbnext = time;
			}
			aux = notaSortu(aukera);
			sartuGrabaketan(burua, aux);
			start = clock();
			break;
		case 'd':
			if (start != -1)
			{
				end = clock();
				time = ((double)(end - start)) / CLOCKS_PER_SEC;
				aux->denbnext = time;
			}
			aux = notaSortu(aukera);
			sartuGrabaketan(burua, aux);
			start = clock();
			break;
		case 'e':
			if (start != -1)
			{
				end = clock();
				time = ((double)(end - start)) / CLOCKS_PER_SEC;
				aux->denbnext = time;
			}
			aux = notaSortu(aukera);
			sartuGrabaketan(burua, aux);
			start = clock();
			break;
		case 'f':
			if (start != -1)
			{
				end = clock();
				time = ((double)(end - start)) / CLOCKS_PER_SEC;
				aux->denbnext = time;
			}
			aux = notaSortu(aukera);
			sartuGrabaketan(burua, aux);
			start = clock();
			break;
		case 'g':
			if (start != -1)
			{
				end = clock();
				time = ((double)(end - start)) / CLOCKS_PER_SEC;
				aux->denbnext = time;
			}
			aux = notaSortu(aukera);
			sartuGrabaketan(burua, aux);
			start = clock();
			break;
		case 'h':
			if (start != -1)
			{
				end = clock();
				time = ((double)(end - start)) / CLOCKS_PER_SEC;
				aux->denbnext = time;
			}
			aux = notaSortu(aukera);
			sartuGrabaketan(burua, aux);
			start = clock();
			break;
		case 'i':
			if (start != -1)
			{
				end = clock();
				time = ((double)(end - start)) / CLOCKS_PER_SEC;
				aux->denbnext = time;
			}
			aux = notaSortu(aukera);
			sartuGrabaketan(burua, aux);
			start = clock();
			break;
		case 'j':
			if (start != -1)
			{
				end = clock();
				time = ((double)(end - start)) / CLOCKS_PER_SEC;
				aux->denbnext = time;
			}
			aux = notaSortu(aukera);
			sartuGrabaketan(burua, aux);
			start = clock();
			break;
		case 'k':
			if (start != -1)
			{
				end = clock();
				time = ((double)(end - start)) / CLOCKS_PER_SEC;
				aux->denbnext = time;
			}
			aux = notaSortu(aukera);
			sartuGrabaketan(burua, aux);
			start = clock();
			break;
		case 'l':
			if (start != -1)
			{
				end = clock();
				time = ((double)(end - start)) / CLOCKS_PER_SEC;
				aux->denbnext = time;
			}
			aux = notaSortu(aukera);
			sartuGrabaketan(burua, aux);
			start = clock();
			break;
		case 'm':
			if (start != -1)
			{
				end = clock();
				time = ((double)(end - start)) / CLOCKS_PER_SEC;
				aux->denbnext = time;
			}
			aux = notaSortu(aukera);
			sartuGrabaketan(burua, aux);
			start = clock();
			break;
		case 'q':
			grabatzen = 0;
			break;
		default:
			break;
		}*/
	}
}

NOTA * notaSortu(char key)
{
	NOTA * aux;

	aux = (NOTA*)malloc(sizeof(NOTA));

	aux->denbSak = - 1;
	aux->denbnext = - 1;
	aux->key = key;
	aux->ptrNext = NULL;
	aux->ptrPrev = NULL;

	return aux;
}

void sartuGrabaketan(NOTA ** burua, NOTA * aux)
{
	NOTA * ptr = *burua;

	if(*burua == NULL) *burua = aux;
	else
	{
		while(ptr->ptrNext != NULL) ptr = ptr->ptrNext;

		ptr->ptrNext = aux;
		aux->ptrPrev = ptr;
	}
}

void notaJo(char aukera)
{
	switch (aukera)
	{
	case 'a':
		system("aplay doPiano.wav");
		break;
	case 'b':
		system("aplay doSosPiano.wav");
		break;
	case 'c':
		system("aplay rePiano.wav");
		break;
	case 'd':
		system("aplay reSosPiano.wav");
		break;
	case 'e':
		system("aplay miPiano.wav");
		break;
	case 'f':
		system("aplay faPiano.wav");
		break;
	case 'g':
		system("aplay faSosPiano.wav");
		break;
	case 'h':
		system("aplay solPiano.wav");
		break;
	case 'i':
		system("aplay solSosPiano.wav");
		break;
	case 'j':
		system("aplay laPiano.wav");
		break;
	case 'k':
		system("aplay laSosPiano.wav");
		break;
	case 'l':
		system("aplay siPiano.wav");
		break;
	case 'm':
		system("aplay doMPiano.wav");
		break;
	default:
		break;

	}
}

void playRec(NOTA * burua)
{
	while(burua != NULL)
	{
		notaJo(burua->key);
		sleep(burua->denbnext);
		burua = burua->ptrNext;
	}
}

void playRecRev(NOTA * burua)
{
	while(burua->ptrNext != NULL) burua = burua->ptrNext;

	while(burua != NULL)
	{
		notaJo(burua->key);
		if(burua->ptrPrev != NULL) sleep(burua->ptrPrev->denbnext);
		burua = burua->ptrPrev;

	}
}

void freePlay()
{
	int jotzen = 1;
	char str[128];
	char aukera;


	while(jotzen)
	{
		fgets(str, 128, stdin);
		aukera = *str;

		if (aukera >= 'a' && aukera <= 'm') notaJo(aukera);
		else jotzen = 0;
}
