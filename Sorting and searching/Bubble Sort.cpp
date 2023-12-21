#include <iostream>

// Custom swap function
void customSwap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Function to perform bubble sort
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            // Compare adjacent elements
            if (arr[j] > arr[j + 1]) {
                // Swap them if they are in the wrong order
                customSwap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    const int size = 5;
    int arr[size] = {64, 34, 25, 12, 22};

    std::cout << "Original array: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }

    // Perform bubble sort
    bubbleSort(arr, size);

    std::cout << "\nSorted array: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }

    return 0;
}

