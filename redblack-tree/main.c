/*********************************************************************
* Arquivo main.c para trabalhar com arvores Rubro Negras             *
* Aluno: Wallace Luiz Carvalho de Andrade                            *
*********************************************************************/

#include "ArvoreRubroNegra.h"

int menu()
{
    int opcao;

    printf("1.Inserir No na arvore....:\n");
    printf("2.Mostrar arvore..........:\n");
    printf("3.Remover No da arvore....:\n");
    printf("4.Buscar No da arvore.....:\n");
    printf("0.Sair do programa........:\n");
    printf("?: ");

    scanf("%d", &opcao);
    return opcao;
}

nohVP *vazio = NULL;

int main()
{
    nohVP *Arvore_PV = NULL;
    nohVP *aux;
    int valor, altura, opc;

    vazio = (nohVP *)malloc(sizeof(nohVP));
    vazio->pai = Arvore_PV;
    vazio->direita = vazio->esquerda = vazio;

    do
    {
        opc = menu();
        switch (opc)
        {

        case 1:
            inserir_Novo_Noh_PV(&Arvore_PV, criaNovoNoh(vazio), vazio);
            break;
        case 2:
            printf("Listagem dos nohs da Arvore \n\n");
            if (Arvore_PV != NULL)
            {
                imprimeArvore(Arvore_PV, vazio, 0);
            }
            else
            {
                printf("Sem Elementos na Arvore \n");
            }
            break;
        case 3:
            if (Arvore_PV != NULL)
            {
                printf("Digite o ID da Arvore para remover: \n");
                scanf("%d", &valor);
                aux = localizar_Noh_Arvore(Arvore_PV, valor, vazio);
                if (aux->info.id == valor)
                {
                    removerVP(&Arvore_PV, aux, vazio);
                }
                else
                {
                    printf("\nO ID %d nao foi encontrado!\n\n", valor);
                }
                if (Arvore_PV == vazio)
                {
                    vazio = (nohVP *)malloc(sizeof(nohVP));
                    vazio->pai = Arvore_PV = NULL;
                    vazio->direita = vazio->esquerda = vazio;
                }
            }
            else
            {
                printf("Sem Elementos na Arvore \n");
            }
            break;
        case 4:
            if (Arvore_PV != NULL)
            {
                printf("Digite o ID: \n");
                scanf("%d", &valor);
                aux = localizar_Noh_Arvore(Arvore_PV, valor, vazio);
                if (aux->info.id == valor)
                {
                    imprimirDados(aux);
                }
                else
                {
                    printf("\nO ID %d nao foi encontrado!\n\n", valor);
                }
            }
            else
            {
                printf("Sem Elementos na Arvore \n");
            }
            break;
        }
    } while (opc != 0);

    return 0;
}
