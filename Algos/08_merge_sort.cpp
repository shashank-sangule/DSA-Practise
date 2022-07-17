#include <iostream>

void printArray(int arr[], int size)
{
    std::cout << "Sorted array: " << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
}

void merge(int arr[], int startIndex, int midIndex, int lastIndex)
{
    int size = lastIndex - startIndex + 1;
    int *newArray = new int[size];

    int newArrayIndex = 0;
    int firstArrayIndex = startIndex;
    int secondArrayIndex = midIndex + 1;

    while (firstArrayIndex <= midIndex && secondArrayIndex <= lastIndex)
    {
        if (arr[firstArrayIndex] <= arr[secondArrayIndex])
        {
            newArray[newArrayIndex] = arr[firstArrayIndex];
            newArrayIndex++;
            firstArrayIndex++;
        }
        else
        {
            newArray[newArrayIndex] = arr[secondArrayIndex];
            newArrayIndex++;
            secondArrayIndex++;
        }
    }

    while (firstArrayIndex <= midIndex)
    {
        newArray[newArrayIndex] = arr[firstArrayIndex];
        newArrayIndex++;
        firstArrayIndex++;
    }

    while (secondArrayIndex <= lastIndex)
    {
        newArray[newArrayIndex] = arr[secondArrayIndex];
        newArrayIndex++;
        secondArrayIndex++;
    }

    int j = startIndex;
    for (int i = 0; i < size; i++)
    {
        std::cout<<newArray[i]<<std::endl;
        arr[j] = newArray[i];
        j++;
    }
}

void mergeSort(int arr[], int startIndex, int LastIndex)
{
    // base case
    if (startIndex >= LastIndex)
    {
        return;
    }
    std::cout << std::endl;
    // printArray(arr,LastIndex+1);
    int midIndex = startIndex + (LastIndex - startIndex) / 2;
    mergeSort(arr, startIndex, midIndex);
    mergeSort(arr, midIndex + 1, LastIndex);
    merge(arr, startIndex, midIndex, LastIndex);
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

    mergeSort(arr, 0, size - 1);
    std::cout << std::endl;
    printArray(arr, size);
    return 0;
}