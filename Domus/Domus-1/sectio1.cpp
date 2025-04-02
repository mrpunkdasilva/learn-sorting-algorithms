#include <iostream>
#include <cstdlib>
#define MAX_SIZE 100
using namespace std;

int main()
{
    int n;  // Quantidade de elementos
    int array[MAX_SIZE];  // Nosso array (lista)

    // Pede ao usuário informar quantos elementos deseja
    cout << "Enter a number: " << endl;
    cin >> n;

    // Preenche o array com números aleatórios
    for (int i = 0; i < n; i++) {
        array[i] = rand();  // rand() gera número aleatório
    }

    // Exibe o array desordenado
    for (int i = 0; i < n; i++) {
        cout << " [ " << array[i] <<  " ]  ";
    }
    cout << endl;

    // ALGORITMO DE ORDENAÇÃO (o núcleo do código)
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // Mostra quais elementos estão sendo comparados
            cout << array[i] << " < " << array[j] << " " << endl;

            // Se o elemento atual for MENOR que o próximo
            if (array[i] < array[j])
            {
                // Realiza a troca (swap) dos elementos
                int temp = array[i];  // Armazena o valor temporariamente
                array[i] = array[j];  // Substitui i por j
                array[j] = temp;     // Completa a troca
            }
        }
    }

    cout << "==============================" << endl;

    // Exibe o array ordenado (em ordem decrescente)
    for (int i = 0; i < n; i++) {
        cout << array[i] << "  ";
    }
    cout << endl;

    return 0;
}