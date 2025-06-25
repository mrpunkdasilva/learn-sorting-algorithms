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