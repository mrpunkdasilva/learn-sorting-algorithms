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