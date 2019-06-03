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
	TCelula *pInicio;
	TCelula *pFim;
	int tamanho;
}TFila;

