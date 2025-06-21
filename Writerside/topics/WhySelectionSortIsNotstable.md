# Por que o Selection Sort NÃO é Estável?

## O que significa "Estabilidade" em algoritmos de ordenação?

Um algoritmo de ordenação é **estável** quando mantém a **ordem relativa** dos elementos que possuem valores iguais. Ou seja, se dois elementos têm o mesmo valor, aquele que aparece primeiro no array original deve aparecer primeiro no array ordenado.

## Exemplo Prático de Instabilidade

Considere um array de cartas onde cada carta tem um valor e um naipe:

**Array inicial:** `[5♠, 3♦, 5♥, 2♣, 3♠]`

Vamos ordenar por **valor numérico** apenas, ignorando o naipe:

### ✅ Ordenação Estável (esperada):
`[2♣, 3♦, 3♠, 5♠, 5♥]`
- Note que `3♦` vem antes de `3♠` (mantém ordem original)
- E `5♠` vem antes de `5♥` (mantém ordem original)

### ❌ Selection Sort (instável):
`[2♣, 3♠, 3♦, 5♥, 5♠]`
- `3♠` agora vem antes de `3♦` (ordem alterada!)
- `5♥` agora vem antes de `5♠` (ordem alterada!)

## Por que isso acontece no Selection Sort?

O Selection Sort **troca elementos distantes** entre si, o que pode "pular" sobre elementos iguais e alterar sua ordem relativa.

### Demonstração com números simples:

**Array inicial:** `[4, 2, 4, 1, 3]`
- Para distinguir, vamos chamar: `[4a, 2, 4b, 1, 3]`

**Execução do Selection Sort:**

**Iteração 1:**
- Procura menor elemento: `1` (posição 3)
- **Troca:** `4a` ↔ `1`
- Resultado: `[1, 2, 4b, 4a, 3]`

<warning>

**Observe:** `4b` agora vem antes de `4a`!

</warning>

**Iteração 2:**
- Procura menor na parte não ordenada `[2, 4b, 4a, 3]`: `2` já está correto
- Sem troca
- Resultado: `[1, 2, 4b, 4a, 3]`

**Iteração 3:**
- Procura menor na parte não ordenada `[4b, 4a, 3]`: `3` (posição 4)
- **Troca:** `4b` ↔ `3`
- Resultado: `[1, 2, 3, 4a, 4b]`

**Array final:** `[1, 2, 3, 4a, 4b]`

## O Problema da "Troca Distante"

```
Array: [4a, 2, 4b, 1, 3]
        ↑           ↑
        |___________|
     Troca distante que "pula"
     sobre 4b, alterando a ordem!
```

Quando o Selection Sort encontra o menor elemento em uma posição distante, ele o troca diretamente com a posição atual, **pulando sobre todos os elementos intermediários**, incluindo aqueles que têm o mesmo valor.

## Impacto Prático da Instabilidade

A instabilidade pode ser problemática em situações reais:

1. **Ordenação de registros de funcionários por salário:**
   - Se dois funcionários têm o mesmo salário, você pode querer manter a ordem original (ex: por data de contratação)

2. **Classificação de produtos por preço:**
   - Produtos com mesmo preço podem ter diferentes prioridades de exibição

3. **Ordenação de notas de alunos:**
   - Alunos com a mesma nota podem estar em ordem alfabética inicialmente

## Como tornar o Selection Sort estável?

É possível modificar o Selection Sort para ser estável, mas isso aumenta a complexidade:

```cpp
// Versão estável (menos eficiente)
void stableSelectionSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int minIdx = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        
        // Em vez de trocar diretamente, 
        // desloca todos os elementos entre i e minIdx
        int key = arr[minIdx];
        while (minIdx > i) {
            arr[minIdx] = arr[minIdx-1];
            minIdx--;
        }
        arr[i] = key;
    }
}
```

<warning>

**Mas isso aumenta a complexidade de trocas de O(n) para O(n²)!**

</warning>

## Visualização da Instabilidade - "Rotatividade"

O conceito de "rotatividade" que você mencionou refere-se à forma como os elementos "giram" ou alteram suas posições relativas durante as trocas distantes:

```
Estado inicial: [4a, 2, 4b, 1, 3]
                 ▲              ▲
                 └──────────────┘ Troca distante na iteração 1

Após troca:     [1, 2, 4b, 4a, 3]
                        ▲   ▲
                     4b "rotacionou" para frente de 4a

Estado inicial: [A, B, C, D] (onde A = D em valor)
Após Selection: [D, B, C, A] (A e D trocaram posições!)
                 ▲        ▲
                 └────────┘ "Rotatividade" - ordem relativa invertida
```

## Comparação Visual: Estável vs Instável

### Algoritmo Estável (ex: Insertion Sort):
```
[3a, 1, 3b, 2] → [1, 2, 3a, 3b] ✅ Ordem mantida
 ▲      ▲                ▲   ▲
 └──────┘                └───┘ 3a ainda vem antes de 3b
```

### Selection Sort (Instável): {id="selection-sort-inst-vel_1"}
```
[3a, 1, 3b, 2] → [1, 2, 3b, 3a] ❌ Ordem alterada!
 ▲      ▲               ▲   ▲
 └──────┘               └───┘ 3b agora vem antes de 3a
```

## Resumo: Por que Selection Sort é Instável

- **Trocas distantes**: Elementos são trocados através de grandes distâncias
- **Pula elementos**: Ignora elementos iguais no meio do caminho
- **Foco apenas no valor**: Não considera a posição original dos elementos iguais
- **Prioriza eficiência**: A versão estável seria muito menos eficiente
- **Rotatividade**: Elementos iguais podem "rotacionar" suas posições relativas
