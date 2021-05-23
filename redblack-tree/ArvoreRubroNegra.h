/*********************************************************************
* Arquivo ArvoreRubroNegra.h para trabalhar com arvores Rubro Negras *
* Aluno: Wallace Luiz Carvalho de Andrade                            *
*********************************************************************/

#ifndef ARVORERUBRONEGRA_H
#define ARVORERUBRONEGRA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Estrutura solicitada para os dados*/
struct artigo
{
	int id;
	int ano;
	char autor[200];
	char titulo[200];
	char revista[200];
	char DOI[20];
	char palavraChave[200];
};

/*Estrutura para a Árvore Rubro Negra*/
typedef struct noh
{
	struct artigo info;
	char cor;
	struct noh *pai;
	struct noh *esquerda;
	struct noh *direita;
} nohVP;

/********************** Funções **********************/
nohVP *criaNovoNoh(nohVP *vazio);
void rotacaoEsquerda(nohVP **Arvore_PV, nohVP *noh, nohVP *vazio);
void rotacaoDireita(nohVP **Arvore_PV, nohVP *noh, nohVP *vazio);
nohVP *inserir_Novo_Noh_PV(nohVP **Arvore_PV, nohVP *noh, nohVP *vazio);
void inserirCorVP(nohVP **Arvore_PV, nohVP *noh, nohVP *vazio);
void removerCorVP(nohVP **Arvore_PV, nohVP *noh, nohVP *vazio);
nohVP *sucessorVP(nohVP *noh, nohVP *vazio);
nohVP *maximoVP(nohVP *noh, nohVP *vazio);
nohVP *minimoVP(nohVP *noh, nohVP *vazio);
nohVP *localizar_Noh_Arvore(nohVP *noh, int id, nohVP *vazio);
nohVP *rotacaoDireitaEsquerda(nohVP *arvore);
nohVP *rotacaoEsquerdaDireita(nohVP *arvore);
nohVP *removerVP(nohVP **Arvore_PV, nohVP *noh, nohVP *vazio);
void imprimeArvore(nohVP *Arvore_PV, nohVP *vazio, int cont);
void imprimirDados(nohVP *noh);

#endif
