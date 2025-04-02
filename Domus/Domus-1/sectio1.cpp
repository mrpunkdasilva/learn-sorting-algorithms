#include <iostream>
#include <cstdlib>
#define MAX_SIZE 100
using namespace std;

int main()
{
    int n;
    int array[MAX_SIZE];

    cout << "Enter a number: " << endl;
    cin >> n;

    // preenchendo array
    for (int i = 0; i < n; i++) {
        array[i] = rand();
    }

    // saida do array
    for (int i = 0; i < n; i++) {
        cout << " [ " << array[i] <<  " ]  ";
    }
    cout << endl;

    // ordenar o array
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // Com isso conseguimos acesar o número e seu sucessor
            cout  << array[i] << " < " << array[j] << " " << endl;

            // ordem ascendente - se for descencedente basta inverter e colocar ">"
            if (array[i] < array[j])
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    cout << "==============================" << endl;

    // exibir o array ordenado
    for (int i = 0; i < n; i++) {
        cout << array[i] << "  ";
    }
    cout << endl;


    return 0;
}
