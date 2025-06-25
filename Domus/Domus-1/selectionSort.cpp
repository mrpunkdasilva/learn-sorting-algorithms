#include <iostream>

using namespace std;

void swapElements(int dataArray[], int firstPosition, int secondPosition)
{
    cout << "  -> Swapping elements: " << dataArray[firstPosition] << " (position " << firstPosition << ") <-> " << dataArray[secondPosition] << " (position " << secondPosition << ")" << endl;
    int temporaryValue = dataArray[firstPosition];
    dataArray[firstPosition] = dataArray[secondPosition];
    dataArray[secondPosition] = temporaryValue;
    cout << "  -> After swap: position " << firstPosition << " = " << dataArray[firstPosition] << ", position " << secondPosition << " = " << dataArray[secondPosition] << endl;
}

int findSmallestElementIndex(int dataArray[], int startIndex, int endIndex)
{
    cout << "--- Searching for smallest element in range [" << startIndex << ", " << endIndex << "] ---" << endl;
    int currentIndex = startIndex;
    int smallestIndex = currentIndex;
    int numberOfComparisons = 0;

    cout << "Initial element for comparison: dataArray[" << smallestIndex << "] = " << dataArray[smallestIndex] << endl;

    while (currentIndex <= endIndex)
    {
        cout << "Comparing dataArray[" << currentIndex << "] = " << dataArray[currentIndex] << " with current smallest dataArray[" << smallestIndex << "] = " << dataArray[smallestIndex];
        numberOfComparisons++;
        
        if (dataArray[currentIndex] < dataArray[smallestIndex])
        {
            cout << " -> " << dataArray[currentIndex] << " is smaller! New smallest element found at position " << currentIndex << endl;
            smallestIndex = currentIndex;
        }
        else
        {
            cout << " -> " << dataArray[currentIndex] << " >= " << dataArray[smallestIndex] << ", keeping current smallest" << endl;
        }

        currentIndex++;
    }

    cout << "Smallest element found: " << dataArray[smallestIndex] << " at position " << smallestIndex << " (after " << numberOfComparisons << " comparisons)" << endl;
    return smallestIndex;
}

void selectionSortAlgorithm(int dataArray[], int arraySize)
{
    cout << "========================================" << endl;
    cout << "STARTING SELECTION SORT ALGORITHM" << endl;
    cout << "========================================" << endl;
    cout << "Initial array: ";
    for(int displayIndex = 0; displayIndex < arraySize; displayIndex++) {
        cout << dataArray[displayIndex] << " ";
    }
    cout << endl << endl;

    int totalNumberOfSwaps = 0;

    for (int currentPosition = 0; currentPosition < arraySize - 1; currentPosition++)
    {
        cout << ">>> ITERATION " << (currentPosition + 1) << " <<<" << endl;
        cout << "Looking for smallest element for position " << currentPosition << endl;
        
        int smallestElementIndex = findSmallestElementIndex(dataArray, currentPosition, arraySize - 1);

        if (currentPosition != smallestElementIndex) {
            cout << "Smallest element is at position " << smallestElementIndex << ", need to swap with position " << currentPosition << endl;
            swapElements(dataArray, currentPosition, smallestElementIndex);
            totalNumberOfSwaps++;
        } else {
            cout << "Smallest element is already in correct position (" << currentPosition << "), no swap needed" << endl;
        }

        cout << "Array state after iteration " << (currentPosition + 1) << ": ";
        for(int displayIndex = 0; displayIndex < arraySize; displayIndex++) {
            if (displayIndex <= currentPosition) {
                cout << "[" << dataArray[displayIndex] << "] "; // Already sorted elements
            } else {
                cout << dataArray[displayIndex] << " ";        // Not yet sorted elements
            }
        }
        cout << endl;
        cout << "Elements sorted: " << (currentPosition + 1) << "/" << arraySize << endl;
        cout << "--------------------------------" << endl;
    }

    cout << "========================================" << endl;
    cout << "SELECTION SORT ALGORITHM COMPLETED!" << endl;
    cout << "Total number of swaps performed: " << totalNumberOfSwaps << endl;
    cout << "========================================" << endl;
}

void displayArray(int dataArray[], int arraySize)
{
    cout << endl;
    cout << "========== ARRAY RESULT ========== ";
    cout << endl;

    int displayIndex = 0;
    while (displayIndex < arraySize)
    {
        cout << dataArray[displayIndex] << " | ";
        displayIndex++;
    }
    cout << endl;
    cout << "=================================== ";
    cout << endl;
}

int main()
{
    cout << "=============================================" << endl;
    cout << "   SELECTION SORT ALGORITHM DEMONSTRATION" << endl;
    cout << "=============================================" << endl;
    cout << endl;
    
    int numbersArray[] = {64, 25, 12, 22, 11, 90, 5, 77, 30};
    int arraySize = sizeof(numbersArray) / sizeof(int);

    cout << "ALGORITHM EXPLANATION:" << endl;
    cout << "Selection Sort works by dividing the array into two parts:" << endl;
    cout << "- Sorted part (initially empty, at the beginning of the array)" << endl;
    cout << "- Unsorted part (initially the entire array)" << endl;
    cout << "In each iteration, it finds the smallest element from the unsorted part" << endl;
    cout << "and moves it to the end of the sorted part." << endl;
    cout << endl;
    
    cout << "Array before sorting:";
    displayArray(numbersArray, arraySize);
    
    selectionSortAlgorithm(numbersArray, arraySize);
    
    cout << "Array after sorting:";
    displayArray(numbersArray, arraySize);
    
    cout << endl;
    cout << "IMPORTANT OBSERVATIONS:" << endl;
    cout << "- The algorithm always performs exactly n-1 passes" << endl;
    cout << "- In each pass, it finds the smallest remaining element" << endl;
    cout << "- The left part of the array is always kept sorted" << endl;
    cout << "- It is more efficient than Bubble Sort for small arrays" << endl;
    cout << "- Time complexity: O(n²) comparisons, O(n) swaps" << endl;
    cout << "- It is NOT a stable sorting algorithm" << endl;
    cout << "- Performs well when memory writes are expensive" << endl;

    return 0;
}
