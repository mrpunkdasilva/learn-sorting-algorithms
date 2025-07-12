# Variações do Insertion Sort

## 1. Insertion Sort Padrão (com Deslocamento)
Esta é a implementação mais comum do Insertion Sort. Ele funciona construindo a matriz final ordenada um item por vez. As iterações através da matriz de entrada pegam um elemento por vez e o inserem em seu lugar correto na parte já ordenada da matriz.

```cpp
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move os elementos de arr[0..i-1], que são maiores que key,
        // para uma posição à frente de sua posição atual
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
```

## 2. Binary Insertion Sort
A principal otimização do Insertion Sort Binário é usar a pesquisa binária para encontrar a posição correta para o elemento `key` na sub-matriz ordenada `arr[0...i-1]`. Isso reduz o número de comparações de O(i) para O(log i) em cada passo. No entanto, o número de deslocamentos (swaps) permanece o mesmo, pois os elementos ainda precisam ser movidos para abrir espaço para o `key`.

```cpp
#include <algorithm> // Para std::upper_bound

void binaryInsertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        
        // Encontra a posição onde 'key' deve ser inserido usando pesquisa binária
        // upper_bound retorna um iterador para o primeiro elemento maior que 'key'
        // (arr + i) é o fim da sub-matriz ordenada
        int j = std::upper_bound(arr, arr + i, key) - arr;

        // Move os elementos para abrir espaço para 'key'
        // std::copy_backward move elementos de [j, i-1] para [j+1, i]
        // Isso é equivalente a um loop for que desloca os elementos
        for (int k = i; k > j; k--) {
            arr[k] = arr[k - 1];
        }
        
        arr[j] = key;
    }
}
```
Apesar da redução nas comparações, o Binary Insertion Sort ainda tem uma complexidade de tempo no pior caso de O(n^2) devido aos deslocamentos de elementos. Ele é mais eficaz quando as comparações são muito mais caras do que os deslocamentos.