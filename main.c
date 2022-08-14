#include "controlador_lista.h"

void inicializa_lista(int tamanho_vetor, TLista lista[])
{
	int i = 0;
	for (i = 0; i < tamanho_vetor; i++)
	{
		inicializaLista(&lista[i]);
	}
}

int inserirElemento()
{
	int entrada = -1;
	scanf(" %d", &entrada);
	return entrada;
}
void adicionarLista_Hash(int entrada, int tamanho_vetor, TLista lista[])
{
	int sobra = entrada % tamanho_vetor;
	insereElemento(&lista[sobra], entrada);	
}

void consultarLista_Hash(int entrada, int tamanho_vetor, TLista lista[])
{
	int sobra = entrada % tamanho_vetor;
	int encontrado = mostrarElementoLista(&lista[sobra], entrada);
	if(encontrado == 1){
		printf("\n\n ###### Elemento encontrado na posicao %d ######### \n\n", sobra);
	}else{
		printf("\n\n ###### Elemento não encontrado na lista ######### \n\n");
	}
}


void removerLista_Hash(int entrada, int tamanho_vetor, TLista lista[])
{
	int sobra = entrada % tamanho_vetor;
	int removido = removerElemento(&lista[sobra], entrada);
	if(removido == 1){
		printf("\n\n ###### Elemento removido com sucesso ######### \n\n");
	}else{
		printf("\n\n ###### Elemento não encontrado na lista ######### \n\n");
	}
}


void mostrarElementoListaHash( int tamanho_vetor, TLista lista[]){
	int posicao = 0;
	for(posicao = 0; posicao < tamanho_vetor; posicao ++){
		mostrarTodaLista(&lista[posicao]);
	}
}


void opcoesMenu()
{
	printf("\n ==== MENU ===== \n");
	printf("\n ==== 1 - INSERIR ===== \n");
	printf("\n ==== 2 - LISTAR ===== \n");
	printf("\n ==== 3 - REMOVER ===== \n");
	printf("\n ==== 4 - CONSULTAR ELEMENTO ===== \n");
	printf("\n ==== 5 - SAIR ===== \n");
}

void removerDaLista(TLista *L, int tamanho_vetor)
{
	printf("Digite o elemento que deseja remover: ");
	int elemento = inserirElemento();
	removerLista_Hash( elemento, tamanho_vetor,L);
}
void consultarNaLista(TLista *L, int tamanho_vetor)
{
	printf("Digite o elemento que deseja consultar: ");
	int elemento = inserirElemento();
	consultarLista_Hash( elemento, tamanho_vetor,L);
}


void adicionarNaLista(TLista L[], int tamanho_vetor)
{
	printf("Digite o elemento que deseja inserir: ");
	int elemento = inserirElemento();
	adicionarLista_Hash(elemento, tamanho_vetor, L);
}

int tamanho_lista()
{
	printf("Digite o tamanho da lista: ");
	return inserirElemento();
}


int menu(int tamanho_vetor, TLista l[])
{
	int opcao = -1;
	do
	{
		opcoesMenu();
		opcao = inserirElemento();
		switch (opcao)
		{
		case 1:
			adicionarNaLista(l, tamanho_vetor);
			printf("\n\n##### ELEMENTO ADICIONADO ###### \n\n");
			break;
		case 2:
			printf("\n\n##### LISTA DE ELEMENTOS ######\n\n");
			mostrarElementoListaHash(tamanho_vetor,l);
			break;
		case 3:
			removerDaLista(l, tamanho_vetor);
			break;
		case 4:
			printf("\n\n##### CONSULTAR ELEMENTO ######\n\n");
			consultarNaLista(l, tamanho_vetor);
			break;
		case 5:
			printf("Saindo do programa");
			break;
		}
	} while (opcao != 5);
	return 0;
}

int main(int argc, const char *argv[])
{
	int tamanho_vetor = tamanho_lista();
	TLista *l;
	l = (TLista *) malloc(tamanho_vetor * sizeof(TLista));
	inicializa_lista(tamanho_vetor, l);
	menu(tamanho_vetor, l);
	return 0;
}
