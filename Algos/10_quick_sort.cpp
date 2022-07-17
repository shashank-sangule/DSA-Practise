#include <iostream>

void printArray(int arr[], int size)
{
    std::cout << "Sorted array: " << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
}

int partition(int arr[], int left, int right)
{
    int pivotIndex = left + (right - left) / 2;
    int countSmall = 0;
    for (int i = 0; i <= right; i++)
    {
        if (arr[pivotIndex] > arr[i])
        {
            countSmall++;
        }
    }
    std::swap(arr[pivotIndex], arr[countSmall]);

    pivotIndex = countSmall;
    int i = left, j = right;

    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] <= arr[pivotIndex])
        {
            i++;
        }
        while (arr[j] > arr[pivotIndex])
        {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex)
        {
            std::swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}

void quickSort(int arr[], int left, int right)
{
    // base case
    if (left > right)
    {
        return;
    }
    int pivot = partition(arr, left, right);
    quickSort(arr, left, pivot - 1);
    quickSort(arr, pivot + 1, right);
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

    quickSort(arr, 0, size - 1);
    std::cout << std::endl;
    printArray(arr, size);
    return 0;
}