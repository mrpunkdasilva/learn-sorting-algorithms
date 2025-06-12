#include <iostream>

using namespace std;


void swap(int array[], int x, int y)
{
  int temporary = array[x];
  array[x] = array[y];
  array[y] = temporary;
}

void bubble(int array[], int n)
{
  int i = n - 1;
  while (i > 0)
  {
    if (array[i] < array[i - 1])
    {
      swap(array, i, i - 1);
    }
    i--;
  }
}

void bubbleSort(int array[], int n)
{
  int i = 0;

  while (i <= n - 1)
  {
    bubble(array, n);
    i++;
  }
}

void display(int array[], int size)
{
  cout << endl;
  cout << " ========== ";
  cout << endl;

  int i = 0;
  while (i < size)
  {
    cout << array[i] << " | ";
    i++;
  }
}


int main()
{
  int array[] = {123, 578, 12, 35, 1245, 745, 901, 901, 9901901, 901};
  int size = sizeof(array) / sizeof(int);

  display(array, size);
  bubbleSort(array, size);
  display(array, size);

  return 0;
}
