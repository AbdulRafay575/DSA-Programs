#include <iostream>

// Function to perform selection sort
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        // Find the index of the minimum element in the unsorted region
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap the found minimum element with the first element in the unsorted region
        std::swap(arr[i], arr[minIndex]);
    }
}

int main() {
    const int size = 5;
    int arr[size] = {64, 25, 12, 22, 11};

    std::cout << "Original array: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }

    // Perform selection sort
    selectionSort(arr, size);

    std::cout << "\nSorted array: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }

    return 0;
}

