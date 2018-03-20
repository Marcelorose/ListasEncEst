#ifndef LISTA_ESTATICA_H
#define LISTA_ESTATICA_H

#include <iostream>

using namespace std;

const int TAM = 50;


struct Monstro {
	int ataque;
};

struct ListaEstatica {
	Monstro listaEstatica[TAM];
	int qtd;
};

void inicializarListaEstatica(ListaEstatica &l) {
	l.qtd = 0;
}

bool inserirInicioListaEstatica(ListaEstatica &l, Monstro mons) {
	if (l.qtd == TAM)
	{
		return false;
	}

	for (int i = l.qtd; i > 0; i--)
	{
		l.listaEstatica[i] = l.listaEstatica[i - 1];
	}

	l.listaEstatica[0] = mons;
	l.qtd++;
	return true;
}

bool inserirFimListaEstatica(ListaEstatica &l, Monstro mons) {
	if (l.qtd == TAM)
	{
		return false;
	}
	l.listaEstatica[l.qtd] = mons;
	l.qtd++;
	return true;

}

bool inserirPosicaoListaEstatica(ListaEstatica &l, Monstro mons, int pos) {
	if (l.qtd == TAM)
	{
		return false;
	}

	for (int i = l.qtd; i > pos; i--)
	{
		l.listaEstatica[i] = l.listaEstatica[i - 1];
	}
	l.listaEstatica[pos] = mons;
	l.qtd++;
	return true;
}

bool removerInicioListaEstatica(ListaEstatica &l) {
	if (l.qtd == 0)
	{
		return false;
	}
						
	for (int i = 0; i < l.qtd - 1; i++)
	{
		l.listaEstatica[i] = l.listaEstatica[i + 1];
	}
	l.qtd--;
	return true;

}

bool removerFimListaEstatica(ListaEstatica &l) {
	if (l.qtd == 0)
	{
		return  false;
	}
	l.qtd--;
}

bool bubbleSortListaEstatica(ListaEstatica &l) {
	if (l.qtd == 0)
	{
		return false;
	}
	int aux;
	for (int i = 0; i < l.qtd; i++)
	{
		for (int i = 0; i < l.qtd; i++)
		{
			if (l.listaEstatica[i].ataque > l.listaEstatica[i + 1].ataque)
			{
				aux = l.listaEstatica[i + 1].ataque;
				l.listaEstatica[i + 1].ataque = l.listaEstatica[i].ataque;
				l.listaEstatica[i].ataque = aux;
			}
		}
	}

}


void toViewListaEstatica(ListaEstatica &l) {
	for (int i = 0; i < TAM; i++)
	{
		cout << l.listaEstatica[i].ataque << endl;
	}
}


#endif