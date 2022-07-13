/*
Given an array A of size N of integers. Your task is to find the minimum and maximum elements in the array.

Input:
N = 6
A[] = {3, 2, 1, 56, 10000, 167}
Output:
min = 1, max =  10000
*/

#include <iostream>

std::pair<int, int> findMaxMin(int arr[], int size)
{
    int min = INT_MAX;
    int max = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        min = std::min(arr[i], min);
        max = std::max(arr[i], max);
    }
    std::pair<int, int> ans;
    ans.first = min;
    ans.second = max;
    return ans;
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

    std::pair<int, int> ans = findMaxMin(arr, size);
    std::cout << "Minimum value in the Array is: " << ans.first << std::endl;
    std::cout << "Maximum value in the Array is: " << ans.second << std::endl;

    return 0;
}