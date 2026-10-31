# Aplicação do Teorema Mestre

Trabalho de Análise de Algoritmos com três programas recursivos em C, correspondentes aos três casos do Teorema Mestre.

O repositório reúne os códigos e os dados utilizados na análise experimental. Os gráficos e as demonstrações matemáticas são apresentados no relatório.


## Autor

Gabriel da Silva Campos  
Universidade Católica de Brasília  
Curso: Ciência da Computação  
Disciplina: Análise de Algoritmos

## Problemas analisados

| Problema | Descrição | Recorrência | Caso | Complexidade |
|---|---|---|---|---|
| 1 | Pontuação recursiva: processa duas vezes a primeira metade e uma vez a segunda | T(n) = 3T(n/2) + Θ(n) | 1 | Θ(n^(log₂ 3)) |
| 2 | Soma em três partes com conferência linear | T(n) = 3T(n/3) + Θ(n) | 2 | Θ(n log n) |
| 3 | Verificação recursiva de repetidos com comparação de todos os pares | T(n) = 2T(n/2) + Θ(n²) | 3 | Θ(n²) |

A repetição da primeira metade no Problema 1 e a conferência do Problema 2 são intencionais e possuem finalidade didática.

As entradas devem ser positivas e potências de 2 nos Problemas 1 e 3, ou potências de 3 no Problema 2.

## Arquivos

Todos os arquivos estão na raiz do repositório.

| Arquivo | Conteúdo |
|---|---|
| `Problema1.c` | Programa completo do Problema 1 |
| `Problema2.c` | Programa completo do Problema 2 |
| `Problema3.c` | Programa completo do Problema 3 |
| `resultados_problema 1.csv` | Medições arquivadas do Problema 1 |
| `resultados_problema2.csv` | Medições arquivadas do Problema 2 |
| `resultados_problema3.csv` | Medições arquivadas do Problema 3 |
| `resultados_unificados.csv` | 90 registros dos três problemas |
| `resumo_medicoes.csv` | Médias e desvios-padrão amostrais |

O nome `resultados_problema 1.csv` contém um espaço. O programa do Problema 1 gera novas medições em outro arquivo, chamado `resultados_novos.csv`.

## Compilação

É necessário ter o GCC instalado e disponível no terminal.

Na pasta principal do repositório, execute:

```powershell
gcc -O2 Problema1.c -o problema1.exe
gcc -O2 Problema2.c -o problema2.exe
gcc -O2 Problema3.c -o problema3.exe
```

## Execução no Windows

```powershell
.\problema1.exe
.\problema2.exe
.\problema3.exe
```

Cada programa gera um CSV no diretório de execução:

| Programa | Arquivo gerado |
|---|---|
| `Problema1.c` | `resultados_problema1.csv` |
| `Problema2.c` | `resultados_problema2.csv` |
| `Problema3.c` | `resultados_problema3.csv` |

Uma nova execução sobrescreve o arquivo gerado correspondente. Preserve os registros anteriores antes de executar novamente.

Os programas não atualizam automaticamente o CSV unificado, o resumo estatístico ou os gráficos.

## Configuração dos experimentos

Os programas utilizam `clock()`, da biblioteca `time.h`, e compilação com `-O2`.

São cinco medições de lote para cada tamanho:

| Problema | Tamanhos de entrada | Chamadas por lote |
|---|---|---:|
| 1 | 256, 512, 1024, 2048, 4096 e 8192 | 100 |
| 2 | 729, 2187, 6561, 19683, 59049 e 177147 | 1000 |
| 3 | 512, 1024, 2048, 4096, 8192 e 16384 | 100 |

Nos Problemas 1 e 2, os vetores são preenchidos com valores iguais a 1. No Problema 3, utiliza-se `vetor[i] = i`, produzindo elementos distintos.

A preparação das entradas e a gravação dos registros ficam fora do intervalo cronometrado.

Cada registro representa o tempo do lote dividido pela quantidade de chamadas, em segundos.

## Resultados esperados

Na última entrada de cada programa:

- Problema 1: pontuação `4766585`.
- Problema 2: soma `177147`.
- Problema 3: `Existem repetidos? Nao`.

## Formato dos dados

### resultados_unificados.csv

- `problema`: identificação do algoritmo.
- `n`: tamanho da entrada.
- `repeticao`: medição de 1 a 5.
- `tempo_segundos`: tempo médio por chamada no lote.

O arquivo contém 30 registros por problema, totalizando 90 medições.

### resumo_medicoes.csv

- `problema`: identificação do algoritmo.
- `n`: tamanho da entrada.
- `tempo_medio_segundos`: média das cinco medições.
- `desvio_padrao_segundos`: desvio-padrão amostral das cinco medições.

A coluna `index`, quando presente, é apenas uma numeração auxiliar.

## Gráficos e interpretação

Os gráficos do relatório comparam os tempos médios com funções teóricas escalonadas:

- Problema 1: k₁ · n^(log₂ 3).
- Problema 2: k₂ · n · log₃ n.
- Problema 3: k₃ · n².

As constantes foram escolhidas para coincidir com a média da maior entrada de cada problema. Essa coincidência decorre do ajuste e não constitui prova da complexidade.

## Notas de organização do relatório

Os trechos identificados como “Orientação”, abaixo de alguns blocos de código no PDF, são notas de montagem que permaneceram no documento. Eles registram como foi planejada a organização do relatório: quais funções selecionar, em qual seção inseri-las e onde disponibilizar os programas completos.

Essas notas não fazem parte dos algoritmos nem das demonstrações matemáticas e não exigem nenhuma ação do leitor.

## Limitações

Os tempos dependem do computador, da resolução do relógio e das otimizações do compilador. Novas execuções podem produzir valores diferentes dos registros publicados.

A configuração completa do computador e a versão do compilador da campanha original não estão documentadas neste README.

As medições complementam as demonstrações matemáticas, sem substituí-las.
