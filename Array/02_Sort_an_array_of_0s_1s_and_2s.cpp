/*

Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.


Example 1:

Input:
N = 5
arr[]= {0 2 1 2 0}
Output:
0 0 1 2 2
Explanation:
0s 1s and 2s are segregated
into ascending order.

*/

#include <iostream>

void usingTwoPointer(int arr[], int size)
{
    int left = 0, right = size - 1;
    int pointer = 0;

    while (pointer <= right)
    {
        if (arr[pointer] == 0)
        {
            std::swap(arr[pointer], arr[left]);
            pointer++;
            left++;
        }
        else if (arr[pointer] == 1)
        {
            pointer++;
        }
        else if (arr[pointer] == 2)
        {
            std::swap(arr[pointer], arr[right]);
            right--;
        }
    }
}

void usingMapping(int arr[], int size)
{
    int zeroCount = 0, oneCount = 0, twoCount = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == 0)
        {
            zeroCount++;
        }
        if (arr[i] == 1)
        {
            oneCount++;
        }
        if (arr[i] == 2)
        {
            twoCount++;
        }
    }

    for (int i = 0; i < zeroCount; i++)
    {
        arr[i] = 0;
        std::cout << i << std::endl;
    }
    for (int i = zeroCount; i < (zeroCount + oneCount); i++)
    {
        arr[i] = 1;
        std::cout << i << std::endl;
    }
    for (int i = (zeroCount + oneCount); i < (zeroCount + oneCount + twoCount); i++)
    {
        arr[i] = 2;
        std::cout << i << std::endl;
    }
}

void printArr(int arr[], int size)
{
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

    // usingMapping(arr, size);
    usingTwoPointer(arr, size);
    printArr(arr, size);

    return 0;
}