#include <stdlib.h>
#include <stdio.h>

typedef struct {
	int chave; 
} TItem;

typedef struct celula {
	struct celula *pAnt;
	struct celula *pProx; 
	TItem item; 
} TCelula; 

typedef struct { 
	TCelula *pPrimeiro, *pUltimo; 
} TLista;

void iniciarLista(TLista *pLista)
{
	pLista->pPrimeiro = NULL;
}

int isVazia(TLista *pLista)
{
	return pLista->pPrimeiro == NULL;
}

void imprimir (TLista *pLista) {
printf("Itens da lista: ");
TCelula *celula = pLista->pPrimeiro;

if (celula != NULL) {
 do {
 printf("%d ", celula->item.chave);
 celula = celula->pProx;
 } while (celula != pLista->pPrimeiro);
}
printf("\n");
} 


