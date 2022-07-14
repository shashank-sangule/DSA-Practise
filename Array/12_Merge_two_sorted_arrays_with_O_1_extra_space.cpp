/*
Merge two sorted arrays with O(1) extra space

We are given two sorted arrays.
We need to merge these two arrays such that the initial numbers (after complete sorting)
are in the first array and the remaining numbers are in the second array.
Extra space is allowed in O(1).

Example:

Input: ar1[] = {10};
       ar2[] = {2, 3};
Output: ar1[] = {2}
        ar2[] = {3, 10}

Input: ar1[] = {1, 5, 9, 10, 15, 20};
       ar2[] = {2, 3, 8, 13};
Output: ar1[] = {1, 2, 3, 5, 8, 9}
        ar2[] = {10, 13, 15, 20}

*/

#include <iostream>
#include <algorithm>

void printArr(int arr[], int size)
{
    std::cout << "Arranged Array: " << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void mergeArray(int arr1[], int arr2[], int size1, int size2)
{
    for (int i = 0; i < size2; i++)
    {
        std::cout << "Enter the value of " << i << " index: ";
        std::cin >> arr2[i];
    }

    for (int i = size2 - 1; i >= 0; i--)
    {
        for (int j = size1 - 1; j >= 0; j--)
        {
            if (arr2[i] < arr1[j])
            {
                std::swap(arr2[i], arr1[j]);
            }
            std::sort(arr1, arr1 + size1);
        }
    }
}

int main()
{
    int arr1[100], arr2[100];
    int size1, size2;
    std::cout << "Enter the size of 1st array: ";
    std::cin >> size1;
    for (int i = 0; i < size1; i++)
    {
        std::cout << "Enter the value of " << i << " index: ";
        std::cin >> arr1[i];
    }

    std::cout << "Enter the size of 2nd array: ";
    std::cin >> size2;

    mergeArray(arr1, arr2, size1, size2);

    printArr(arr1, size1);
    printArr(arr2, size2);

    return 0;
}
