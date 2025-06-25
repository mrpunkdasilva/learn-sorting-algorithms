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