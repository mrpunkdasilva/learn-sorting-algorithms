#include <iostream>

using namespace std;

// Helper function to display the array
void displayArray(int arr[], int size, const string& message = "") {
    if (!message.empty()) {
        cout << message;
    }
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Main Insertion Sort algorithm function
void insertionSortAlgorithm(int arr[], int size) {
    cout << "========================================" << endl;
    cout << "STARTING INSERTION SORT ALGORITHM" << endl;
    cout << "========================================" << endl;
    cout << "Initial array: ";
    displayArray(arr, size);
    cout << endl;

    int totalShifts = 0; // Counter for shifts (similar to swaps)

    // Iterate through the array starting from the second element
    for (int i = 1; i < size; ++i) {
        cout << ">>> ITERATION " << i << " <<<" << endl;
        int key = arr[i]; // Element to be inserted into the sorted part
        int j = i - 1;    // Last element of the already sorted part

        cout << "Element to be inserted (key): " << key << " (position " << i << ")" << endl;
        cout << "Comparing " << key << " with elements to its left..." << endl;

        // Move elements of arr[0..i-1] that are greater than key
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            cout << "  -> " << arr[j] << " (position " << j << ") is greater than " << key << ". Shifting to position " << (j + 1) << endl;
            arr[j + 1] = arr[j];
            j = j - 1;
            totalShifts++;
            displayArray(arr, size, "     Current array state: ");
        }
        // Insert key into its correct position
        if (j + 1 != i) { // Check if a shift occurred
            cout << "  -> Inserting " << key << " at position " << (j + 1) << endl;
        } else {
            cout << "  -> " << key << " is already in correct position (position " << (j + 1) << "), no shift needed." << endl;
        }
        arr[j + 1] = key;
        displayArray(arr, size, "Array state after iteration " + to_string(i) + ": ");
        cout << "--------------------------------" << endl;
        cout << endl;
    }

    cout << "========================================" << endl;
    cout << "INSERTION SORT ALGORITHM COMPLETED!" << endl;
    cout << "Total shifts: " << totalShifts << endl;
    cout << "========================================" << endl;
}

int main() {
    cout << "===========================================" << endl;
    cout << "    INSERTION SORT ALGORITHM DEMONSTRATION" << endl;
    cout << "===========================================" << endl;
    cout << endl;

    int numbersArray[] = {64, 34, 25, 12, 22, 11, 90, 88, 76, 50};
    int arraySize = sizeof(numbersArray) / sizeof(numbersArray[0]);

    cout << "ALGORITHM EXPLANATION:" << endl;
    cout << "Insertion Sort builds the final sorted array one item at a time." << endl;
    cout << "It iterates over the array, taking each element and inserting it into" << endl;
    cout << "the correct position within the already sorted part of the array." << endl;
    cout << endl;

    cout << "Array before sorting:";
    displayArray(numbersArray, arraySize);

    insertionSortAlgorithm(numbersArray, arraySize);

    cout << "Array after sorting:";
    displayArray(numbersArray, arraySize);

    cout << endl;
    cout << "IMPORTANT OBSERVATIONS:" << endl;
    cout << "- The algorithm is efficient for small datasets." << endl;
    cout << "- It is very efficient for nearly sorted data." << endl;
    cout << "- It is a stable sorting algorithm (maintains the relative order of equal elements)." << endl;
    cout << "- Time complexity: O(n²) in worst and average case, O(n) in best case." << endl;
    cout << "- It is an in-place algorithm (requires minimal additional memory space)." << endl;

    return 0;
}
