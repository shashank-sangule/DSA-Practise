/*

Cyclically rotate an array by one

Given an array, rotate the array by one position in clock-wise direction.


Example 1:

Input:
N = 5
A[] = {1, 2, 3, 4, 5}
Output:
5 1 2 3 4


Example 2:

Input:
N = 8
A[] = {9, 8, 7, 6, 4, 2, 1, 3}
Output:
3 9 8 7 6 4 2 1

*/

#include <iostream>

void printArr(int arr[], int size)
{
    std::cout << "Reversed Array: " << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void rotate(int arr[], int size)
{
    int temp = arr[size-1];
    for (int i = size-1; i > 0; i--)
    {
        arr[i] = arr[i-1];
    }
    std::cout << std::endl;
    arr[0] = temp;    
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

    rotate(arr, size);
    printArr(arr, size);

    return 0;
}