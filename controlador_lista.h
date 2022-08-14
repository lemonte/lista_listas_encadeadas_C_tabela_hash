#include "listas.h"

void inicializaLista(TLista *lista)
{
	lista->inicio = NULL;
	lista->fim = NULL;
	lista->total = 0;
}

int removerElemento(TLista *L, int valor)
{

	if (L->inicio != NULL)

	{
		TNo *atual = L->inicio, *previo = NULL;
		TNo *proximo = atual->prox;
		int removido = 0;

		while (atual != NULL)
		{
			if (atual->valor == valor)
			{
				proximo = atual->prox;

				if (previo == NULL)
					L->inicio = proximo;
				else
					previo->prox = proximo;
				if (L->fim == atual)
					L->fim = previo;

				free(atual);
				removido = 1;
				L->total--;
				break;
			} // if
			previo = atual;
			atual = atual->prox;
			if (atual != NULL)
				proximo = atual->prox;
			else
				proximo = NULL;
		} // while

		if (!removido)
		{
			return 0;
		}
		return 1;
	}
	return 0;
}

void insereElemento(TLista *L, int num)
{
	TNo *novo = (TNo *)malloc(sizeof(TNo));
	TNo *atual = NULL;
	TNo *anterior;
	int inserido = 0;

	novo->valor = num;
	novo->prox = NULL;

	if (L->inicio == NULL)
	{
		L->inicio = novo;
		L->fim = novo;
		L->total++;
	}
	else
	{
		atual = L->inicio;
		anterior = NULL;

		while (atual != NULL)
		{
			if (atual->valor >= novo->valor)
			{
				novo->prox = atual;
				if (anterior == NULL)
				{
					L->inicio = novo;
				}
				else
				{
					anterior->prox = novo;
				}
				inserido = 1;
				L->total++;
				break;
			}
			anterior = atual;
			atual = atual->prox;
		}
		if (!inserido)
		{
			L->fim->prox = novo;
			L->fim = novo;
		}
		L->fim = novo;
	}
}

int mostrarElementoLista(TLista *L, int elemento)
{
	if (L->inicio != NULL)
	{
		TNo *atual = L->inicio;
		while (atual != NULL)
		{
			if (atual->valor == elemento)
			{
				printf("\n");
				printf("valor -> %d", atual->valor);
				printf("\n");
				return 1;
			}
			atual = atual->prox;
		}
	}
	return 0;
}

void mostrarTodaLista(TLista *L)
{
	if (L->inicio != NULL)
	{
		TNo *atual = L->inicio;
		while (atual != NULL)
		{
			printf("\n");
			printf("valor -> %d", atual->valor);
			printf("\n");
			atual = atual->prox;
		}
	}
}
