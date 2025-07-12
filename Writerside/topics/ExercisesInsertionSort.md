# Exercícios Práticos

## Exercício 1: Implementação Básica
Implemente o Insertion Sort para ordenar um array de números inteiros em ordem crescente.

### 💡 Solução do Exercício 1 {collapsible="true"}

```cpp
#include <iostream>

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

        std::cout << "Array após a iteração " << i << ": ";
        for (int k = 0; k < n; k++) {
            std::cout << arr[k] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Array original: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    insertionSort(arr, n);

    std::cout << "\nArray ordenado: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

## Exercício 2: Insertion Sort com Contagem de Operações
Modifique o algoritmo Insertion Sort para contar e exibir o número total de comparações e deslocamentos (shifts) realizados.

### 💡 Solução do Exercício 2 {collapsible="true"}

```cpp
#include <iostream>

struct InsertionSortStats {
    int comparisons;
    int shifts;
};

void insertionSortWithStats(int arr[], int n, InsertionSortStats& stats) {
    stats.comparisons = 0;
    stats.shifts = 0;

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move os elementos de arr[0..i-1], que são maiores que key,
        // para uma posição à frente de sua posição atual
        while (j >= 0) {
            stats.comparisons++;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                stats.shifts++;
                j = j - 1;
            } else {
                break;
            }
        }
        arr[j + 1] = key;

        std::cout << "Array após a iteração " << i << ": ";
        for (int k = 0; k < n; k++) {
            std::cout << arr[k] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    InsertionSortStats stats;

    std::cout << "Array original: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    insertionSortWithStats(arr, n, stats);

    std::cout << "\nArray ordenado: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "\nEstatísticas:\n";
    std::cout << "Comparações: " << stats.comparisons << std::endl;
    std::cout << "Deslocamentos: " << stats.shifts << std::endl;

    return 0;
}
```

## Exercício 3: Insertion Sort para Strings
Implemente o Insertion Sort para ordenar um array de strings em ordem alfabética.

### 💡 Solução do Exercício 3 {collapsible="true"}

```cpp
#include <iostream>
#include <string>

void insertionSortStrings(std::string arr[], int n) {
    for (int i = 1; i < n; i++) {
        std::string key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j].compare(key) > 0) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;

        std::cout << "Array após a iteração " << i << ": ";
        for (int k = 0; k < n; k++) {
            std::cout << arr[k] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::string arr[] = {"banana", "apple", "orange", "grape", "kiwi"};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Array original: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    insertionSortStrings(arr, n);

    std::cout << "\nArray ordenado: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
```
