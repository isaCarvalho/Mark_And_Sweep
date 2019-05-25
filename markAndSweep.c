#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct lista
{
    int mark;
    struct lista *prox;
} *Lista;

Lista inserir(Lista l, int v)
{
    Lista novo = (Lista) malloc(sizeof(struct lista));

    novo->mark = v;
    novo->prox = l;
    l = novo;

    return l;
}

Lista remover(Lista l)
{
    Lista ant = NULL, p = l;

    for (; p != NULL; p = p->prox)
    {
        if (p->mark <= 10)
        {
            if (ant == NULL)
                l = p->prox;
            else if (p->prox == NULL)
                ant->prox = NULL;
            else
                ant->prox = p->prox;

            free(p);
        }
        else
            ant = p;
    }

    return l;
}

void imprimir(Lista l)
{
    for (Lista p = l; p != NULL; p = p->prox)
        printf("%d ", p->mark);
}

Lista ventre()
{
    Lista l = NULL;

    for (int i = 0; i < 20; i++)
    {
        l = inserir(l, rand() % 18);
    }

    return l;
}

void main(void)
{
    srand(time(NULL));

    Lista l = ventre();

    imprimir(l);

    printf("\n\n-----------------------------------------------\n\n");

    l = remover(l);

    imprimir(l);

}