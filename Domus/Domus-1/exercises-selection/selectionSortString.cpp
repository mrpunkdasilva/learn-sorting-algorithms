#include <iostream>
#include <string>

using namespace std;

void swapStringElements(string stringArray[], int firstPosition, int secondPosition)
{
  cout << "  -> Swapping strings: \"" << stringArray[firstPosition] << "\" (position " << firstPosition << ") <-> \"" << stringArray[secondPosition] << "\" (position " << secondPosition << ")" << endl;
  string temporaryString = stringArray[firstPosition];
  stringArray[firstPosition] = stringArray[secondPosition];
  stringArray[secondPosition] = temporaryString;
  cout << "  -> After swap: position " << firstPosition << " = \"" << stringArray[firstPosition] << "\", position " << secondPosition << " = \"" << stringArray[secondPosition] << "\"" << endl;
}

int findSmallestStringIndex(string stringArray[], int startPosition, int endPosition)
{
  cout << "--- Finding smallest string from position " << startPosition << " to " << endPosition << " ---" << endl;
  int smallestStringIndex = startPosition;
  cout << "Starting with \"" << stringArray[smallestStringIndex] << "\" as current smallest" << endl;
  
  int currentIndex = startPosition + 1;
  while (currentIndex <= endPosition)
  {
    cout << "Comparing \"" << stringArray[currentIndex] << "\" (position " << currentIndex << ") with current smallest \"" << stringArray[smallestStringIndex] << "\" (position " << smallestStringIndex << ")";
    
    if (stringArray[currentIndex] < stringArray[smallestStringIndex])
    {
      cout << " -> \"" << stringArray[currentIndex] << "\" comes before \"" << stringArray[smallestStringIndex] << "\" alphabetically!" << endl;
      smallestStringIndex = currentIndex;
      cout << "  -> New smallest string: \"" << stringArray[smallestStringIndex] << "\" at position " << smallestStringIndex << endl;
    }
    else
    {
      cout << " -> \"" << stringArray[currentIndex] << "\" comes after \"" << stringArray[smallestStringIndex] << "\" alphabetically." << endl;
    }
    currentIndex++;
  }
  
  cout << "--- Smallest string found: \"" << stringArray[smallestStringIndex] << "\" at position " << smallestStringIndex << " ---" << endl;
  cout << endl;
  return smallestStringIndex;
}

void performSelectionSortIteration(string stringArray[], int arraySize, int currentIteration)
{
  cout << ">>> ITERATION " << (currentIteration + 1) << " <<<" << endl;
  cout << "Finding smallest string from position " << currentIteration << " to " << (arraySize - 1) << endl;
  
  int smallestStringIndex = findSmallestStringIndex(stringArray, currentIteration, arraySize - 1);
  
  if (currentIteration != smallestStringIndex)
  {
    cout << "String \"" << stringArray[smallestStringIndex] << "\" needs to be moved to position " << currentIteration << endl;
    swapStringElements(stringArray, currentIteration, smallestStringIndex);
  }
  else
  {
    cout << "String \"" << stringArray[currentIteration] << "\" is already in the correct position!" << endl;
  }
  
  cout << "Array state after iteration " << (currentIteration + 1) << ": ";
  for(int displayIndex = 0; displayIndex < arraySize; displayIndex++) {
    if (displayIndex <= currentIteration) {
      cout << "[" << stringArray[displayIndex] << "] ";
    } else {
      cout << stringArray[displayIndex] << " ";
    }
  }
  cout << endl;
  cout << "--------------------------------" << endl;
}

void selectionSortAlgorithmForStrings(string stringArray[], int arraySize)
{
  cout << "========================================" << endl;
  cout << "  STARTING SELECTION SORT FOR STRINGS" << endl;
  cout << "========================================" << endl;
  cout << "Initial string array: ";
  for(int displayIndex = 0; displayIndex < arraySize; displayIndex++) {
    cout << "\"" << stringArray[displayIndex] << "\" ";
  }
  cout << endl << endl;
  
  int iterationNumber = 0;
  while (iterationNumber < arraySize - 1)
  {
    performSelectionSortIteration(stringArray, arraySize, iterationNumber);
    iterationNumber++;
  }
  
  cout << "========================================" << endl;
  cout << "SELECTION SORT ALGORITHM COMPLETED!" << endl;
  cout << "========================================" << endl;
}

void displayStringArray(string stringArray[], int arraySize)
{
  cout << endl;
  cout << "========== STRING ARRAY RESULT ========== ";
  cout << endl;

  int displayIndex = 0;
  while (displayIndex < arraySize)
  {
    cout << "\"" << stringArray[displayIndex] << "\" | ";
    displayIndex++;
  }
  cout << endl;
  cout << "========================================== ";
  cout << endl;
}


int main()
{
  cout << "===============================================" << endl;
  cout << "  SELECTION SORT ALGORITHM FOR STRINGS DEMO" << endl;
  cout << "===============================================" << endl;
  cout << endl;
  
  string fruitsArray[] = {"banana", "maçã", "laranja", "uva", "abacaxi", "pêra", "manga"};
  int arraySize = sizeof(fruitsArray) / sizeof(string);

  cout << "ALGORITHM EXPLANATION:" << endl;
  cout << "Selection Sort finds the smallest element in the unsorted portion" << endl;
  cout << "of the array and places it at the beginning. For strings, this" << endl;
  cout << "means finding the alphabetically first string in each iteration." << endl;
  cout << "The process continues until all strings are in alphabetical order." << endl;
  cout << endl;
  
  cout << "String array before sorting:";
  displayStringArray(fruitsArray, arraySize);
  
  selectionSortAlgorithmForStrings(fruitsArray, arraySize);
  
  cout << "String array after sorting:";
  displayStringArray(fruitsArray, arraySize);
  
  cout << endl;
  cout << "IMPORTANT OBSERVATIONS:" << endl;
  cout << "- Strings are compared lexicographically (dictionary order)" << endl;
  cout << "- Each iteration finds the alphabetically smallest remaining string" << endl;
  cout << "- The algorithm makes exactly (n-1) iterations for n strings" << endl;
  cout << "- Unlike Bubble Sort, Selection Sort makes at most (n-1) swaps" << endl;
  cout << "- Time complexity: O(n²) for comparisons, O(n) for swaps" << endl;
  cout << "- It is NOT a stable sorting algorithm for strings" << endl;
  cout << "- Accented characters follow Unicode/ASCII ordering" << endl;

  return 0;
}