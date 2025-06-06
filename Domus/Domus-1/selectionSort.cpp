#include <iostream>

using namespace std;

void swap(int array[], int x, int y)
{
    int temp = array[x];
    array[x] = array[y];
    array[y] = temp;
}

int locOfSmallest(int array[], int s, int e)
{
    int i = s;
    int j = i;

    while (i <= e)
    {
        if (array[i] < array[j])
        {
            j = i;
        }

        i++;
    }

    return j;
}

void selectionSort(int array[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int j = locOfSmallest(array, i, n - 1);

        swap(array, i, j);
    }
}

void display(int array[], int n)
{
    int i = 0;
    cout << endl;
    cout << " ========== ";
    cout << endl;
    while (i < n)
    {
        cout << array[i] << " | ";
        i++;
    }
}

int main()
{
    int array[] = {2, 34, 23, 12, 55, 34, 56, 157};
    int size = sizeof(array) / sizeof(int);

    display(array, size);

    selectionSort(array, size);

    display(array, size);

    return 0;
}
