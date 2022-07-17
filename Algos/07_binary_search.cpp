#include <iostream>
#include <algorithm>

int binarySearch(int arr[], int left, int right, int key)
{
    if (left <= right)
    {
        int mid = left + (right - left) / 2;
        // base case
        if (arr[mid] == key)
        {
            return mid;
        }

        if (arr[mid] > key)
        {
            return binarySearch(arr, left, mid - 1, key);
        }

        return binarySearch(arr, mid + 1, right, key);
    }

    return -1;
}

int main()
{
    int arr[100];
    int size, key;
    std::cout << "Enter the size of array: ";
    std::cin >> size;
    for (int i = 0; i < size; i++)
    {
        std::cout << "Enter the value in Array: ";
        std::cin >> arr[i];
    }

    std::cout << "Enter the key to be searched in the array: ";
    std::cin >> key;

    std::sort(arr, arr + size);
    int ansIndex = binarySearch(arr, 0, size - 1, key);
    if (ansIndex == -1)
    {
        std::cout << std::endl
                  << "Searched Key is not present in the array." << std::endl;
    }
    else
    {
        std::cout << std::endl
                  << "Searched Key is present in the array at index: " << ansIndex << std::endl;
    }

    return 0;
}