# Insertion Sort

## O que é Insertion Sort?

O **Insertion Sort** (Ordenação por Inserção) é um algoritmo de ordenação simples que constrói a matriz final ordenada um item por vez. É muito menos eficiente em grandes listas do que algoritmos mais avançados, como o Quick Sort, Heap Sort ou Merge Sort. No entanto, ele tem algumas vantagens:

*   É simples de implementar.
*   É eficiente para conjuntos de dados pequenos ou quase ordenados.
*   É mais eficiente na prática do que outros algoritmos quadráticos (como Bubble Sort e Selection Sort).
*   É um algoritmo de ordenação estável.

## Como funciona?

O algoritmo funciona da seguinte forma:

1.  **Divide** a lista em duas partes: uma parte ordenada e uma parte não ordenada. Inicialmente, a parte ordenada contém apenas o primeiro elemento da lista.
2.  **Pega** o primeiro elemento da parte não ordenada.
3.  **Compara** este elemento com os elementos na parte ordenada, movendo os elementos maiores uma posição para a direita para abrir espaço.
4.  **Insere** o elemento na posição correta na parte ordenada.
5.  **Repete** os passos 2 a 4 até que todos os elementos da parte não ordenada tenham sido inseridos na parte ordenada.

## Diagramação

![insertionSort_annotated.png](insertionSort_annotated.png)

## Exemplo Visual

Considerando o array: `[12, 11, 13, 5, 6]`

**Iteração 1:**
- O primeiro elemento `12` é considerado ordenado. Array: `[12], 11, 13, 5, 6`
- **Resultado:** O primeiro elemento é inicializado como a parte ordenada.

**Iteração 2:**
- Pega `11`. Compara `11` com `12`: `11 < 12` → Move `12` para a direita e insere `11` antes de `12`. Array: `[11, 12], 13, 5, 6`
- **Resultado:** A parte ordenada do array é `[11, 12]`.

**Iteração 3:**
- Pega `13`. Compara `13` com `12`: `13 > 12` → Sem troca: `[11, 12, 13], 5, 6`
- **Resultado:** `13` já está na posição correta.

**Iteração 4:**
- Pega `5`. Compara `5` com `13`, `12`, `11`: Move `13`, `12`, `11` para a direita e insere `5` no início.
- **Resultado:** O array é `[5, 11, 12, 13], 6`

**Iteração 5:**
- Pega `6`. Compara `6` com `13`, `12`, `11`, `5`: Move `13`, `12`, `11` para a direita e insere `6` após `5`.
- **Resultado:** O array é `[5, 6, 11, 12, 13]`

**Resultado Final:** `[5, 6, 11, 12, 13]`