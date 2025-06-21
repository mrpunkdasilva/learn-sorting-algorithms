#include <iostream>

using namespace std;

void swap(int array[], int x, int y)
{
  cout << "  -> Trocando elementos: " << array[x] << " (posição " << x << ") <-> " << array[y] << " (posição " << y << ")" << endl;
  int temporary = array[x];
  array[x] = array[y];
  array[y] = temporary;
  cout << "  -> Após a troca: posição " << x << " = " << array[x] << ", posição " << y << " = " << array[y] << endl;
}

void bubble(int array[], int n)
{
  cout << "--- Iniciando uma passada do bubble ---" << endl;
  int i = n - 1;
  int trocas = 0;
  
  while (i > 0)
  {
    cout << "Comparando array[" << i << "] = " << array[i] << " com array[" << (i-1) << "] = " << array[i-1];
    
    if (array[i] < array[i - 1])
    {
      cout << " -> " << array[i] << " é menor que " << array[i-1] << ", precisa trocar!" << endl;
      swap(array, i, i - 1);
      trocas++;
    }
    else
    {
      cout << " -> " << array[i] << " >= " << array[i-1] << ", não precisa trocar." << endl;
    }
    i--;
  }
  
  cout << "--- Fim da passada. Total de trocas: " << trocas << " ---" << endl;
  cout << endl;
}

void bubbleSort(int array[], int n)
{
  cout << "========================================" << endl;
  cout << "INICIANDO BUBBLE SORT" << endl;
  cout << "========================================" << endl;
  cout << "Array inicial: ";
  for(int j = 0; j < n; j++) {
    cout << array[j] << " ";
  }
  cout << endl << endl;
  
  int i = 0;
  while (i <= n - 1)
  {
    cout << ">>> ITERAÇÃO " << (i + 1) << " <<<" << endl;
    bubble(array, n);
    
    cout << "Estado do array após iteração " << (i + 1) << ": ";
    for(int j = 0; j < n; j++) {
      cout << array[j] << " ";
    }
    cout << endl;
    cout << "--------------------------------" << endl;
    
    i++;
  }
  
  cout << "========================================" << endl;
  cout << "BUBBLE SORT CONCLUÍDO!" << endl;
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
  cout << "===========================================" << endl;
  cout << "    DEMONSTRAÇÃO DO ALGORITMO BUBBLE SORT" << endl;
  cout << "===========================================" << endl;
  cout << endl;
  
  int array[] = {123, 578, 12, 35, 1245, 745, 901, 901, 9901901, 901};
  int size = sizeof(array) / sizeof(int);

  cout << "EXPLICAÇÃO DO ALGORITMO:" << endl;
  cout << "O Bubble Sort compara elementos adjacentes e os troca se estiverem" << endl;
  cout << "na ordem errada. Esse processo é repetido até que nenhuma troca" << endl;
  cout << "seja mais necessária." << endl;
  cout << endl;
  
  cout << "Array antes da ordenação:";
  display(array, size);
  
  bubbleSort(array, size);
  
  cout << "Array após a ordenação:";
  display(array, size);
  
  cout << endl;
  cout << "Observações:" << endl;
  cout << "- O algoritmo fez várias passadas pelo array" << endl;
  cout << "- Em cada passada, os elementos 'borbulharam' para suas posições corretas" << endl;
  cout << "- O menor elemento sempre vai para o início do array" << endl;
  cout << "- O processo continua até que não haja mais trocas necessárias" << endl;

  return 0;
}
