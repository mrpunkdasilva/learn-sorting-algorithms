#include <iostream>

using namespace std;

// Structure to represent an element with its original position for stability tracking
struct StableElement {
    int value;
    int originalIndex;
    
    StableElement() : value(0), originalIndex(0) {}
    StableElement(int val, int index) : value(val), originalIndex(index) {}
};

// Function to rotate elements to the right to maintain stability
void rotateElementsRight(int integerArray[], int startPosition, int endPosition) 
{
    cout << "  -> Rotating elements from position " << startPosition << " to " << endPosition << " to maintain stability" << endl;
    
    // Store the element that will be moved to the front
    int elementToMove = integerArray[endPosition];
    cout << "  -> Moving element " << elementToMove << " from position " << endPosition << " to position " << startPosition << endl;
    
    // Shift all elements one position to the right
    for (int shiftIndex = endPosition; shiftIndex > startPosition; shiftIndex--) {
        cout << "    -> Shifting " << integerArray[shiftIndex - 1] << " from position " << (shiftIndex - 1) << " to position " << shiftIndex << endl;
        integerArray[shiftIndex] = integerArray[shiftIndex - 1];
    }
    
    // Place the element at the front
    integerArray[startPosition] = elementToMove;
    cout << "  -> Element " << elementToMove << " successfully placed at position " << startPosition << endl;
    cout << "  -> Rotation completed while preserving relative order of equal elements" << endl;
}

// Function to find the smallest element in the unsorted portion
int findSmallestElementForStableSort(int integerArray[], int startPosition, int endPosition) 
{
    cout << "--- Finding smallest element from position " << startPosition << " to " << endPosition << " for stable sort ---" << endl;
    
    int smallestElementIndex = startPosition;
    int smallestValue = integerArray[smallestElementIndex];
    
    cout << "Starting search with element " << smallestValue << " at position " << smallestElementIndex << " as current smallest" << endl;
    
    // Search for the smallest element
    for (int searchIndex = startPosition + 1; searchIndex <= endPosition; searchIndex++) {
        cout << "Comparing " << integerArray[searchIndex] << " (position " << searchIndex << ") with current smallest " << smallestValue << " (position " << smallestElementIndex << ")";
        
        if (integerArray[searchIndex] < integerArray[smallestElementIndex]) {
            cout << " -> " << integerArray[searchIndex] << " is smaller!" << endl;
            smallestElementIndex = searchIndex;
            smallestValue = integerArray[smallestElementIndex];
            cout << "  -> New smallest element: " << smallestValue << " at position " << smallestElementIndex << endl;
        } else {
            cout << " -> " << smallestValue << " remains the smallest" << endl;
        }
    }
    
    cout << "--- Smallest element identified: " << smallestValue << " at position " << smallestElementIndex << " ---" << endl;
    return smallestElementIndex;
}

// Function to perform one iteration of stable selection sort
void performStableSelectionSortIteration(int integerArray[], int arraySize, int currentIteration) 
{
    cout << "========== STABLE ITERATION " << (currentIteration + 1) << " OF " << (arraySize - 1) << " ==========" << endl;
    cout << "Processing position " << currentIteration << " while maintaining stability" << endl;
    
    // Display current array state
    cout << "Current array state: ";
    for (int displayIndex = 0; displayIndex < arraySize; displayIndex++) {
        if (displayIndex < currentIteration) {
            cout << "[" << integerArray[displayIndex] << "] ";
        } else if (displayIndex == currentIteration) {
            cout << ">" << integerArray[displayIndex] << "< ";
        } else {
            cout << integerArray[displayIndex] << " ";
        }
    }
    cout << endl;
    
    // Find the smallest element in the unsorted portion
    int smallestElementIndex = findSmallestElementForStableSort(integerArray, currentIteration, arraySize - 1);
    
    cout << "Smallest element: " << integerArray[smallestElementIndex] << " at position " << smallestElementIndex << endl;
    
    // Use rotation instead of swapping to maintain stability
    if (smallestElementIndex != currentIteration) {
        cout << "MAINTAINING STABILITY: Using rotation instead of simple swap" << endl;
        cout << "This preserves the relative order of equal elements" << endl;
        
        rotateElementsRight(integerArray, currentIteration, smallestElementIndex);
        
        cout << "Element " << integerArray[currentIteration] << " moved to position " << currentIteration 
             << " while maintaining relative order" << endl;
    } else {
        cout << "Element " << integerArray[currentIteration] << " is already in the correct position - no rotation needed" << endl;
    }
    
    // Display array state after iteration
    cout << "Array after stable iteration " << (currentIteration + 1) << ": ";
    for (int displayIndex = 0; displayIndex < arraySize; displayIndex++) {
        if (displayIndex <= currentIteration) {
            cout << "[" << integerArray[displayIndex] << "] ";
        } else {
            cout << integerArray[displayIndex] << " ";
        }
    }
    cout << endl;
    cout << "----------------------------------------------------------------" << endl;
}

// Main stable selection sort algorithm
void stableSelectionSortAlgorithm(int integerArray[], int arraySize) 
{
    cout << "=============================================" << endl;
    cout << "    STABLE SELECTION SORT ALGORITHM" << endl;
    cout << "=============================================" << endl;
    cout << endl;
    
    cout << "STABILITY EXPLANATION:" << endl;
    cout << "Traditional Selection Sort is NOT stable because it swaps" << endl;
    cout << "non-adjacent elements, which can change the relative order" << endl;
    cout << "of equal elements. Our stable version uses rotation instead" << endl;
    cout << "of swapping to preserve the original relative order." << endl;
    cout << endl;
    
    cout << "Initial array: ";
    for (int displayIndex = 0; displayIndex < arraySize; displayIndex++) {
        cout << integerArray[displayIndex] << " ";
    }
    cout << endl << endl;
    
    // Perform stable selection sort
    for (int iterationIndex = 0; iterationIndex < arraySize - 1; iterationIndex++) {
        performStableSelectionSortIteration(integerArray, arraySize, iterationIndex);
    }
    
    cout << "=============================================" << endl;
    cout << "STABLE SELECTION SORT COMPLETED!" << endl;
    cout << "=============================================" << endl;
    
    cout << "Final sorted array (stable): ";
    for (int displayIndex = 0; displayIndex < arraySize; displayIndex++) {
        cout << "[" << integerArray[displayIndex] << "] ";
    }
    cout << endl;
}

// Function to demonstrate stability with tracked elements
void demonstrateStabilityWithTrackedElements(StableElement trackedArray[], int arraySize) 
{
    cout << endl;
    cout << "=============================================" << endl;
    cout << "      STABILITY DEMONSTRATION" << endl;
    cout << "=============================================" << endl;
    cout << "Each element is shown as (value, original_position)" << endl;
    cout << "This helps visualize if equal elements maintain their relative order" << endl;
    cout << endl;
    
    cout << "Initial array with tracking: ";
    for (int displayIndex = 0; displayIndex < arraySize; displayIndex++) {
        cout << "(" << trackedArray[displayIndex].value << "," << trackedArray[displayIndex].originalIndex << ") ";
    }
    cout << endl << endl;
    
    // Perform stable selection sort on tracked elements
    for (int currentPosition = 0; currentPosition < arraySize - 1; currentPosition++) {
        cout << "Iteration " << (currentPosition + 1) << " - Finding smallest element from position " << currentPosition << endl;
        
        // Find smallest element
        int smallestIndex = currentPosition;
        for (int searchIndex = currentPosition + 1; searchIndex < arraySize; searchIndex++) {
            if (trackedArray[searchIndex].value < trackedArray[smallestIndex].value) {
                smallestIndex = searchIndex;
            }
        }
        
        // Rotate elements to maintain stability
        if (smallestIndex != currentPosition) {
            cout << "Moving (" << trackedArray[smallestIndex].value << "," << trackedArray[smallestIndex].originalIndex 
                 << ") from position " << smallestIndex << " to position " << currentPosition << endl;
            
            StableElement elementToMove = trackedArray[smallestIndex];
            
            // Rotate elements
            for (int rotateIndex = smallestIndex; rotateIndex > currentPosition; rotateIndex--) {
                trackedArray[rotateIndex] = trackedArray[rotateIndex - 1];
            }
            trackedArray[currentPosition] = elementToMove;
        }
        
        cout << "After iteration " << (currentPosition + 1) << ": ";
        for (int displayIndex = 0; displayIndex < arraySize; displayIndex++) {
            cout << "(" << trackedArray[displayIndex].value << "," << trackedArray[displayIndex].originalIndex << ") ";
        }
        cout << endl << endl;
    }
    
    cout << "STABILITY VERIFICATION:" << endl;
    cout << "Check if elements with the same value maintained their relative order" << endl;
    cout << "by comparing their original indices in the final result." << endl;
}

// Function to display array with educational formatting
void displayArrayWithFormatting(int integerArray[], int arraySize, string description) 
{
    cout << endl;
    cout << "=============== " << description << " ===============" << endl;
    cout << "Elements: ";
    
    for (int displayIndex = 0; displayIndex < arraySize; displayIndex++) {
        cout << integerArray[displayIndex];
        if (displayIndex < arraySize - 1) cout << " | ";
    }
    
    cout << endl;
    cout << "Positions: ";
    for (int displayIndex = 0; displayIndex < arraySize; displayIndex++) {
        cout << displayIndex;
        if (displayIndex < arraySize - 1) cout << " | ";
    }
    cout << endl;
    cout << "================================================" << endl;
}

int main() 
{
    cout << "======================================================" << endl;
    cout << "    STABLE SELECTION SORT EDUCATIONAL DEMONSTRATION" << endl;
    cout << "======================================================" << endl;
    cout << endl;
    
    // Test array with duplicate values to demonstrate stability
    int testArray[] = {4, 2, 2, 8, 3, 3, 1};
    int arraySize = sizeof(testArray) / sizeof(int);
    
    cout << "EDUCATIONAL OBJECTIVE:" << endl;
    cout << "This program demonstrates how to make Selection Sort stable" << endl;
    cout << "by using element rotation instead of simple swapping." << endl;
    cout << "This preserves the relative order of equal elements." << endl;
    cout << endl;
    
    displayArrayWithFormatting(testArray, arraySize, "ARRAY BEFORE STABLE SORTING");
    
    stableSelectionSortAlgorithm(testArray, arraySize);
    
    displayArrayWithFormatting(testArray, arraySize, "ARRAY AFTER STABLE SORTING");
    
    // Demonstrate stability with tracked elements
    StableElement trackedElements[] = {
        StableElement(4, 0), StableElement(2, 1), StableElement(2, 2), 
        StableElement(8, 3), StableElement(3, 4), StableElement(3, 5), 
        StableElement(1, 6)
    };
    
    demonstrateStabilityWithTrackedElements(trackedElements, 7);
    
    cout << endl;
    cout << "KEY LEARNING POINTS:" << endl;
    cout << "• Traditional Selection Sort is NOT stable" << endl;
    cout << "• Stability can be achieved using element rotation" << endl;
    cout << "• Rotation preserves relative order of equal elements" << endl;
    cout << "• Time complexity remains O(n²) but with more element movements" << endl;
    cout << "• Space complexity is still O(1) - in-place sorting" << endl;
    cout << "• Trade-off: More operations but maintains stability" << endl;
    cout << "• Useful when the original order of equal elements matters" << endl;
    
    return 0;
}