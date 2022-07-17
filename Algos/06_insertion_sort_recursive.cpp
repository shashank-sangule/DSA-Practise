#include <iostream>

void printArray(int arr[], int size)
{
    std::cout << "Sorted array: " << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
}

void insertionSort(int arr[], int size)
{
    // base case
    if (size == 1)
    {
        return;
    }

    insertionSort(arr, size - 1);

    int temp = arr[size - 1];
    int j = size - 2;
    while (j >= 0 && arr[j] > temp)
    {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = temp;
}

int main()
{
    int arr[100];
    int size;
    std::cout << "Enter the size of array: ";
    std::cin >> size;
    for (int i = 0; i < size; i++)
    {
        std::cout << "Enter the value in Array: ";
        std::cin >> arr[i];
    }

    insertionSort(arr, size);
    printArray(arr, size);
    return 0;
}