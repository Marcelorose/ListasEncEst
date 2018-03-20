#ifndef LISTA_DUPLAMENTE_ENCADEADA_H
#define LISTA_DUPLAMENTE_ENCADEADA_H


struct Monstro {
	int ataque;
};

struct ElementoLista2Enc {
	ElementoLista2Enc *anterior;
	Monstro dado;
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

bool inserirInicioLista2Encadeada(Lista2Encadeada &l, Monstro mons) {
	ElementoLista2Enc *novo = new ElementoLista2Enc;
	if (novo == NULL)
	{
		return false;
	}
	novo->dado = mons;
	novo->anterior = NULL;
	if (l.qtd == 0)
	{
		novo->proximo = NULL;
	}
	else
	{
		novo->proximo = l.primeiro;
	}
	l.primeiro = novo;
	l.qtd++;
	return true;
}

bool inserirFimLista2Encadeada(Lista2Encadeada &l, Monstro mons) {

}

bool inserirPosicaoLista2Encadeada(Lista2Encadeada &l, Monstro mons) {

}

bool removerInicioLista2Encadeada(Lista2Encadeada &l) {

}

bool removerFimLista2Encadeada(Lista2Encadeada &l) {

}

bool removerPosicaoLista2Encadeada(Lista2Encadeada &l) {

}

bool bubbleSortLista2Encadeada(Lista2Encadeada &l) {

}


#endif 
