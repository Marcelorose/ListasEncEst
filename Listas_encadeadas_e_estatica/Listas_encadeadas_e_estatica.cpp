// Listas_encadeadas_e_estatica.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include "Lista_estatica.h"
#include "Lista_encadeada.h"


int main()
{
	ListaEstatica lista;
	Monstro a, b, c, d;
	a.ataque = 10; b.ataque = 40, c.ataque = 20; d.ataque = 100;
	inicializarListaEstatica(lista);
	
	//arrumar bubblesort lista estatica

	toViewListaEstatica(lista);

	

    return 0;
}

