# Implementação

Nossa implementação educativa inclui saídas detalhadas para ajudar no aprendizado.

Você pode encontrar uma implementação completa e educativa do Selection Sort em:

<resource src="../../Domus/Domus-1/selectionSort.cpp">

- 📁 `Domus/Domus-1/selectionSort.cpp`

</resource>


## Função Principal - Selection Sort Algorithm

```cpp
void selectionSortAlgorithm(int dataArray[], int arraySize)
{
    cout << "========================================" << endl;
    cout << "STARTING SELECTION SORT ALGORITHM" << endl;
    cout << "========================================" << endl;
    cout << "Initial array: ";
    for(int displayIndex = 0; displayIndex < arraySize; displayIndex++) {
        cout << dataArray[displayIndex] << " ";
    }
    cout << endl << endl;

    int totalNumberOfSwaps = 0;

    for (int currentPosition = 0; currentPosition < arraySize - 1; currentPosition++)
    {
        cout << ">>> ITERATION " << (currentPosition + 1) << " <<<" << endl;
        cout << "Looking for smallest element for position " << currentPosition << endl;
        
        int smallestElementIndex = findSmallestElementIndex(dataArray, currentPosition, arraySize - 1);

        if (currentPosition != smallestElementIndex) {
            cout << "Smallest element is at position " << smallestElementIndex << ", need to swap with position " << currentPosition << endl;
            swapElements(dataArray, currentPosition, smallestElementIndex);
            totalNumberOfSwaps++;
        } else {
            cout << "Smallest element is already in correct position (" << currentPosition << "), no swap needed" << endl;
        }

        cout << "Array state after iteration " << (currentPosition + 1) << ": ";
        for(int displayIndex = 0; displayIndex < arraySize; displayIndex++) {
            if (displayIndex <= currentPosition) {
                cout << "[" << dataArray[displayIndex] << "] "; // Already sorted elements
            } else {
                cout << dataArray[displayIndex] << " ";        // Not yet sorted elements
            }
        }
        cout << endl;
        cout << "Elements sorted: " << (currentPosition + 1) << "/" << arraySize << endl;
        cout << "--------------------------------" << endl;
    }

    cout << "========================================" << endl;
    cout << "SELECTION SORT ALGORITHM COMPLETED!" << endl;
    cout << "Total number of swaps performed: " << totalNumberOfSwaps << endl;
    cout << "========================================" << endl;
}
```

## Função para Encontrar o Menor Elemento

```cpp
int findSmallestElementIndex(int dataArray[], int startIndex, int endIndex)
{
    cout << "--- Searching for smallest element in range [" << startIndex << ", " << endIndex << "] ---" << endl;
    int currentIndex = startIndex;
    int smallestIndex = currentIndex;
    int numberOfComparisons = 0;

    cout << "Initial element for comparison: dataArray[" << smallestIndex << "] = " << dataArray[smallestIndex] << endl;

    while (currentIndex <= endIndex)
    {
        cout << "Comparing dataArray[" << currentIndex << "] = " << dataArray[currentIndex] << " with current smallest dataArray[" << smallestIndex << "] = " << dataArray[smallestIndex];
        numberOfComparisons++;
        
        if (dataArray[currentIndex] < dataArray[smallestIndex])
        {
            cout << " -> " << dataArray[currentIndex] << " is smaller! New smallest element found at position " << currentIndex << endl;
            smallestIndex = currentIndex;
        }
        else
        {
            cout << " -> " << dataArray[currentIndex] << " >= " << dataArray[smallestIndex] << ", keeping current smallest" << endl;
        }

        currentIndex++;
    }

    cout << "Smallest element found: " << dataArray[smallestIndex] << " at position " << smallestIndex << " (after " << numberOfComparisons << " comparisons)" << endl;
    return smallestIndex;
}
```

## Função para Trocar Elementos

```cpp
void swapElements(int dataArray[], int firstPosition, int secondPosition)
{
    cout << "  -> Swapping elements: " << dataArray[firstPosition] << " (position " << firstPosition << ") <-> " << dataArray[secondPosition] << " (position " << secondPosition << ")" << endl;
    int temporaryValue = dataArray[firstPosition];
    dataArray[firstPosition] = dataArray[secondPosition];
    dataArray[secondPosition] = temporaryValue;
    cout << "  -> After swap: position " << firstPosition << " = " << dataArray[firstPosition] << ", position " << secondPosition << " = " << dataArray[secondPosition] << endl;
}
```


## Características do Algoritmo

### Complexidade de Tempo
- **Melhor caso**: O(n²) - Mesmo que o array já esteja ordenado
- **Caso médio**: O(n²) - Comportamento típico
- **Pior caso**: O(n²) - Array ordenado inversamente

### Complexidade de Espaço
- **O(1)** - Algoritmo in-place, usa apenas memória constante adicional

### Propriedades Importantes

| Propriedade | Valor |
|-------------|-------|
| **Estável** | ❌ Não |
| **In-place** | ✅ Sim |
| **Adaptivo** | ❌ Não |
| **Comparações** | O(n²) |
| **Trocas** | O(n) |

