// Listas_encadeadas_e_estatica.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
//#include "Lista_estatica.h"
#include "Lista_encadeada.h"
//#include "Lista_duplamente_encadeada.h"


int main()
{
	ListaEncadeada lista;
	int a, b, c, d, e, f, g, h, i, j;
	a = 10;
	b = 20;
	c = 30;
	d = 40;
	e = 50;
	f = 60;
	g = 70;
	h = 80;
	i = 90;
	j = 100;

	inicializarListaEncadeada(lista);
	inserirInicioListaEncadeada(lista, a);
	inserirFimListaEncadeada(lista, b);
	inserirPosicaoListaEncadeada(lista, c, 2);
	inserirInicioListaEncadeada(lista, d);
	inserirPosicaoListaEncadeada(lista, e, 1);
	inserirPosicaoListaEncadeada(lista, f, 3);
	inserirPosicaoListaEncadeada(lista, g, 0);
	inserirPosicaoListaEncadeada(lista, h, 1);
	inserirPosicaoListaEncadeada(lista, i, 5);
	inserirPosicaoListaEncadeada(lista, j, 4);
	toViewListaEncadeada(lista);

	bubbleSortListaEncadeada(lista);
	cout << endl << endl;
	toViewListaEncadeada(lista);
	

    return 0;
}

