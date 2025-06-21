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

void performBubblePass(int dataArray[], int arraySize)
{
  cout << "--- Starting a bubble pass ---" << endl;
  int currentIndex = arraySize - 1;
  int numberOfSwaps = 0;
  
  while (currentIndex > 0)
  {
    cout << "Comparing dataArray[" << currentIndex << "] = " << dataArray[currentIndex] << " with dataArray[" << (currentIndex-1) << "] = " << dataArray[currentIndex-1];
    
    if (dataArray[currentIndex] < dataArray[currentIndex - 1])
    {
      cout << " -> " << dataArray[currentIndex] << " is smaller than " << dataArray[currentIndex-1] << ", need to swap!" << endl;
      swapElements(dataArray, currentIndex, currentIndex - 1);
      numberOfSwaps++;
    }
    else
    {
      cout << " -> " << dataArray[currentIndex] << " >= " << dataArray[currentIndex-1] << ", no swap needed." << endl;
    }
    currentIndex--;
  }
  
  cout << "--- End of pass. Total swaps: " << numberOfSwaps << " ---" << endl;
  cout << endl;
}

void bubbleSortAlgorithm(int dataArray[], int arraySize)
{
  cout << "========================================" << endl;
  cout << "STARTING BUBBLE SORT ALGORITHM" << endl;
  cout << "========================================" << endl;
  cout << "Initial array: ";
  for(int displayIndex = 0; displayIndex < arraySize; displayIndex++) {
    cout << dataArray[displayIndex] << " ";
  }
  cout << endl << endl;
  
  int iterationNumber = 0;
  while (iterationNumber <= arraySize - 1)
  {
    cout << ">>> ITERATION " << (iterationNumber + 1) << " <<<" << endl;
    performBubblePass(dataArray, arraySize);
    
    cout << "Array state after iteration " << (iterationNumber + 1) << ": ";
    for(int displayIndex = 0; displayIndex < arraySize; displayIndex++) {
      cout << dataArray[displayIndex] << " ";
    }
    cout << endl;
    cout << "--------------------------------" << endl;
    
    iterationNumber++;
  }
  
  cout << "========================================" << endl;
  cout << "BUBBLE SORT ALGORITHM COMPLETED!" << endl;
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
  cout << "===========================================" << endl;
  cout << "    BUBBLE SORT ALGORITHM DEMONSTRATION" << endl;
  cout << "===========================================" << endl;
  cout << endl;
  
  int numbersArray[] = {64, 34, 25, 12, 22, 11, 90, 88, 76, 50};
  int arraySize = sizeof(numbersArray) / sizeof(int);

  cout << "ALGORITHM EXPLANATION:" << endl;
  cout << "Bubble Sort compares adjacent elements and swaps them if they are" << endl;
  cout << "in the wrong order. This process is repeated until no more swaps" << endl;
  cout << "are needed. The name 'bubble' comes from the way smaller elements" << endl;
  cout << "'bubble' to the beginning of the array." << endl;
  cout << endl;
  
  cout << "Array before sorting:";
  displayArray(numbersArray, arraySize);
  
  bubbleSortAlgorithm(numbersArray, arraySize);
  
  cout << "Array after sorting:";
  displayArray(numbersArray, arraySize);
  
  cout << endl;
  cout << "IMPORTANT OBSERVATIONS:" << endl;
  cout << "- The algorithm made multiple passes through the array" << endl;
  cout << "- In each pass, smaller elements 'bubbled' towards the beginning" << endl;
  cout << "- Each element is compared with its adjacent neighbor" << endl;
  cout << "- The process continues until no more swaps are necessary" << endl;
  cout << "- Time complexity: O(n²) in worst case, O(n) in best case" << endl;
  cout << "- It is a stable sorting algorithm (maintains relative order)" << endl;

  return 0;
}
