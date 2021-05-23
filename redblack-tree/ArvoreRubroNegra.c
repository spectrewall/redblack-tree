/*********************************************************************
* Arquivo ArvoreRubroNegra.c para trabalhar com arvores Rubro Negras *
* Aluno: Wallace Luiz Carvalho de Andrade                            *
*********************************************************************/

#include "ArvoreRubroNegra.h"

/* Rotação a Esquerda do No */
void rotacaoEsquerda(nohVP **Arvore_PV, nohVP *noh, nohVP *vazio)
{
    nohVP *y;

    if (((*Arvore_PV)->pai == vazio) && (noh->direita != vazio))
    {
        y = noh->direita;
        noh->direita = y->esquerda;
        y->esquerda->pai = noh;
        y->pai = noh->pai;

        if (noh->pai == vazio)
        {
            *Arvore_PV = y;
        }
        else if (noh == noh->pai->esquerda)
        {
            noh->pai->esquerda = y;
        }
        else
        {
            noh->pai->direita = y;
        }
    }
    y->esquerda = noh;
    noh->pai = y;
    (*Arvore_PV)->pai = vazio;
}

/* Rotação a Direita do No */
void rotacaoDireita(nohVP **Arvore_PV, nohVP *noh, nohVP *vazio)
{
    nohVP *y;

    if (((*Arvore_PV)->pai == vazio) && (noh->esquerda != vazio))
    {
        y = noh->esquerda;
        noh->esquerda = y->direita;
        y->direita->pai = noh;
        y->pai = noh->pai;

        if (noh->pai == vazio)
        {
            *Arvore_PV = y;
        }
        else if (noh == noh->pai->direita)
        {
            noh->pai->direita = y;
        }
        else
        {
            noh->pai->esquerda = y;
        }
    }
    y->direita = noh;
    noh->pai = y;
    (*Arvore_PV)->pai = vazio;
}

/* Inserção na Árvore */
nohVP *inserir_Novo_Noh_PV(nohVP **Arvore_PV, nohVP *noh, nohVP *vazio)
{
    nohVP *y = vazio;
    nohVP *x = *Arvore_PV;

    if ((*Arvore_PV) == NULL)
    {
        *Arvore_PV = noh;
        (*Arvore_PV)->pai = vazio;
        vazio->pai = *Arvore_PV;
        (*Arvore_PV)->cor = 'P';
        return;
    }

    if ((*Arvore_PV)->info.id == noh->info.id)
    {
        printf(" Numero duplicado, Coloque outro numero !!\n\n");
        return;
    }

    while (x != vazio)
    {
        y = x;

        if (noh->info.id < x->info.id)
        {
            x = x->esquerda;
        }
        else
        {
            x = x->direita;
        }
    }

    noh->pai = y;

    if (noh->info.id < y->info.id)
    {
        y->esquerda = noh;
    }
    else if (noh->info.id > y->info.id)
    {
        y->direita = noh;
    }
    else if (noh->info.id == y->info.id)
    {
        printf("Numeros iguais, Tente outro numero !!\n\n");
    }

    noh->esquerda = vazio;
    noh->direita = vazio;
    noh->cor = 'V';

    inserirCorVP(&(*Arvore_PV), noh, vazio);
    return noh;
}

/* Insere a cor do No e faz o balanceamento se necessário */
void inserirCorVP(nohVP **Arvore_PV, nohVP *noh, nohVP *vazio)
{
    nohVP *y;

    while (noh->pai->cor == 'V')
    {
        if (noh->pai == noh->pai->pai->esquerda)
        {
            y = noh->pai->pai->direita;

            if (y->cor == 'V')
            {
                noh->pai->cor = 'P';
                y->cor = 'P';
                noh->pai->pai->cor = 'V';
                noh = noh->pai->pai;
            }
            else
            {
                if (noh == noh->pai->direita)
                {
                    noh = noh->pai;
                    rotacaoEsquerda(&(*Arvore_PV), noh, vazio);
                }

                noh->pai->cor = 'P';
                noh->pai->pai->cor = 'V';
                rotacaoDireita(&(*Arvore_PV), noh->pai->pai, vazio);
            }
        }
        else
        {
            y = noh->pai->pai->esquerda;

            if (y->cor == 'V')
            {
                noh->pai->cor = 'P';
                y->cor = 'P';
                noh->pai->pai->cor = 'V';
                noh = noh->pai->pai;
            }
            else
            {
                if (noh == noh->pai->esquerda)
                {
                    noh = noh->pai;
                    rotacaoDireita(&(*Arvore_PV), noh, vazio);
                }

                noh->pai->cor = 'P';
                noh->pai->pai->cor = 'V';
                rotacaoEsquerda(&(*Arvore_PV), noh->pai->pai, vazio);
            }
        }
    }

    (*Arvore_PV)->cor = 'P';
}

/* Remove o No da Arvore */
nohVP *removerVP(nohVP **Arvore_PV, nohVP *noh, nohVP *vazio)
{
    nohVP *y, *x;

    if ((noh->esquerda == vazio) || (noh->direita == vazio))
    {
        y = noh;
    }
    else
    {
        y = sucessorVP(noh, vazio);
    }

    if (y->esquerda != vazio)
    {
        x = y->esquerda;
    }
    else
    {
        x = y->direita;
    }

    x->pai = y->pai;

    if (y->pai == vazio)
    {
        *Arvore_PV = x;
    }
    else if (y == y->pai->esquerda)
    {
        y->pai->esquerda = x;
    }
    else
    {
        y->pai->direita = x;
    }

    if (y != noh)
    {
        noh->info = y->info;
    }

    if (y->cor == 'P')
    {

        if ((*Arvore_PV)->direita == vazio && (*Arvore_PV)->esquerda->direita != vazio)
        {

            rotacaoEsquerda(&(*Arvore_PV), (*Arvore_PV)->esquerda, vazio);
            removerCorVP(&(*Arvore_PV), (*Arvore_PV)->esquerda, vazio);
            rotacaoDireita(&(*Arvore_PV), (*Arvore_PV), vazio);
        }
        else
        {

            if ((*Arvore_PV)->esquerda == vazio && (*Arvore_PV)->direita->esquerda != vazio)
            {

                rotacaoDireita(&(*Arvore_PV), (*Arvore_PV)->direita, vazio);
                removerCorVP(&(*Arvore_PV), (*Arvore_PV)->direita, vazio);
                rotacaoEsquerda(&(*Arvore_PV), (*Arvore_PV), vazio);
            }
        }
        removerCorVP(&(*Arvore_PV), x, vazio);
    }
    return y;
    free(y);
    free(x);
}

/* Faz o balaceamento da cor caso tenha alguma incosistencia */
void removerCorVP(nohVP **Arvore_PV, nohVP *noh, nohVP *vazio)
{
    nohVP *aux;

    while (((*Arvore_PV) != noh) && (noh->cor == 'P'))
    {
        if (noh == noh->pai->esquerda)
        {
            aux = noh->pai->direita;

            if (aux->cor == 'V')
            {
                aux->cor = 'P';
                noh->pai->cor = 'V';
                rotacaoEsquerda(&(*Arvore_PV), noh->pai, vazio);
                aux = noh->pai->direita;
            }

            if ((aux->esquerda->cor == 'P') && (aux->direita->cor == 'P'))
            {
                aux->cor = 'V';
                noh = noh->pai;
            }
            else if (aux->direita->cor == 'P')
            {
                aux->esquerda->cor = 'P';
                aux->cor = 'V';
                rotacaoDireita(&(*Arvore_PV), aux, vazio);
                aux = noh->pai->direita;
                aux->cor = noh->pai->cor;
                noh->pai->cor = 'P';
                aux->direita->cor = 'P';
                rotacaoEsquerda(&(*Arvore_PV), noh->pai, vazio);
                noh = *Arvore_PV;
            }
        }
        else
        {
            aux = noh->pai->esquerda;

            if (aux->cor == 'V')
            {
                aux->cor = 'P';
                noh->pai->cor = 'V';
                rotacaoDireita(&(*Arvore_PV), noh->pai, vazio);
                aux = noh->pai->esquerda;
            }

            if ((aux->esquerda->cor == 'P') && (aux->direita->cor == 'P'))
            {
                aux->cor = 'V';
                noh = noh->pai;
            }
            else if (aux->esquerda->cor == 'P')
            {
                aux->direita->cor = 'P';
                aux->cor = 'V';
                rotacaoEsquerda(&(*Arvore_PV), aux, vazio);
                aux = noh->pai->esquerda;
                aux->cor = noh->pai->cor;
                noh->pai->cor = 'P';
                aux->esquerda->cor = 'P';
                rotacaoDireita(&(*Arvore_PV), noh->pai, vazio);
                noh = *Arvore_PV;
            }
        }
    }
    noh->cor = 'P';
}

/* Sucessor do noh para o balaceamento */
nohVP *sucessorVP(nohVP *noh, nohVP *vazio)
{
    nohVP *aux;

    if (noh->direita != vazio)
    {
        return minimoVP(noh->direita, vazio);
    }

    aux = noh->pai;

    while ((aux != vazio) && (noh == aux->direita))
    {
        noh = aux;
        aux = aux->pai;
    }

    return aux;
}

/* Maximo da Arvore */
nohVP *maximoVP(nohVP *noh, nohVP *vazio)
{
    while (noh->direita != vazio)
    {
        noh = noh->direita;
    }
    return noh;
}

/* Minimo da Arvore */
nohVP *minimoVP(nohVP *noh, nohVP *vazio)
{
    while (noh->esquerda != vazio)
    {
        noh = noh->esquerda;
    }
    return noh;
}

/* Cria o no para a Arvore */
nohVP *criaNovoNoh(nohVP *vazio)
{
    nohVP *novo;
    novo = (nohVP *)malloc(sizeof(nohVP));
    printf("Informe um ID: ");
    fflush(stdin);
    scanf("%d", &novo->info.id);
    if (novo->info.id < 0)
    {
        printf("Numero Invalido! Tente Novamente !!!\n");
        return criaNovoNoh(vazio);
    }

    printf("\nInforme o Ano: ");
    fflush(stdin);
    scanf("%d", &novo->info.ano);
    getchar();

    printf("\nInforme o Autor: ");
    fflush(stdin);
    fgets(novo->info.autor, 200, stdin);

    printf("\nInforme o Titulo: ");
    fflush(stdin);
    fgets(novo->info.titulo, 200, stdin);

    printf("\nInforme a Revista: ");
    fflush(stdin);
    fgets(novo->info.revista, 200, stdin);

    printf("\nInforme o DOI: ");
    fflush(stdin);
    fgets(novo->info.DOI, 200, stdin);

    printf("\nInforme a Palavra Chave: ");
    fflush(stdin);
    fgets(novo->info.palavraChave, 200, stdin);

    novo->cor = 'V';
    novo->pai = vazio;
    novo->direita = vazio;
    novo->esquerda = vazio;

    return novo;
}

/* Impressão da Árvore */
void imprimeArvore(nohVP *Arvore_PV, nohVP *vazio, int cont)
{
    int i;

    if (Arvore_PV != vazio)
    {
        imprimeArvore(Arvore_PV->direita, vazio, cont + 1);
        for (i = 0; i < cont; i++)
            printf("\t");
        printf("%d: %c", Arvore_PV->info.id, Arvore_PV->cor);
        printf("\n");
        imprimeArvore(Arvore_PV->esquerda, vazio, cont + 1);
    }
}

/* Localizar o noh da Arvore para devidas alterações ou remoções */
nohVP *localizar_Noh_Arvore(nohVP *noh, int id, nohVP *vazio)
{
    if ((noh == vazio) || (noh->info.id == id))
    {
        return noh;
    }

    if (id < noh->info.id)
    {
        return localizar_Noh_Arvore(noh->esquerda, id, vazio);
    }
    else
    {
        return localizar_Noh_Arvore(noh->direita, id, vazio);
    }
}

/* Imprimir os dados de um Nó */
void imprimirDados(nohVP *noh)
{
    printf("\n\n*****************\n");
    printf("ID: %d\n", noh->info.id);
    printf("Ano: %d\n", noh->info.ano);
    printf("Autor: %s\n", noh->info.autor);
    printf("Titulo: %s\n", noh->info.titulo);
    printf("Revista: %s\n", noh->info.revista);
    printf("DOI: %s\n", noh->info.DOI);
    printf("Palavra Chave: %s\n", noh->info.palavraChave);
    printf("\n*****************\n\n");
}
