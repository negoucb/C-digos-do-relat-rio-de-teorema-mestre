# Aplicação do Teorema Mestre

Trabalho de Análise de Algoritmos com três implementações recursivas em C, correspondentes aos três casos do Teorema Mestre.

O projeto reúne códigos, medições e gráficos para comparar a análise matemática com o comportamento experimental.

## Integrantes

- [Nome do integrante]
- [Nome do integrante]

**Instituição:** [preencher]  
**Disciplina:** Análise de Algoritmos  
**Professor(a):** [preencher]

## Problemas analisados

| Problema | Descrição | Recorrência | Caso | Complexidade |
|---|---|---|---|---|
| 1 | Pontuação recursiva de vetor com janelas sobrepostas | T(n) = 3T(n/2) + Θ(n) | 1 | Θ(n^(log₂ 3)) |
| 2 | Soma recursiva em três partes com conferência linear | T(n) = 3T(n/3) + Θ(n) | 2 | Θ(n log n) |
| 3 | Verificação recursiva de repetidos com comparação de pares | T(n) = 2T(n/2) + Θ(n²) | 3 | Θ(n²) |

As sobreposições do Problema 1 e a conferência redundante do Problema 2 são intencionais e possuem finalidade didática.

As funções foram desenvolvidas para entradas positivas que sejam potências de 2 nos Problemas 1 e 3 e potências de 3 no Problema 2.

## Organização

- `codigos/problema1.c`: programa completo do Problema 1.
- `codigos/problema2.c`: programa completo do Problema 2.
- `codigos/problema3.c`: programa completo do Problema 3.
- `dados/resultados_unificados.csv`: 90 medições da campanha experimental.
- `dados/resumo_medicoes.csv`: médias e desvios-padrão amostrais.
- `graficos/`: gráficos comparativos dos três problemas.

## Ambiente experimental

- Processador: [preencher]
- Memória RAM: [preencher]
- Sistema operacional: [preencher]
- Versão do GCC: [preencher]
- Otimização: `-O2`
- Medição: função `clock()`, da biblioteca `time.h`
- Tratamento dos dados: [preencher]
- Geração dos gráficos: [preencher]

## Compilação e execução

É necessário ter o GCC instalado e disponível no terminal.

No Windows, abra o terminal na pasta principal do repositório:

```powershell
cd codigos

gcc -O2 problema1.c -o problema1.exe
gcc -O2 problema2.c -o problema2.exe
gcc -O2 problema3.c -o problema3.exe
```

Execute os programas:

```powershell
.\problema1.exe
.\problema2.exe
.\problema3.exe
```

Cada programa cria seu CSV individual no diretório de execução:

- `resultados_problema1.csv`
- `resultados_problema2.csv`
- `resultados_problema3.csv`

Uma nova execução sobrescreve o CSV individual correspondente. Preserve os registros anteriores caso queira manter campanhas diferentes.

Os programas não atualizam automaticamente os arquivos consolidados da pasta `dados/`.

## Procedimento experimental

Foram utilizados seis tamanhos de entrada e cinco medições de lote por tamanho em cada problema, totalizando 90 registros.

| Problema | Tamanhos de entrada | Chamadas por lote |
|---|---|---:|
| 1 | 256, 512, 1024, 2048, 4096 e 8192 | [confirmar no código da campanha] |
| 2 | 729, 2187, 6561, 19683, 59049 e 177147 | 1000 |
| 3 | 512, 1024, 2048, 4096, 8192 e 16384 | 100 |

Cada registro temporal representa o tempo do lote dividido pela quantidade de chamadas. Os tempos estão em segundos.

O resumo apresenta a média e o desvio-padrão amostral dos cinco registros de cada configuração.

## Dados

### resultados_unificados.csv

Contém os registros dos três problemas:

| Coluna | Significado |
|---|---|
| `problema` | Identificação do algoritmo: 1, 2 ou 3 |
| `n` | Tamanho da entrada |
| `repeticao` | Identificação da medição: 1 a 5 |
| `tempo_segundos` | Tempo médio por chamada no lote |

### resumo_medicoes.csv

Apresenta os resultados agrupados:

| Coluna | Significado |
|---|---|
| `problema` | Identificação do algoritmo |
| `n` | Tamanho da entrada |
| `tempo_medio_segundos` | Média das cinco medições |
| `desvio_padrao_segundos` | Desvio-padrão amostral das cinco medições |

A coluna `index`, quando presente, é apenas uma numeração auxiliar das linhas.

## Gráficos

Cada gráfico compara o tempo médio experimental com uma função teórica escalonada:

- Problema 1: `k₁ · n^(log₂ 3)`
- Problema 2: `k₂ · n · log₃ n`
- Problema 3: `k₃ · n²`

As constantes foram escolhidas para que cada curva coincida com a média da maior entrada do respectivo problema.

Essa coincidência decorre do ajuste e não representa uma prova da complexidade.

## Limitações

Os tempos dependem do computador, da resolução do relógio e das otimizações do compilador. Novas execuções podem produzir resultados diferentes.

As medições complementam a análise matemática, mas não substituem as demonstrações. Os códigos, dados e gráficos utilizados no relatório devem corresponder à mesma campanha experimental.
