#include <iostream>

// Function to perform linear search
int linearSearch(const int arr[], int size, int target) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            return i;  // Element found, return its index
        }
    }

    return -1;  // Element not found
}

int main() {
    const int size = 5;
    int arr[size] = {10, 20, 30, 40, 50};

    int target;
    std::cout << "Enter the element to search: ";
    std::cin >> target;

    int result = linearSearch(arr, size, target);

    if (result != -1) {
        std::cout << "Element found at index " << result << std::endl;
    } else {
        std::cout << "Element not found in the array." << std::endl;
    }

    return 0;
}

