#include <iostream>

using namespace std;

void swap(int array[], int x, int y)
{
    cout << "  -> Trocando elementos: " << array[x] << " (posição " << x << ") <-> " << array[y] << " (posição " << y << ")" << endl;
    int temp = array[x];
    array[x] = array[y];
    array[y] = temp;
    cout << "  -> Após a troca: posição " << x << " = " << array[x] << ", posição " << y << " = " << array[y] << endl;
}

int locOfSmallest(int array[], int s, int e)
{
    cout << "--- Procurando o menor elemento no intervalo [" << s << ", " << e << "] ---" << endl;
    int i = s;
    int j = i;
    int comparacoes = 0;

    cout << "Elemento inicial para comparação: array[" << j << "] = " << array[j] << endl;

    while (i <= e)
    {
        cout << "Comparando array[" << i << "] = " << array[i] << " com o menor atual array[" << j << "] = " << array[j];
        comparacoes++;
        
        if (array[i] < array[j])
        {
            cout << " -> " << array[i] << " é menor! Novo menor elemento encontrado na posição " << i << endl;
            j = i;
        }
        else
        {
            cout << " -> " << array[i] << " >= " << array[j] << ", mantendo o menor atual" << endl;
        }

        i++;
    }

    cout << "Menor elemento encontrado: " << array[j] << " na posição " << j << " (após " << comparacoes << " comparações)" << endl;
    return j;
}

void selectionSort(int array[], int n)
{
    cout << "========================================" << endl;
    cout << "INICIANDO SELECTION SORT" << endl;
    cout << "========================================" << endl;
    cout << "Array inicial: ";
    for(int k = 0; k < n; k++) {
        cout << array[k] << " ";
    }
    cout << endl << endl;

    int totalTrocas = 0;

    for (int i = 0; i < n - 1; i++)
    {
        cout << ">>> ITERAÇÃO " << (i + 1) << " <<<" << endl;
        cout << "Procurando o menor elemento para a posição " << i << endl;
        
        int j = locOfSmallest(array, i, n - 1);

        if (i != j) {
            cout << "Menor elemento está na posição " << j << ", precisa trocar com posição " << i << endl;
            swap(array, i, j);
            totalTrocas++;
        } else {
            cout << "Menor elemento já está na posição correta (" << i << "), não precisa trocar" << endl;
        }

        cout << "Estado do array após iteração " << (i + 1) << ": ";
        for(int k = 0; k < n; k++) {
            if (k <= i) {
                cout << "[" << array[k] << "] "; // Elementos já ordenados
            } else {
                cout << array[k] << " ";        // Elementos ainda não ordenados
            }
        }
        cout << endl;
        cout << "Elementos ordenados: " << (i + 1) << "/" << n << endl;
        cout << "--------------------------------" << endl;
    }

    cout << "========================================" << endl;
    cout << "SELECTION SORT CONCLUÍDO!" << endl;
    cout << "Total de trocas realizadas: " << totalTrocas << endl;
    cout << "========================================" << endl;
}

void display(int array[], int size)
{
    cout << endl;
    cout << "========== ARRAY RESULTADO ========== ";
    cout << endl;

    int i = 0;
    while (i < size)
    {
        cout << array[i] << " | ";
        i++;
    }
    cout << endl;
    cout << "===================================== ";
    cout << endl;
}

int main()
{
    cout << "=============================================" << endl;
    cout << "    DEMONSTRAÇÃO DO ALGORITMO SELECTION SORT" << endl;
    cout << "=============================================" << endl;
    cout << endl;
    
    int array[] = {64, 25, 12, 22, 11, 90, 5, 77, 30};
    int size = sizeof(array) / sizeof(int);

    cout << "EXPLICAÇÃO DO ALGORITMO:" << endl;
    cout << "O Selection Sort funciona dividindo o array em duas partes:" << endl;
    cout << "- Parte ordenada (inicialmente vazia, no início do array)" << endl;
    cout << "- Parte não ordenada (inicialmente todo o array)" << endl;
    cout << "Em cada iteração, encontra o menor elemento da parte não ordenada" << endl;
    cout << "e o move para o final da parte ordenada." << endl;
    cout << endl;
    
    cout << "Array antes da ordenação:";
    display(array, size);
    
    selectionSort(array, size);
    
    cout << "Array após a ordenação:";
    display(array, size);
    
    cout << endl;
    cout << "Observações:" << endl;
    cout << "- O algoritmo sempre faz exatamente n-1 passadas" << endl;
    cout << "- Em cada passada, encontra o menor elemento restante" << endl;
    cout << "- A parte esquerda do array fica sempre ordenada" << endl;
    cout << "- É mais eficiente que o Bubble Sort para arrays pequenos" << endl;
    cout << "- Tempo de complexidade: O(n²) comparações, O(n) trocas" << endl;

    return 0;
}
