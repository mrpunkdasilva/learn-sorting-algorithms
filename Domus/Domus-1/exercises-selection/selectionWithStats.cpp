#include <iostream>

using namespace std;

void swapArrayElements(int integerArray[], int firstPosition, int secondPosition)
{
  cout << "  -> Swapping elements: " << integerArray[firstPosition] << " (position " << firstPosition << ") <-> " << integerArray[secondPosition] << " (position " << secondPosition << ")" << endl;
  int temporaryValue = integerArray[firstPosition];
  integerArray[firstPosition] = integerArray[secondPosition];
  integerArray[secondPosition] = temporaryValue;
  cout << "  -> After swap: position " << firstPosition << " = " << integerArray[firstPosition] << ", position " << secondPosition << " = " << integerArray[secondPosition] << endl;
}

int findSmallestElementIndex(int integerArray[], int startPosition, int endPosition)
{
  cout << "--- Finding smallest element from position " << startPosition << " to " << endPosition << " ---" << endl;
  int smallestElementIndex = startPosition;
  cout << "Starting with " << integerArray[smallestElementIndex] << " as current smallest" << endl;
  
  int currentIndex = startPosition + 1;
  while (currentIndex <= endPosition)
  {
    cout << "Comparing " << integerArray[currentIndex] << " (position " << currentIndex << ") with current smallest " << integerArray[smallestElementIndex] << " (position " << smallestElementIndex << ")";
    
    if (integerArray[currentIndex] < integerArray[smallestElementIndex])
    {
      cout << " -> " << integerArray[currentIndex] << " is smaller!" << endl;
      smallestElementIndex = currentIndex;
      cout << "  -> New smallest element: " << integerArray[smallestElementIndex] << " at position " << smallestElementIndex << endl;
    }
    else
    {
      cout << " -> " << integerArray[smallestElementIndex] << " remains the smallest." << endl;
    }
    currentIndex++;
  }
  
  cout << "--- Smallest element found: " << integerArray[smallestElementIndex] << " at position " << smallestElementIndex << " ---" << endl;
  cout << endl;
  return smallestElementIndex;
}

void performSelectionSortIteration(int integerArray[], int arraySize, int currentIteration)
{
  cout << ">>> ITERATION " << (currentIteration + 1) << " <<<" << endl;
  cout << "Finding smallest element from position " << currentIteration << " to " << (arraySize - 1) << endl;
  
  int smallestElementIndex = findSmallestElementIndex(integerArray, currentIteration, arraySize - 1);
  
  if (currentIteration != smallestElementIndex)
  {
    cout << "Element " << integerArray[smallestElementIndex] << " needs to be moved to position " << currentIteration << endl;
    swapArrayElements(integerArray, currentIteration, smallestElementIndex);
  }
  else
  {
    cout << "Element " << integerArray[currentIteration] << " is already in the correct position!" << endl;
  }
  
  cout << "Array state after iteration " << (currentIteration + 1) << ": ";
  for(int displayIndex = 0; displayIndex < arraySize; displayIndex++) {
    if (displayIndex <= currentIteration) {
      cout << "[" << integerArray[displayIndex] << "] ";
    } else {
      cout << integerArray[displayIndex] << " ";
    }
  }
  cout << endl;
  cout << "--------------------------------" << endl;
}

void selectionSortAlgorithmWithStatistics(int integerArray[], int arraySize)
{
  cout << "========================================" << endl;
  cout << "  STARTING SELECTION SORT WITH STATISTICS" << endl;
  cout << "========================================" << endl;
  cout << "Initial array: ";
  for(int displayIndex = 0; displayIndex < arraySize; displayIndex++) {
    cout << integerArray[displayIndex] << " ";
  }
  cout << endl << endl;
  
  int totalComparisons = 0;
  int totalSwaps = 0;
  
  int iterationNumber = 0;
  while (iterationNumber < arraySize - 1)
  {
    int comparisonsBeforeIteration = totalComparisons;
    int swapsBeforeIteration = totalSwaps;
    
    performSelectionSortIteration(integerArray, arraySize, iterationNumber);
    
    // Calculate statistics (manual count for educational purposes)
    int comparisonsThisIteration = arraySize - iterationNumber - 1;
    totalComparisons += comparisonsThisIteration;
    
    // Count swaps by checking if elements were actually swapped
    if (iterationNumber > 0) {
      // Simple way to track swaps - in real implementation this would be tracked during swap
      totalSwaps = iterationNumber; // Approximation for educational display
    }
    
    cout << "Statistics for iteration " << (iterationNumber + 1) << ":" << endl;
    cout << "  -> Comparisons this iteration: " << comparisonsThisIteration << endl;
    cout << "  -> Total comparisons so far: " << totalComparisons << endl;
    cout << endl;
    
    iterationNumber++;
  }
  
  cout << "========================================" << endl;
  cout << "SELECTION SORT ALGORITHM COMPLETED!" << endl;
  cout << "========================================" << endl;
  
  cout << "========== FINAL STATISTICS ==========" << endl;
  cout << "Total comparisons: " << totalComparisons << endl;
  cout << "Theoretical comparisons O(n²): " << (arraySize * (arraySize - 1) / 2) << endl;
  cout << "Maximum possible swaps: " << (arraySize - 1) << endl;
  cout << "Algorithm characteristics:" << endl;
  cout << "  - Time complexity: O(n²) for comparisons" << endl;
  cout << "  - Space complexity: O(1) - in-place sorting" << endl;
  cout << "  - Stability: NOT stable" << endl;
  cout << "  - Adaptivity: NOT adaptive" << endl;
  cout << "=======================================" << endl;
}

void displayIntegerArray(int integerArray[], int arraySize)
{
  cout << endl;
  cout << "========== INTEGER ARRAY RESULT ========== ";
  cout << endl;

  int displayIndex = 0;
  while (displayIndex < arraySize)
  {
    cout << integerArray[displayIndex] << " | ";
    displayIndex++;
  }
  cout << endl;
  cout << "========================================== ";
  cout << endl;
}

int main()
{
  cout << "===============================================" << endl;
  cout << "  SELECTION SORT ALGORITHM WITH STATISTICS DEMO" << endl;
  cout << "===============================================" << endl;
  cout << endl;
  
  int numbersArray[] = {64, 34, 25, 12, 22, 11, 90};
  int arraySize = sizeof(numbersArray) / sizeof(int);

  cout << "ALGORITHM EXPLANATION:" << endl;
  cout << "Selection Sort finds the smallest element in the unsorted portion" << endl;
  cout << "of the array and places it at the beginning. This process continues" << endl;
  cout << "until all elements are sorted. We track comparisons and operations" << endl;
  cout << "to understand the algorithm's efficiency." << endl;
  cout << endl;
  
  cout << "Integer array before sorting:";
  displayIntegerArray(numbersArray, arraySize);
  
  selectionSortAlgorithmWithStatistics(numbersArray, arraySize);
  
  cout << "Integer array after sorting:";
  displayIntegerArray(numbersArray, arraySize);
  
  cout << endl;
  cout << "IMPORTANT OBSERVATIONS:" << endl;
  cout << "- Selection Sort always performs O(n²) comparisons" << endl;
  cout << "- It performs at most (n-1) swaps, making it efficient for write operations" << endl;
  cout << "- Unlike Bubble Sort, it doesn't adapt to already sorted data" << endl;
  cout << "- It's an in-place sorting algorithm requiring O(1) extra memory" << endl;
  cout << "- Best used when write operations are expensive" << endl;
  cout << "- Not stable: relative order of equal elements may change" << endl;

  return 0;
}