
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long pontuacao(const int vetor[], int inicio, int n) {
    if (n == 1) {
        return vetor[inicio];
    }

    int metade = n / 2;
    long long soma = 0;

    for (int i = inicio; i < inicio + n; i++) {
        soma += vetor[i];
    }

    long long esquerda1 = pontuacao(vetor, inicio, metade);
    long long direita = pontuacao(vetor, inicio + metade, metade);
    long long esquerda2 = pontuacao(vetor, inicio, metade);

    return soma + esquerda1 + direita + esquerda2;
}

int main(void) {
    const int tamanhos[] = {256, 512, 1024, 2048, 4096, 8192};
    const int quantidade = sizeof(tamanhos) / sizeof(tamanhos[0]);
    const int repeticoes = 5;
    const int chamadas = 100;

    volatile long long resultado = 0;

    FILE *arquivo = fopen("resultados_novos.csv", "w");

    if (arquivo == NULL) {
        printf("Erro ao criar CSV.\n");
        return 1;
    }

    fprintf(arquivo, "problema,n,repeticao,tempo_segundos\n");

    for (int t = 0; t < quantidade; t++) {
        int n = tamanhos[t];
        int *vetor = malloc((size_t)n * sizeof(int));

        if (vetor == NULL) {
            fclose(arquivo);
            return 1;
        }

        for (int i = 0; i < n; i++) {
            vetor[i] = 1;
        }

        for (int r = 1; r <= repeticoes; r++) {
            clock_t inicio = clock();

            for (int j = 0; j < chamadas; j++) {
                resultado = pontuacao(vetor, 0, n);
            }

            clock_t fim = clock();

            double tempo = (double)(fim - inicio)
                           / CLOCKS_PER_SEC / chamadas;

            fprintf(arquivo, "1,%d,%d,%.9f\n", n, r, tempo);

            printf("n=%d | repeticao=%d | tempo=%.9f s\n",
                   n, r, tempo);
        }

        free(vetor);
    }

    fclose(arquivo);

    printf("Resultado final: %lld\n", resultado);
    return 0;
}
