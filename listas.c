#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inserir_lista1(int **lista, int *tamanho, int valor) {
for (int i = 0; i < *tamanho; i++) {
        if ((*lista)[i] == valor)
            return; 
    }
    int *temp = realloc(*lista, (*tamanho + 1) * sizeof(int));
    if (!temp) {
        printf("erro na alocação\n");
        return;
    }
    *lista = temp;
    (*lista)[*tamanho] = valor;
    (*tamanho)++;
}

int inserir_lista2(int **lista, int tamanho, int valor) {
for (int i = 0; i < tamanho; i++) {
        if ((*lista)[i] == valor) {
            return tamanho;
        }
    }
    int *temp = realloc(*lista, (tamanho + 1) * sizeof(int));
    if (!temp) {
        printf("erro na alocação\n");
        return tamanho;
    }
    *lista = temp;
    (*lista)[tamanho] = valor;
    return tamanho + 1;
}

void exibir(int *lista, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");
}

void exibir_comuns(int *lista1, int tam1, int *lista2, int tam2) {
    printf("Números comuns nas duas listas:\n");
    for (int i = 0; i < tam1; i++) {
    for (int j = 0; j < tam2; j++) {
            if (lista1[i] == lista2[j]) {
                printf("%d ", lista1[i]);
                break;
            }
        }
    }
    printf("\n");
}

int excluir_pares(int *lista, int tamanho) {
    int j = 0;
    for (int i = 0; i < tamanho; i++) {
        if (lista[i] % 2 != 0) {
            lista[j++] = lista[i];
        }
    }
    return j;
}

void unir_lista2_na_lista1(int **lista1, int *tam1, int *lista2, int tam2) {
    for (int i = 0; i < tam2; i++) {
        int val = lista2[i];
        int duplicado = 0;
     for (int j = 0; j < *tam1; j++) {
            if ((*lista1)[j] == val) {
                duplicado = 1;
                break;
            }
        }
        if (!duplicado) {
            int *temp = realloc(*lista1, (*tam1 + 1) * sizeof(int));
            if (!temp) {
                printf("Erro na alocaçao\n");
                return;
            }
            *lista1 = temp;
            (*lista1)[*tam1] = val;
            (*tam1)++;
        }
    }
}

void bubble_sort(int *lista, int tamanho) {
    int trocou;
    do {
        trocou = 0;
    for (int i = 0; i < tamanho - 1; i++) {
            if (lista[i] > lista[i + 1]) {
                int temp = lista[i];
                lista[i] = lista[i + 1];
                lista[i + 1] = temp;
                trocou = 1;
            }
        }
    } while (trocou);
}

int *apagar_lista(int *lista) {
    free(lista);
    return NULL;
}

int main() {
    srand(time(NULL));

    int *lista1 = NULL, *lista2 = NULL;
    int tam1 = 0, tam2 = 0;

    for (int i = 0; i < 25; i++) {
        int val = rand() % 100 + 1;
        inserir_lista1(&lista1, &tam1, val);
    }

    
    for (int i = 0; i < 30; i++) {
        int val = rand() % 100 + 1;
        tam2 = inserir_lista2(&lista2, tam2, val);
    }

    printf("Lista 1:\n");
    exibir(lista1, tam1);
    printf("Lista 2:\n");
    exibir(lista2, tam2);

    exibir_comuns(lista1, tam1, lista2, tam2);

    tam1 = excluir_pares(lista1, tam1);
    printf("Lista 1 após excluir pares:\n");
    exibir(lista1, tam1);

    unir_lista2_na_lista1(&lista1, &tam1, lista2, tam2);
    printf("Lista 1 após unir com lista 2:\n");
    exibir(lista1, tam1);

    bubble_sort(lista1, tam1);
    printf("Lista 1 após ordenação:\n");
    exibir(lista1, tam1);

    lista1 = apagar_lista(lista1);
    lista2 = apagar_lista(lista2);

    printf("Listas apagadas\n");

    return 0;
}
