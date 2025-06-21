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