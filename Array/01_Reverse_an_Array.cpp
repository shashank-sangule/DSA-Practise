/*

Reverse an Array

Given an array A of size N, print the reverse of it.

Example:

Input:
1
4
1 2 3 4
Output:
4 3 2 1

*/

#include <iostream>

void reverse(int arr[], int size)
{
    int start = 0,
        end = size - 1;
    for (int i = 0; i < size; i++)
    {
        if (start < end)
        {
            std::swap(arr[start], arr[end]);
            start++;
            end--;
        }
        else
        {
            break;
        }
    }
}

void printArr(int arr[], int size)
{
    std::cout << "Reversed Array: " << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    int arr[100];
    int size;
    std::cout << "Enter the size of array: ";
    std::cin >> size;
    for (int i = 0; i < size; i++)
    {
        std::cout << "Enter the value of " << i << " index: ";
        std::cin >> arr[i];
    }

    reverse(arr, size);
    printArr(arr, size);

    return 0;
}