#ifndef LISTA_DUPLAMENTE_ENCADEADA_H
#define LISTA_DUPLAMENTE_ENCADEADA_H

#include <iostream>

using namespace std;


struct ElementoLista2Enc {
	ElementoLista2Enc *anterior;
	int dado;
	ElementoLista2Enc *proximo;
};

struct Lista2Encadeada {
	ElementoLista2Enc *primeiro;
	ElementoLista2Enc *ultimo;
	int qtd;
};

void inicializarLista2Encadeada(Lista2Encadeada &l) {
	l.primeiro = NULL;
	l.qtd = 0;
	l.ultimo = NULL;
}

bool inserirInicioLista2Encadeada(Lista2Encadeada &l, int mons) {
	ElementoLista2Enc *novo = new ElementoLista2Enc;
	if (novo == NULL)
	{
		return false;
	}
	novo->dado = mons;
	novo->anterior = NULL;
	novo->proximo = NULL;
	if (l.qtd == 0)
	{
		l.ultimo = novo;
	}
	else
	{
		l.primeiro->anterior = novo;
		novo->proximo = l.primeiro;
	}
	l.primeiro = novo;
	l.qtd++;
	return true;
}

bool inserirFimLista2Encadeada(Lista2Encadeada &l, int mons) {
	if (l.qtd == 0)
	{
		return inserirInicioLista2Encadeada(l, mons);
	}
	ElementoLista2Enc *novo = new ElementoLista2Enc;
	if (novo == NULL)
	{
		return false;
	}
	novo->dado = mons;
	novo->anterior = l.ultimo;
	novo->proximo = NULL;
	l.ultimo->proximo = novo;
	l.ultimo = novo;
	l.qtd++;
	return true;

}

bool inserirPosicaoLista2Encadeada(Lista2Encadeada &l, int mons, int pos) {
	if (pos < 0 || pos > l.qtd + 1)
	{
		return false;
	}
	if (pos == 0)
	{
		return inserirInicioLista2Encadeada(l, mons);
	}
	if (pos == l.qtd)
	{
		return inserirFimLista2Encadeada(l, mons);
	}
	ElementoLista2Enc *novo = new ElementoLista2Enc;
	if (novo == NULL)
	{
		return false;
	}
	novo->dado = mons;
	ElementoLista2Enc *nav = l.primeiro;
	for (int i = 0; i < pos - 1; i++)
	{
		nav = nav->proximo;
	}
	ElementoLista2Enc *nav1 = nav->proximo;
	novo->anterior = nav;
	novo->proximo = nav->proximo;
	nav->proximo = novo;
	nav1->anterior = novo;
	l.qtd++;
	return true;
}

bool removerInicioLista2Encadeada(Lista2Encadeada &l) {
	if (l.qtd == 0)
	{
		return false;
	}
	ElementoLista2Enc *save = l.primeiro;
	if (l.qtd == 1)
	{
		l.primeiro = NULL;
		l.ultimo = NULL;
		delete save;
		l.qtd--;
		return true;
	}
	l.primeiro = l.primeiro->proximo;
	delete save;
	l.qtd--;
	return true;

}

bool removerFimLista2Encadeada(Lista2Encadeada &l) {
	ElementoLista2Enc *save = l.ultimo;
	if (l.qtd == 0)
	{
		return false;
	}
	if (l.qtd == 1)
	{
		removerInicioLista2Encadeada(l);
	}
	save->anterior->proximo = NULL;
	l.ultimo = save->anterior;
	delete save;
	l.qtd--;
	return true;
}

bool removerPosicaoLista2Encadeada(Lista2Encadeada &l, int pos) {
	if (pos < 0 || pos >= l.qtd)
	{
		return false;
	}
	if (pos == 0)
	{
		return removerInicioLista2Encadeada(l);
	}
	if (pos == l.qtd - 1)
	{
		return removerFimLista2Encadeada(l);
	}
	ElementoLista2Enc *save = l.primeiro;
	for (int i = 0; i < pos - 1; i++)
	{
		save = save->proximo;
	}
	ElementoLista2Enc *save1 = save->proximo;
	save->proximo = save1->proximo;
	save1->proximo->anterior = save->anterior;
	delete save1;
	l.qtd--;
	return true;
}

bool bubbleSortLista2Encadeada(Lista2Encadeada &l) {
	if (l.qtd == 0)
	{
		return false;
	}
	ElementoLista2Enc *nav = l.primeiro;
	int aux;
	for (int i = 0; i < l.qtd; i++)
	{
		nav = l.primeiro;
		for (int j = 0; j < l.qtd - 1; j++)
		{
			if (nav->dado > nav->proximo->dado)
			{
				aux = nav->dado;
				nav->dado = nav->proximo->dado;
				nav->proximo->dado = aux;

			}
			nav = nav->proximo;
		}
	}
	return true;
}

void toViewLista2Encadeada(Lista2Encadeada &l) {
	ElementoLista2Enc *view = l.primeiro;
	while (view != NULL)
	{
		cout << view->dado << endl;
		view = view->proximo;
	}
}

#endif 
