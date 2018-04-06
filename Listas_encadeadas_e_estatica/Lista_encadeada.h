#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

#include <iostream>

using namespace std;


struct ElementoListaEnc {
	int dado;
	ElementoListaEnc *prox;
};

struct ListaEncadeada {
	ElementoListaEnc *primeiro;
	int qtd;
};

void inicializarListaEncadeada(ListaEncadeada &l) {
	l.primeiro = NULL;
	l.qtd = 0;
}

bool inserirInicioListaEncadeada(ListaEncadeada &l, int mons) {
	ElementoListaEnc *novo = new ElementoListaEnc;
	if (novo == NULL)
	{
		return false;
	}
	novo->dado = mons;
	novo->prox = l.primeiro;
	l.primeiro = novo;
	l.qtd++;
	return true;

}

bool inserirFimListaEncadeada(ListaEncadeada &l, int mons) {
	if (l.qtd == 0)
	{
		inserirInicioListaEncadeada(l, mons);
	}
	ElementoListaEnc *novo = new ElementoListaEnc;
	if (novo == NULL)
	{
		return false;
	}
	novo->dado = mons;
	novo->prox = NULL;
	ElementoListaEnc *ultimo = l.primeiro;
	while (ultimo->prox != NULL)
	{
		ultimo = ultimo->prox;
	}
	ultimo->prox = novo;
	l.qtd++;
	return true;
}

bool inserirPosicaoListaEncadeada(ListaEncadeada &l, int mons, int pos) {
	if (pos < 0 || pos > l.qtd + 1)
	{
		return false;
	}
	if (pos == 0)
	{
		return inserirInicioListaEncadeada(l, mons);
	}
	if (pos == l.qtd)
	{
		return inserirFimListaEncadeada(l, mons);
	}
	ElementoListaEnc *novo = new ElementoListaEnc;
	if (novo == NULL)
	{
		return false;
	}
	novo->dado = mons;
	ElementoListaEnc *nav = l.primeiro;
	for (int i = 0; i < pos; i++)
	{
		nav = nav->prox;
	}
	novo->prox = nav->prox;
	nav->prox = novo;
	l.qtd++;
	return true;
}

bool removerInicioListaEncadeada(ListaEncadeada &l) {
	if (l.qtd == 0)
	{
		return false;
	}
	ElementoListaEnc *save = l.primeiro;
	l.primeiro = l.primeiro->prox;
	delete save;
	l.qtd--;
	return true;

}

bool removerFimListaEncadeada(ListaEncadeada &l) {
	if (l.qtd == 0)
	{
		return false;
	}

	ElementoListaEnc *ultimo = l.primeiro;
	while (ultimo->prox->prox != NULL)
	{
		ultimo = ultimo->prox;
	}
	delete ultimo->prox;
	ultimo->prox = NULL;
	l.qtd--;
	return true;
}

bool removerPosicaoListaEncadeada(ListaEncadeada &l, int pos) {
	if (pos < 0 || pos >= l.qtd)
	{
		return false;
	}
	if (pos == 0)
	{
		return removerInicioListaEncadeada(l);
	}
	if (pos == l.qtd - 1)
	{
		return removerFimListaEncadeada(l);
	}
	ElementoListaEnc *save = l.primeiro;
	for (int i = 0; i < pos - 1; i++)
	{
		save = save->prox;
	}
	ElementoListaEnc *save1 = save->prox;
	save->prox = save->prox->prox;
	delete save1;
	l.qtd--;
	return true;
	
}

bool bubbleSortListaEncadeada(ListaEncadeada &l) {
	if (l.qtd == 0)
	{
		return false;
	}
	ElementoListaEnc *nav = l.primeiro;
	int aux;
	for (int i = 0; i < l.qtd; i++)
	{
		nav = l.primeiro;
		for (int j = 0; j < l.qtd - 1; j++)
		{
			if (nav->dado > nav->prox->dado)
			{
				aux = nav->dado;
				nav->dado = nav->prox->dado;
				nav->prox->dado = aux;
				
			}
			nav = nav->prox;
		}
	}
	return true;
} //fazer //fazer

void toViewListaEncadeada(ListaEncadeada &l) {
	ElementoListaEnc *nav = l.primeiro;
	while (nav != NULL)
	{
		cout << nav->dado <<"  " << nav << "   " << nav->prox << endl;
		nav = nav->prox;
	}
}

#endif
