# Variações do Bubble Sort

## 1. Bubble Sort Otimizado (com Flag)
Adiciona uma flag para detectar quando o array já está ordenado e para antecipadamente.

```cpp
void optimizedBubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool hasSwapped = false;
        
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                hasSwapped = true;
            }
        }
        
        // Se não houve trocas, array está ordenado
        if (!hasSwapped) {
            break;
        }
    }
}
```

## 2. Cocktail Sort (Bubble Sort Bidirecional)
Funciona em ambas as direções alternadamente, melhorando a performance em alguns casos.

```cpp
void cocktailSort(int arr[], int n) {
    bool hasSwapped = true;
    int start = 0;
    int end = n - 1;
    
    while (hasSwapped) {
        hasSwapped = false;
        
        // Esquerda para direita
        for (int i = start; i < end; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                hasSwapped = true;
            }
        }
        end--;
        
        if (!hasSwapped) break;
        
        // Direita para esquerda
        for (int i = end; i > start; i--) {
            if (arr[i] < arr[i - 1]) {
                swap(arr[i], arr[i - 1]);
                hasSwapped = true;
            }
        }
        start++;
    }
}
```

## 3. Bubble Sort Recursivo
Implementação recursiva que "borbulha" o maior elemento e ordena recursivamente o restante.

```cpp
void recursiveBubbleSort(int arr[], int n) {
    // Caso base
    if (n == 1) return;
    
    // Uma passada para colocar o maior elemento no final
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            swap(arr[i], arr[i + 1]);
        }
    }
    
    // Chama recursivamente para os primeiros n-1 elementos
    recursiveBubbleSort(arr, n - 1);
}
```

## 4. Odd-Even Sort (Brick Sort)
Variação que compara elementos em posições ímpares/pares alternadamente.

```cpp
void oddEvenSort(int arr[], int n) {
    bool isSorted = false;
    
    while (!isSorted) {
        isSorted = true;
        
        // Compara elementos em posições ímpares
        for (int i = 1; i <= n - 2; i += 2) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                isSorted = false;
            }
        }
        
        // Compara elementos em posições pares
        for (int i = 0; i <= n - 2; i += 2) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                isSorted = false;
            }
        }
    }
}
```