#include <iostream>

int linearSearch(int arr[], int size, int key)
{
    int ansIndex = -1;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            ansIndex = i;
            return ansIndex;
        }
    }
    return ansIndex;
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

    int ansIndex = linearSearch(arr, size, key);
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