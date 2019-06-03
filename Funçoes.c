#include <stdio.h>
#include <stdlib.h>

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
	pLista->pUltimo = NULL;
}

int isVazia(TLista *pLista)
{
	return pLista->pPrimeiro == NULL;
}

int inserir(TLista *pLista, TItem x)
{
	TCelula *novo;
	novo = (TCelula*) malloc (sizeof(TCelula));
	novo->item = x;
	novo->pAnt = NULL;
	novo->pProx = NULL;
	
	if(isVazia (pLista))
	{
		pLista->pPrimeiro = novo;
	}
	else
	{
		pLista->pUltimo->pProx = novo;
		novo->pAnt = pLista->pUltimo;
	}
	pLista->pUltimo = novo;
	return 1;
}

void imprimir (TLista *pLista, int inverso) {
	TCelula *celula;
	printf("Itens da lista: ");
	if (inverso) {
		celula = pLista->pUltimo;
	} else {
		celula = pLista->pPrimeiro;
	}
	while (celula != NULL) {
		printf("%d ", celula->item.chave);
		if (inverso) {
			celula = celula->pAnt;
		} else {
			celula = celula->pProx;
		}
	}
	printf("\n");
} 

int buscaLista(TLista *pLista, int chave)
{
	TCelula *pAux = pLista->pPrimeiro; 
	while(pAux->pProx != NULL)
	{
		if(pAux->item.chave == chave)
		{
			return chave;
		}
		else
		{
			pAux = pAux->pProx;
		}
	}
	return 1;
}

int removeElemento(TLista *pLista, int chave)
{return 1;}
	

int main(){
	TLista Lista;
	TItem item1, item2,item3,item4,item5;
	item1.chave=2;
	item2.chave=3;
	item3.chave=4;
	item4.chave=5;
	item5.chave=6;
	iniciarLista(&Lista); 
	inserir(&Lista, item1);
	inserir(&Lista, item2);
	inserir(&Lista, item3);
	inserir(&Lista, item4);
	inserir(&Lista, item5);
	imprimir(&Lista, 0);
	printf("O valor é: %d", buscaLista(&Lista, 4));
}
