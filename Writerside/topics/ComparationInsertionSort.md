# Comparação do Insertion Sort

O Insertion Sort, ou Ordenação por Inserção, é um algoritmo de ordenação simples que se destaca em certas situações, mas possui limitações em outras. Vamos compará-lo com outros algoritmos de ordenação comuns:

## Insertion Sort vs. Bubble Sort

*   **Similaridades:** Ambos são algoritmos de ordenação simples com complexidade de tempo de O(n^2) no pior e caso médio.
*   **Diferenças:** O Insertion Sort geralmente supera o Bubble Sort na prática, especialmente para conjuntos de dados quase ordenados. O Insertion Sort move os elementos para suas posições corretas de forma mais eficiente, enquanto o Bubble Sort realiza muitas trocas desnecessárias.

## Insertion Sort vs. Selection Sort

*   **Similaridades:** Ambos são algoritmos de ordenação simples com complexidade de tempo de O(n^2) no pior e caso médio.
*   **Diferenças:** O Insertion Sort é mais rápido que o Selection Sort para conjuntos de dados quase ordenados, pois o Selection Sort sempre realiza o mesmo número de comparações e trocas (n-1 trocas no total). O Insertion Sort é adaptativo, o que significa que seu desempenho melhora com o grau de ordenação inicial do array, enquanto o Selection Sort não é.

## Insertion Sort vs. Merge Sort / Quick Sort

*   **Diferenças:** Algoritmos como Merge Sort e Quick Sort têm complexidade de tempo de O(n log n), o que os torna significativamente mais rápidos para grandes conjuntos de dados. O Insertion Sort é preferível apenas para pequenos conjuntos de dados ou dados quase ordenados, onde sua simplicidade e baixa sobrecarga podem ser vantajosas.