# Implementação

Nossa implementação educativa inclui saídas detalhadas para ajudar no aprendizado.

Você pode encontrar uma implementação completa e educativa do Bubble Sort em:

<resource src="../../Domus/Domus-1/bubbleSort.cpp">

- 📁 `Domus/Domus-1/bubbleSort.cpp`

</resource>


## Função Principal - Bubble Sort Algorithm

```cpp
void bubbleSortAlgorithm(int dataArray[], int arraySize)
{
    cout << "========================================" << endl;
    cout << "STARTING BUBBLE SORT ALGORITHM" << endl;
    cout << "========================================" << endl;
    cout << "Initial array: ";
    for(int displayIndex = 0; displayIndex < arraySize; displayIndex++) {
        cout << dataArray[displayIndex] << " ";
    }
    cout << endl << endl;

    int totalNumberOfSwaps = 0;
    int totalNumberOfComparisons = 0;
    bool hasSwapped = true;
    int iterationCount = 0;

    while (hasSwapped && iterationCount < arraySize - 1)
    {
        iterationCount++;
        hasSwapped = false;
        
        cout << ">>> ITERATION " << iterationCount << " <<<" << endl;
        cout << "Comparing adjacent elements..." << endl;
        
        for (int currentIndex = 0; currentIndex < arraySize - iterationCount; currentIndex++)
        {
            int nextIndex = currentIndex + 1;
            totalNumberOfComparisons++;
            
            cout << "Comparing dataArray[" << currentIndex << "] = " << dataArray[currentIndex] 
                 << " with dataArray[" << nextIndex << "] = " << dataArray[nextIndex];
            
            if (dataArray[currentIndex] > dataArray[nextIndex]) {
                cout << " -> " << dataArray[currentIndex] << " > " << dataArray[nextIndex] 
                     << ", need to swap!" << endl;
                swapElements(dataArray, currentIndex, nextIndex);
                hasSwapped = true;
                totalNumberOfSwaps++;
            } else {
                cout << " -> " << dataArray[currentIndex] << " <= " << dataArray[nextIndex] 
                     << ", no swap needed" << endl;
            }
        }

        cout << "Array state after iteration " << iterationCount << ": ";
        for(int displayIndex = 0; displayIndex < arraySize; displayIndex++) {
            if (displayIndex >= arraySize - iterationCount) {
                cout << "[" << dataArray[displayIndex] << "] "; // Already sorted elements
            } else {
                cout << dataArray[displayIndex] << " ";        // Not yet sorted elements
            }
        }
        cout << endl;
        cout << "Elements in final position: " << iterationCount << "/" << arraySize << endl;
        
        if (!hasSwapped) {
            cout << "No swaps performed in this iteration - array is sorted!" << endl;
        }
        cout << "--------------------------------" << endl;
    }

    cout << "========================================" << endl;
    cout << "BUBBLE SORT ALGORITHM COMPLETED!" << endl;
    cout << "Total number of iterations: " << iterationCount << endl;
    cout << "Total number of comparisons: " << totalNumberOfComparisons << endl;
    cout << "Total number of swaps performed: " << totalNumberOfSwaps << endl;
    cout << "========================================" << endl;
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

## Versão Otimizada do Bubble Sort

```cpp
void optimizedBubbleSortAlgorithm(int dataArray[], int arraySize)
{
    cout << "========================================" << endl;
    cout << "STARTING OPTIMIZED BUBBLE SORT ALGORITHM" << endl;
    cout << "========================================" << endl;
    
    int totalNumberOfSwaps = 0;
    int totalNumberOfComparisons = 0;
    
    for (int iteration = 0; iteration < arraySize - 1; iteration++)
    {
        bool hasSwapped = false;
        
        cout << ">>> ITERATION " << (iteration + 1) << " <<<" << endl;
        
        for (int currentIndex = 0; currentIndex < arraySize - iteration - 1; currentIndex++)
        {
            totalNumberOfComparisons++;
            
            if (dataArray[currentIndex] > dataArray[currentIndex + 1]) {
                swapElements(dataArray, currentIndex, currentIndex + 1);
                hasSwapped = true;
                totalNumberOfSwaps++;
            }
        }
        
        // Early termination if no swaps occurred
        if (!hasSwapped) {
            cout << "No swaps in this iteration - array is already sorted!" << endl;
            break;
        }
        
        cout << "Array after iteration " << (iteration + 1) << ": ";
        for(int displayIndex = 0; displayIndex < arraySize; displayIndex++) {
            cout << dataArray[displayIndex] << " ";
        }
        cout << endl << "--------------------------------" << endl;
    }
    
    cout << "Total comparisons: " << totalNumberOfComparisons << endl;
    cout << "Total swaps: " << totalNumberOfSwaps << endl;
}
```

## Características do Algoritmo

### Complexidade de Tempo
- **Melhor caso**: O(n) - Array já ordenado (com otimização)
- **Caso médio**: O(n²) - Comportamento típico
- **Pior caso**: O(n²) - Array ordenado inversamente

### Complexidade de Espaço
- **O(1)** - Algoritmo in-place, usa apenas memória constante adicional

### Propriedades Importantes

| Propriedade | Valor |
|-------------|-------|
| **Estável** | ✅ Sim |
| **In-place** | ✅ Sim |
| **Adaptivo** | ✅ Sim (com otimização) |
| **Comparações** | O(n²) |
| **Trocas** | O(n²) |