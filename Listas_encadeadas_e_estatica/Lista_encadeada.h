#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H


struct Monstro {
	int ataque;
};


struct ElementoListaEnc {
	Monstro dado;
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

bool inserirInicioListaEncadeada(ListaEncadeada &l, Monstro mons) {
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

bool inserirFimListaEncadeada(ListaEncadeada &l, Monstro mons) {
	ElementoListaEnc *novo = new ElementoListaEnc;
	if (novo == NULL)
	{
		return false;
	}
	if (l.qtd == 0)
	{
		return inserirInicioListaEncadeada;
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

bool inserirPosicaoListaEncadeada(ListaEncadeada &l, Monstro mons) {
	ElementoListaEnc *novo = new ElementoListaEnc;
	if (novo == NULL)
	{
		return false;
	}
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

	ElementoListaEnc *ultimo;
	while (ultimo->prox->prox != NULL)
	{
		ultimo = ultimo->prox;
	}
	delete ultimo->prox;
	ultimo->prox = NULL;
	l.qtd--;
	return true;
}

bool removerPosicaoListaEncadeada(ListaEncadeada &l) {

}

bool bubbleSortListaEncadeada(ListaEncadeada &l) {

}

#endif
