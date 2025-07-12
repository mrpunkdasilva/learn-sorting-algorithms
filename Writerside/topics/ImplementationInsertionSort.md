# Implementação 

O Insertion Sort (Ordenação por Inserção) é um algoritmo de ordenação simples que constrói a matriz final ordenada um item por vez. É muito menos eficiente em grandes listas do que algoritmos mais avançados, como Quick Sort, Heap Sort ou Merge Sort.

<resource src="../../Domus/Domus-1/insertionSort.cpp">

- 📁 `Domus/Domus-1/insertionSort.cpp`

</resource>


## Como funciona:

1.  Comece com o segundo elemento do array (o primeiro elemento é considerado já ordenado).
2.  Compare o elemento atual com os elementos à sua esquerda.
3.  Se o elemento atual for menor que o elemento à sua esquerda, desloque o elemento à esquerda uma posição para a direita.
4.  Continue deslocando os elementos para a direita até encontrar uma posição onde o elemento atual seja maior ou igual ao elemento à sua esquerda, ou até o início do array.
5.  Insira o elemento atual na posição encontrada.
6.  Repita os passos 2 a 5 para todos os elementos restantes do array.

## Exemplo em Pseudocódigo:

```pseudocode
function insertionSort(array):
  n = length(array)
  for i from 1 to n-1:
    key = array[i]
    j = i - 1
    while j >= 0 and array[j] > key:
      array[j + 1] = array[j]
      j = j - 1
    array[j + 1] = key
```

## Exemplo em C++:

```cpp
#include <iostream>
#include <vector>

void insertionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1], that are
        // greater than key, to one position ahead
        // of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    std::vector<int> arr = {12, 11, 13, 5, 6};
    insertionSort(arr);

    std::cout << "Array ordenado: ";
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}
```