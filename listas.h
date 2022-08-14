#include <stdio.h>
#include <stdlib.h>

typedef struct tipoElem {
	int valor;
	struct tipoElem *prox;
}TNo;

typedef struct tipoLista {
	TNo * inicio;
	TNo *fim;
	int total;
}TLista;
