#include <stdlib.h>
#include <stdio.h>

typedef struct {
	int chave;
}TItem;

typedef struct celula{
	struct celula *pProx;
	TItem item;
}TCelula;

typedef struct {
	TCelula *pTopo;
	int tamanho;
}TPilha;

void iniciarPilha (TPilha *pPilha);
int isVazia (TPilha *pPilha);
int push (TPilha *pPilha, TItem x);
int pop (TPilha *pPilha, TItem *pX);
int peek (TPilha *pPilha, TItem *pX);
int tamanho (TPilha *pPilha);

int main() {
	TPilha pilha;
	iniciarPilha (&pilha);
	
	printf("Vazia: %s\n", isVazia(&pilha) == 1 ? "SIM":"NAO");
	
	TItem item1, item2, item3;
	item1.chave = 10;
	item2.chave = -5;
	item3.chave = 20;
	
	push (&pilha, item1);
	push (&pilha, item2);
	push (&pilha, item3);
	
	printf("Vazia: %s\n", isVazia(&pilha) == 1 ? "SIM":"NAO");
	
	TItem itemTeste;
	
	pop (&pilha, &itemTeste);
	printf("Elemento removido: %d\n", itemTeste.chave);
	peek (&pilha, &itemTeste);
	printf("Elemento no topo: %d\n", itemTeste.chave);
	printf("Elementos existentes: %d\n", tamanho(&pilha));
};

void iniciarPilha (TPilha *pPilha) {
	pPilha->pTopo = NULL;
	pPilha->tamanho = 0;
}

int isVazia (TPilha *pPilha) {
	return pPilha->pTopo == NULL;
}

int push (TPilha *pPilha, TItem x) {


	TCelula *p = (TCelula *) malloc(sizeof(TCelula));
	p->item = x;
	
	if(isVazia(pPilha))
		pPilha->pTopo = p;
	
	else{
		p->pProx = pPilha->pTopo;
		pPilha->pTopo = p;
	}
	
	pPilha->tamanho += 1 ;
	
	return 1;
	
}

int pop (TPilha *pPilha, TItem *pX) {


	*pX = pPilha->pTopo->item;
	
	TCelula *Aux = pPilha->pTopo;
	
	pPilha->pTopo = Aux->pProx;
	
	pPilha->tamanho -= 1 ;
	free(Aux);
	
	return 1;
}

int peek (TPilha *pPilha, TItem *pX) {

	*pX = pPilha->pTopo->item;
	
	return 1;
}

int tamanho (TPilha *pPilha) {
	return pPilha->tamanho;
}

