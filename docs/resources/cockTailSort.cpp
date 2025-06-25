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