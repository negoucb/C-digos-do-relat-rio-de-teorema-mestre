
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long somaRecursiva(const int vetor[], int inicio, int n) {
    if (n == 1) {
        return vetor[inicio];
    }

    int parte = n / 3;

    long long soma1 = somaRecursiva(vetor, inicio, parte);
    long long soma2 = somaRecursiva(vetor, inicio + parte, parte);
    long long soma3 = somaRecursiva(vetor, inicio + 2 * parte, parte);

    long long conferencia = 0;

    for (int i = inicio; i < inicio + n; i++) {
        conferencia += vetor[i];
    }

    if (conferencia != soma1 + soma2 + soma3) {
        printf("Erro na soma!\n");
        exit(1);
    }

    return soma1 + soma2 + soma3;
}

int main(void) {
const int tamanhos[] = {729, 2187, 6561, 19683, 59049, 177147};    const int quantidade = sizeof(tamanhos) / sizeof(tamanhos[0]);
    const int repeticoes = 5;
const int chamadas = 1000;
    volatile long long resultado = 0;

    FILE *arquivo = fopen("resultados_problema2.csv", "w");

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

        for (int i = 0; i < n; i++) {
            vetor[i] = 1;
        }

        for (int r = 1; r <= repeticoes; r++) {
            clock_t inicio = clock();

            for (int j = 0; j < chamadas; j++) {
                resultado = somaRecursiva(vetor, 0, n);
            }

            clock_t fim = clock();

            double tempo = (double)(fim - inicio)
                           / CLOCKS_PER_SEC / chamadas;

            fprintf(arquivo, "2,%d,%d,%.9f\n", n, r, tempo);

            printf("n=%d | repeticao=%d | tempo=%.9f s\n",
                   n, r, tempo);
        }

        free(vetor);
    }

    fclose(arquivo);

    printf("Resultado final: %lld\n", resultado);
    return 0;
}
