
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int verificarRepetidos(const int vetor[], int inicio, int n) {
    if (n == 1) {
        return 0;
    }

    int metade = n / 2;

    int esquerda = verificarRepetidos(vetor, inicio, metade);
    int direita = verificarRepetidos(vetor, inicio + metade, metade);

    int repetido = 0;

    for (int i = inicio; i < inicio + n; i++) {
        for (int j = i + 1; j < inicio + n; j++) {
            if (vetor[i] == vetor[j]) {
                repetido = 1;
            }
        }
    }

    return esquerda || direita || repetido;
}

int main(void) {
const int tamanhos[] = {512, 1024, 2048, 4096, 8192, 16384};    const int quantidade = sizeof(tamanhos) / sizeof(tamanhos[0]);
    const int repeticoes = 5;
const int chamadas = 100;
    volatile int resultado = 0;

    FILE *arquivo = fopen("resultados_problema3.csv", "w");

    if (arquivo == NULL) {
        printf("Erro ao criar CSV.\n");
        return 1;
    }

    fprintf(arquivo, "problema,n,repeticao,tempo_segundos\n");

    for (int t = 0; t < quantidade; t++) {
        int n = tamanhos[t];
        int *vetor = malloc((size_t)n * sizeof(int));

        if (vetor == NULL) {
            printf("Erro de memoria.\n");
            fclose(arquivo);
            return 1;
        }

        // Elementos distintos: nao existem repeticoes.
        for (int i = 0; i < n; i++) {
            vetor[i] = i;
        }

        for (int r = 1; r <= repeticoes; r++) {
            clock_t inicio = clock();

            for (int j = 0; j < chamadas; j++) {
                resultado = verificarRepetidos(vetor, 0, n);
            }

            clock_t fim = clock();

            double tempo = (double)(fim - inicio)
                           / CLOCKS_PER_SEC / chamadas;

            fprintf(arquivo, "3,%d,%d,%.9f\n", n, r, tempo);

            printf("n=%d | repeticao=%d | tempo=%.9f s\n",
                   n, r, tempo);
        }

        free(vetor);
    }

    fclose(arquivo);

    printf("Existem repetidos? %s\n", resultado ? "Sim" : "Nao");

    return 0;
}
