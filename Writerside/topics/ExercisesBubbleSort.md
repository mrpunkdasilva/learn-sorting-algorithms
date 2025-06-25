# Exercícios Práticos

## Exercício 1: Implementação Básica
Implemente o Bubble Sort para ordenar um array de strings por ordem alfabética.

### 💡 Solução do Exercício 1 {collapsible="true"}

<resource src="../../../Domus/Domus-1/exercises-bubble/bubbleSortString.cpp">
Código completo
</resource>

```cpp
#include <iostream>
#include <string>
using namespace std;

// Função para trocar duas strings
void swapStrings(string arr[], int pos1, int pos2) {
    cout << "  -> Trocando \"" << arr[pos1] << "\" com \"" << arr[pos2] << "\"" << endl;
    string temp = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = temp;
}

// Bubble Sort para strings
void bubbleSortStrings(string arr[], int size) {
    cout << "Ordenando strings por ordem alfabética usando Bubble Sort:" << endl;
    
    for (int i = 0; i < size - 1; i++) {
        cout << "\n>>> ITERAÇÃO " << (i + 1) << " <<<" << endl;
        bool hasSwapped = false;
        
        for (int j = 0; j < size - i - 1; j++) {
            cout << "Comparando \"" << arr[j] << "\" com \"" << arr[j + 1] << "\"";
            
            if (arr[j] > arr[j + 1]) {
                cout << " -> \"" << arr[j] << "\" > \"" << arr[j + 1] << "\", precisa trocar!" << endl;
                swapStrings(arr, j, j + 1);
                hasSwapped = true;
            } else {
                cout << " -> \"" << arr[j] << "\" <= \"" << arr[j + 1] << "\", sem troca" << endl;
            }
        }
        
        cout << "Array após iteração " << (i + 1) << ": ";
        for (int k = 0; k < size; k++) {
            if (k >= size - i - 1) {
                cout << "[\"" << arr[k] << "\"] ";
            } else {
                cout << "\"" << arr[k] << "\" ";
            }
        }
        cout << endl;
        
        if (!hasSwapped) {
            cout << "Nenhuma troca realizada - array já está ordenado!" << endl;
            break;
        }
    }
}

int main() {
    const int SIZE = 6;
    string nomes[SIZE] = {"Maria", "João", "Ana", "Pedro", "Carlos", "Beatriz"};
    
    cout << "Array inicial: ";
    for (int i = 0; i < SIZE; i++) {
        cout << "\"" << nomes[i] << "\" ";
    }
    cout << endl << endl;
    
    bubbleSortStrings(nomes, SIZE);
    
    cout << "\n========================================" << endl;
    cout << "RESULTADO FINAL:" << endl;
    cout << "Array ordenado: ";
    for (int i = 0; i < SIZE; i++) {
        cout << "\"" << nomes[i] << "\" ";
    }
    cout << endl;
    cout << "========================================" << endl;
    
    return 0;
}
```

## Exercício 2: Bubble Sort com Contador de Operações
Modifique o algoritmo Bubble Sort para contar e exibir o número total de comparações e trocas realizadas.

### 💡 Solução do Exercício 2 {collapsible="true"}

<resource src="../../../Domus/Domus-1/exercises-bubble/bubbleWithStats.cpp">
Código completo
</resource>

```cpp
#include <iostream>
using namespace std;

struct BubbleSortStats {
    int comparisons;
    int swaps;
    int iterations;
};

void bubbleSortWithStats(int arr[], int size, BubbleSortStats& stats) {
    stats.comparisons = 0;
    stats.swaps = 0;
    stats.iterations = 0;
    
    cout << "Bubble Sort com estatísticas detalhadas:" << endl;
    
    for (int i = 0; i < size - 1; i++) {
        stats.iterations++;
        cout << "\n>>> ITERAÇÃO " << stats.iterations << " <<<" << endl;
        bool hasSwapped = false;
        
        for (int j = 0; j < size - i - 1; j++) {
            stats.comparisons++;
            cout << "Comparação " << stats.comparisons << ": " << arr[j] << " vs " << arr[j + 1];
            
            if (arr[j] > arr[j + 1]) {
                // Realizar troca
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                
                stats.swaps++;
                hasSwapped = true;
                cout << " -> Troca " << stats.swaps << " realizada!" << endl;
            } else {
                cout << " -> Sem troca necessária" << endl;
            }
        }
        
        cout << "Array após iteração " << stats.iterations << ": ";
        for (int k = 0; k < size; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;
        
        if (!hasSwapped) {
            cout << "Otimização: Array já ordenado, parando antecipadamente!" << endl;
            break;
        }
    }
}

int main() {
    int numeros[] = {64, 34, 25, 12, 22, 11, 90};
    int tamanho = sizeof(numeros) / sizeof(numeros[0]);
    BubbleSortStats estatisticas;
    
    cout << "Array inicial: ";
    for (int i = 0; i < tamanho; i++) {
        cout << numeros[i] << " ";
    }
    cout << endl;
    
    bubbleSortWithStats(numeros, tamanho, estatisticas);
    
    cout << "\n========================================" << endl;
    cout << "ESTATÍSTICAS FINAIS:" << endl;
    cout << "Iterações realizadas: " << estatisticas.iterations << endl;
    cout << "Total de comparações: " << estatisticas.comparisons << endl;
    cout << "Total de trocas: " << estatisticas.swaps << endl;
    cout << "Array final: ";
    for (int i = 0; i < tamanho; i++) {
        cout << numeros[i] << " ";
    }
    cout << endl;
    cout << "========================================" << endl;
    
    return 0;
}
```

## Exercício 3: Bubble Sort Bidirecional (Cocktail Sort)
Implemente uma variação do Bubble Sort que funciona nas duas direções.

### 💡 Solução do Exercício 3 {collapsible="true"}

<resource src="../../../Domus/Domus-1/exercises-bubble/cockTailSort.cpp">
Código completo
</resource>

```cpp
#include <iostream>
using namespace std;

void cocktailSort(int arr[], int size) {
    cout << "Implementando Cocktail Sort (Bubble Sort Bidirecional):" << endl;
    
    bool hasSwapped = true;
    int start = 0;
    int end = size - 1;
    int iteration = 0;
    
    while (hasSwapped) {
        iteration++;
        hasSwapped = false;
        
        cout << "\n>>> ITERAÇÃO " << iteration << " - DIREÇÃO →" << endl;
        // Passada da esquerda para direita
        for (int i = start; i < end; i++) {
            cout << "Comparando " << arr[i] << " com " << arr[i + 1];
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                hasSwapped = true;
                cout << " -> Trocado!" << endl;
            } else {
                cout << " -> Sem troca" << endl;
            }
        }
        
        if (!hasSwapped) {
            break;
        }
        
        end--;
        
        cout << "\n>>> ITERAÇÃO " << iteration << " - DIREÇÃO ←" << endl;
        // Passada da direita para esquerda
        for (int i = end; i > start; i--) {
            cout << "Comparando " << arr[i] << " com " << arr[i - 1];
            if (arr[i] < arr[i - 1]) {
                swap(arr[i], arr[i - 1]);
                hasSwapped = true;
                cout << " -> Trocado!" << endl;
            } else {
                cout << " -> Sem troca" << endl;
            }
        }
        
        start++;
        
        cout << "Array após iteração " << iteration << ": ";
        for (int j = 0; j < size; j++) {
            cout << arr[j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int numeros[] = {5, 1, 4, 2, 8, 0, 2};
    int tamanho = sizeof(numeros) / sizeof(numeros[0]);
    
    cout << "Array inicial: ";
    for (int i = 0; i < tamanho; i++) {
        cout << numeros[i] << " ";
    }
    cout << endl;
    
    cocktailSort(numeros, tamanho);
    
    cout << "\nArray final ordenado: ";
    for (int i = 0; i < tamanho; i++) {
        cout << numeros[i] << " ";
    }
    cout << endl;
    
    return 0;
}
```

## Exercício 4: Análise de Performance
Compare o desempenho do Bubble Sort com e sem otimização de parada antecipada.

### 🤔 Desafio Extra
Implemente uma versão do Bubble Sort que:
1. Conta operações (comparações e trocas)
2. Para automaticamente quando detecta que está ordenado
3. Mostra estatísticas detalhadas no final
4. Funciona com diferentes tipos de dados (int, float, string)

### 🏆 Solução do Desafio Extra {collapsible="true"}

<resource src="../../../Domus/Domus-1/exercises-bubble/advancedBubbleSort.cpp">
Código completo
</resource>

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <iomanip>
using namespace std;
using namespace std::chrono;

// Estrutura para armazenar estatísticas de ordenação
struct SortingStats {
    int comparisons = 0;
    int swaps = 0;
    int iterations = 0;
    double timeElapsed = 0.0;
    bool optimizedExit = false;
};

// Template para Bubble Sort genérico com estatísticas
template<typename T>
void advancedBubbleSort(T arr[], int size, SortingStats& stats) {
    auto start = high_resolution_clock::now();
    
    cout << "\n========================================" << endl;
    cout << "ADVANCED BUBBLE SORT WITH STATISTICS" << endl;
    cout << "========================================" << endl;
    
    stats = {0, 0, 0, 0.0, false}; // Reset statistics
    
    cout << "Array inicial: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl << endl;
    
    bool hasSwapped = true;
    
    while (hasSwapped && stats.iterations < size - 1) {
        hasSwapped = false;
        stats.iterations++;
        
        cout << ">>> ITERAÇÃO " << stats.iterations << " <<<" << endl;
        
        for (int i = 0; i < size - stats.iterations; i++) {
            stats.comparisons++;
            
            cout << "Comparação " << stats.comparisons << ": " 
                 << arr[i] << " vs " << arr[i + 1];
            
            if (arr[i] > arr[i + 1]) {
                // Realizar troca
                T temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                
                stats.swaps++;
                hasSwapped = true;
                cout << " -> Troca " << stats.swaps << " realizada!" << endl;
            } else {
                cout << " -> Sem troca necessária" << endl;
            }
        }
        
        cout << "Estado do array: ";
        for (int i = 0; i < size; i++) {
            if (i >= size - stats.iterations) {
                cout << "[" << arr[i] << "] ";
            } else {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
        
        if (!hasSwapped) {
            stats.optimizedExit = true;
            cout << "🎯 OTIMIZAÇÃO: Array já ordenado! Parando antecipadamente." << endl;
        }
        cout << "--------------------------------" << endl;
    }
    
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    stats.timeElapsed = duration.count() / 1000.0; // Convert to milliseconds
    
    cout << "\n========================================" << endl;
    cout << "ESTATÍSTICAS DETALHADAS" << endl;
    cout << "========================================" << endl;
    cout << "Elementos no array: " << size << endl;
    cout << "Iterações realizadas: " << stats.iterations << endl;
    cout << "Total de comparações: " << stats.comparisons << endl;
    cout << "Total de trocas: " << stats.swaps << endl;
    cout << "Tempo de execução: " << fixed << setprecision(3) 
         << stats.timeElapsed << " ms" << endl;
    cout << "Otimização ativada: " << (stats.optimizedExit ? "✅ Sim" : "❌ Não") << endl;
    cout << "Eficiência: " << fixed << setprecision(2) 
         << ((double)stats.swaps / stats.comparisons * 100) << "% das comparações resultaram em trocas" << endl;
    
    cout << "\nArray final ordenado: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "========================================" << endl;
}

// Função para testar com diferentes tipos de dados
void testWithIntegers() {
    cout << "\n🔢 TESTE COM NÚMEROS INTEIROS" << endl;
    int numeros[] = {64, 34, 25, 12, 22, 11, 90};
    int tamanho = sizeof(numeros) / sizeof(numeros[0]);
    SortingStats stats;
    
    advancedBubbleSort(numeros, tamanho, stats);
}

void testWithFloats() {
    cout << "\n🔢 TESTE COM NÚMEROS DECIMAIS" << endl;
    float decimais[] = {3.14f, 2.71f, 1.41f, 1.73f, 0.57f};
    int tamanho = sizeof(decimais) / sizeof(decimais[0]);
    SortingStats stats;
    
    advancedBubbleSort(decimais, tamanho, stats);
}

void testWithStrings() {
    cout << "\n📝 TESTE COM STRINGS" << endl;
    string nomes[] = {"Maria", "João", "Ana", "Pedro", "Carlos"};
    int tamanho = sizeof(nomes) / sizeof(nomes[0]);
    SortingStats stats;
    
    advancedBubbleSort(nomes, tamanho, stats);
}

void testWithAlreadySorted() {
    cout << "\n✅ TESTE COM ARRAY JÁ ORDENADO (Demonstração de Otimização)" << endl;
    int ordenado[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int tamanho = sizeof(ordenado) / sizeof(ordenado[0]);
    SortingStats stats;
    
    advancedBubbleSort(ordenado, tamanho, stats);
}

void testWithReverseSorted() {
    cout << "\n❌ TESTE COM ARRAY INVERSAMENTE ORDENADO (Pior Caso)" << endl;
    int reverso[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int tamanho = sizeof(reverso) / sizeof(reverso[0]);
    SortingStats stats;
    
    advancedBubbleSort(reverso, tamanho, stats);
}

// Função para comparar performance
void performanceComparison() {
    cout << "\n📊 COMPARAÇÃO DE PERFORMANCE" << endl;
    cout << "=============================" << endl;
    
    // Teste com diferentes tamanhos
    vector<int> sizes = {5, 10, 15};
    
    for (int size : sizes) {
        cout << "\n🔍 Testando com " << size << " elementos:" << endl;
        
        // Criar array aleatório
        int* arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = rand() % 100;
        }
        
        SortingStats stats;
        advancedBubbleSort(arr, size, stats);
        
        cout << "Resultado: " << stats.iterations << " iterações, " 
             << stats.comparisons << " comparações, " 
             << stats.swaps << " trocas em " 
             << stats.timeElapsed << " ms" << endl;
        
        delete[] arr;
    }
}

int main() {
    cout << "==================================================" << endl;
    cout << "BUBBLE SORT AVANÇADO - DESAFIO EXTRA COMPLETO" << endl;
    cout << "==================================================" << endl;
    
    // Teste com diferentes tipos de dados
    testWithIntegers();
    testWithFloats();
    testWithStrings();
    
    // Testes especiais para demonstrar otimizações
    testWithAlreadySorted();
    testWithReverseSorted();
    
    // Comparação de performance
    performanceComparison();
    
    cout << "\n🎉 Todos os testes foram concluídos com sucesso!" << endl;
    cout << "📚 Este exemplo demonstra:" << endl;
    cout << "   ✅ Contagem de operações" << endl;
    cout << "   ✅ Parada antecipada (otimização)" << endl;
    cout << "   ✅ Estatísticas detalhadas" << endl;
    cout << "   ✅ Suporte a diferentes tipos de dados" << endl;
    cout << "   ✅ Medição de tempo de execução" << endl;
    cout << "   ✅ Análise de eficiência" << endl;
    
    return 0;
}
```

#### 🔍 Explicação da Solução

Esta solução avançada implementa todos os requisitos do desafio:

##### 1. **Contagem de Operações**
- Struct `SortingStats` armazena comparações, trocas, iterações e tempo
- Cada operação é contada e exibida em tempo real

##### 2. **Parada Antecipada**
- Flag `hasSwapped` detecta quando não há mais trocas
- Para automaticamente, economizando iterações desnecessárias

##### 3. **Estatísticas Detalhadas**
- Número total de operações realizadas
- Tempo de execução em milissegundos
- Percentual de eficiência (trocas/comparações)
- Indicação se a otimização foi ativada

##### 4. **Suporte a Diferentes Tipos**
- Template genérico funciona com `int`, `float`, `string`
- Testes demonstram funcionamento com cada tipo

##### 5. **Recursos Extras**
- Visualização do processo de ordenação
- Testes com casos especiais (já ordenado, inverso)
- Comparação de performance com diferentes tamanhos
- Medição precisa de tempo de execução

Esta implementação é ideal para estudos avançados de algoritmos e análise de performance! 