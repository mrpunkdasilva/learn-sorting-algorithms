# Exercícios Práticos

## Exercício 1: Implementação Básica
Implemente o Selection Sort para ordenar um array de strings por ordem alfabética.

### 💡 Solução do Exercício 1 {collapsible="true"}

<resource src="../../Domus/Domus-1/exercises-selection/selectionSortString.cpp">
Código completo
</resource>

```cpp
#include <iostream>
#include <string>
using namespace std;

// Função para encontrar o índice da menor string
int findSmallestStringIndex(string arr[], int start, int end) {
    int smallestIndex = start;
    
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] < arr[smallestIndex]) {
            smallestIndex = i;
        }
    }
    
    return smallestIndex;
}

// Função para trocar duas strings
void swapStrings(string arr[], int pos1, int pos2) {
    string temp = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = temp;
}

// Selection Sort para strings
void selectionSortStrings(string arr[], int size) {
    cout << "Ordenando strings por ordem alfabética:" << endl;
    
    for (int i = 0; i < size - 1; i++) {
        cout << "\nIteração " << (i + 1) << ":" << endl;
        
        int smallestIndex = findSmallestStringIndex(arr, i, size - 1);
        
        if (i != smallestIndex) {
            cout << "Trocando \"" << arr[i] << "\" com \"" << arr[smallestIndex] << "\"" << endl;
            swapStrings(arr, i, smallestIndex);
        } else {
            cout << "\"" << arr[i] << "\" já está na posição correta" << endl;
        }
        
        // Mostrar estado atual
        cout << "Array atual: ";
        for (int j = 0; j < size; j++) {
            if (j <= i) {
                cout << "[" << arr[j] << "] ";
            } else {
                cout << arr[j] << " ";
            }
        }
        cout << endl;
    }
}

// Exemplo de uso
int main() {
    string frutas[] = {"banana", "maçã", "laranja", "uva", "abacaxi"};
    int tamanho = 5;
    
    cout << "Array inicial: ";
    for (int i = 0; i < tamanho; i++) {
        cout << frutas[i] << " ";
    }
    cout << endl;
    
    selectionSortStrings(frutas, tamanho);
    
    cout << "\nArray final ordenado: ";
    for (int i = 0; i < tamanho; i++) {
        cout << frutas[i] << " ";
    }
    cout << endl;
    
    return 0;
}
```

**Pontos importantes:**
- Usamos o operador `<` para comparação lexicográfica de strings
- A lógica é a mesma do Selection Sort para números
- Strings são ordenadas alfabeticamente (A-Z)

## Exercício 2: Contagem de Operações
Modifique o algoritmo para contar o número de comparações e trocas realizadas.

### 💡 Solução do Exercício 2 {collapsible="true"}

<resource src="../../Domus/Domus-1/exercises-selection/selectionWithStats.cpp">Código completo</resource>

```cpp
#include <iostream>
using namespace std;

// Estrutura para armazenar estatísticas
struct SortStatistics {
    int comparisons;
    int swaps;
    
    SortStatistics() : comparisons(0), swaps(0) {}
};

// Função para encontrar o menor elemento com contagem de comparações
int findSmallestWithStats(int arr[], int start, int end, SortStatistics& stats) {
    int smallestIndex = start;
    
    for (int i = start + 1; i <= end; i++) {
        stats.comparisons++; // Incrementa contador de comparações
        
        if (arr[i] < arr[smallestIndex]) {
            smallestIndex = i;
        }
    }
    
    return smallestIndex;
}

// Função para trocar elementos com contagem
void swapWithStats(int arr[], int pos1, int pos2, SortStatistics& stats) {
    if (pos1 != pos2) {
        stats.swaps++; // Incrementa contador de trocas
        
        int temp = arr[pos1];
        arr[pos1] = arr[pos2];
        arr[pos2] = temp;
        
        cout << "  Troca #" << stats.swaps << ": " << arr[pos1] 
             << " <-> " << arr[pos2] << endl;
    }
}

// Selection Sort com estatísticas
void selectionSortWithStats(int arr[], int size) {
    SortStatistics stats;
    
    cout << "=== SELECTION SORT COM ESTATÍSTICAS ===" << endl;
    cout << "Array inicial: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl << endl;
    
    for (int i = 0; i < size - 1; i++) {
        cout << "Iteração " << (i + 1) << ":" << endl;
        
        int smallestIndex = findSmallestWithStats(arr, i, size - 1, stats);
        
        cout << "  Menor elemento: " << arr[smallestIndex] 
             << " (posição " << smallestIndex << ")" << endl;
        
        swapWithStats(arr, i, smallestIndex, stats);
        
        cout << "  Comparações nesta iteração: " 
             << (stats.comparisons - (i > 0 ? (size - i) : 0)) << endl;
        cout << "  Array atual: ";
        for (int j = 0; j < size; j++) {
            if (j <= i) {
                cout << "[" << arr[j] << "] ";
            } else {
                cout << arr[j] << " ";
            }
        }
        cout << endl << endl;
    }
    
    // Exibir estatísticas finais
    cout << "========== ESTATÍSTICAS FINAIS ==========" << endl;
    cout << "Total de comparações: " << stats.comparisons << endl;
    cout << "Total de trocas: " << stats.swaps << endl;
    cout << "Eficiência de trocas: " << stats.swaps << "/" << (size - 1) 
         << " (" << (stats.swaps * 100.0 / (size - 1)) << "%)" << endl;
    cout << "Comparações teóricas O(n²): " << (size * (size - 1) / 2) << endl;
    cout << "Comparações reais vs teóricas: " << stats.comparisons 
         << "/" << (size * (size - 1) / 2) << endl;
}

// Exemplo de uso
int main() {
    int numeros[] = {64, 34, 25, 12, 22, 11, 90};
    int tamanho = 7;
    
    selectionSortWithStats(numeros, tamanho);
    
    return 0;
}
```

**Análise das Estatísticas:**
- **Comparações**: Sempre n(n-1)/2 independente da entrada
- **Trocas**: No máximo n-1, pode ser menor se alguns elementos já estão no lugar
- **Eficiência**: Mostra quantas trocas foram realmente necessárias

## Exercício 3: Versão Estável
Implemente uma versão estável do Selection Sort.

### 💡 Solução do Exercício 3 {collapsible="true"}

<resource src="../../Domus/Domus-1/exercises-selection/stableSelection.cpp">Código completo</resource>

```cpp
#include <iostream>
using namespace std;

// Função para rotacionar elementos para manter estabilidade
void rotateRight(int arr[], int start, int end) {
    int temp = arr[end];
    for (int i = end; i > start; i--) {
        arr[i] = arr[i - 1];
    }
    arr[start] = temp;
}

// Selection Sort Estável
void stableSelectionSort(int arr[], int size) {
    cout << "=== SELECTION SORT ESTÁVEL ===" << endl;
    cout << "Array inicial: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl << endl;
    
    for (int i = 0; i < size - 1; i++) {
        cout << "Iteração " << (i + 1) << ":" << endl;
        
        // Encontrar o menor elemento na parte não ordenada
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        
        cout << "  Menor elemento: " << arr[minIndex] 
             << " (posição " << minIndex << ")" << endl;
        
        // Em vez de trocar, rotacionar para manter estabilidade
        if (minIndex != i) {
            cout << "  Rotacionando elementos da posição " << i 
                 << " até " << minIndex << endl;
            
            int minValue = arr[minIndex];
            rotateRight(arr, i, minIndex);
            
            cout << "  Elemento " << minValue 
                 << " movido para posição " << i << " mantendo ordem relativa" << endl;
        } else {
            cout << "  Elemento já está na posição correta" << endl;
        }
        
        cout << "  Array atual: ";
        for (int j = 0; j < size; j++) {
            if (j <= i) {
                cout << "[" << arr[j] << "] ";
            } else {
                cout << arr[j] << " ";
            }
        }
        cout << endl << endl;
    }
    
    cout << "Array final ordenado (estável): ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Versão para demonstrar estabilidade com pares (valor, índice original)
struct Element {
    int value;
    int originalIndex;
};

void printElements(Element arr[], int size, string label) {
    cout << label;
    for (int i = 0; i < size; i++) {
        cout << "(" << arr[i].value << "," << arr[i].originalIndex << ") ";
    }
    cout << endl;
}

void stableSelectionSortDemo(Element arr[], int size) {
    cout << "\n=== DEMONSTRAÇÃO DE ESTABILIDADE ===" << endl;
    printElements(arr, size, "Array inicial: ");
    
    for (int i = 0; i < size - 1; i++) {
        // Encontrar o menor elemento
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j].value < arr[minIndex].value) {
                minIndex = j;
            }
        }
        
        // Rotacionar para manter ordem relativa
        if (minIndex != i) {
            Element minElement = arr[minIndex];
            for (int k = minIndex; k > i; k--) {
                arr[k] = arr[k - 1];
            }
            arr[i] = minElement;
        }
        
        cout << "Após iteração " << (i + 1) << ": ";
        printElements(arr, size, "");
    }
}

int main() {
    // Teste básico
    int numeros[] = {4, 2, 2, 8, 3, 3, 1};
    int tamanho = 7;
    
    stableSelectionSort(numeros, tamanho);
    
    // Demonstração de estabilidade
    Element elementos[] = {
        {4, 0}, {2, 1}, {2, 2}, {8, 3}, {3, 4}, {3, 5}, {1, 6}
    };
    
    stableSelectionSortDemo(elementos, 7);
    
    return 0;
}
```

**Como funciona a versão estável:**
1. **Rotação em vez de troca**: Em vez de trocar o menor elemento com o primeiro, rotacionamos todos os elementos
2. **Preserva ordem relativa**: Elementos iguais mantêm sua ordem original
3. **Complexidade**: O(n²) tempo, mas O(n) operações de movimento por iteração
4. **Trade-off**: Mais operações de movimento, mas mantém estabilidade

**Diferença visual:**
- **Selection Sort normal**: `[2a, 2b] → [2b, 2a]` (não estável)
- **Selection Sort estável**: `[2a, 2b] → [2a, 2b]` (estável)
