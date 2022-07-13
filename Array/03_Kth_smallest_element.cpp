/*

Kth smallest element

Given an array arr[] and an integer K where K is smaller than size of array,
the task is to find the Kth smallest element in the given array.
It is given that all array elements are distinct.

Input:
N = 6
arr[] = 7 10 4 3 20 15
K = 3
Output : 7
Explanation :
3rd smallest element in the given
array is 7.

*/

#include <iostream>
#include <queue>
#include <vector>

int main()
{
    int arr[100];
    int size;
    int kMin, kMax;
    int ansMin, ansMax;
    std::cout << "Enter the size of array: ";
    std::cin >> size;
    for (int i = 0; i < size; i++)
    {
        std::cout << "Enter the value of " << i << " index: ";
        std::cin >> arr[i];
    }

    std::cout << "Enter the value of K for minimum: ";
    std::cin >> kMin;
    std::cout << "Enter the value of K for maximum: ";
    std::cin >> kMax;

    std::priority_queue<int> queue;
    for (int i = 0; i < size; i++)
    {
        queue.push(arr[i]);
    }

    for (int i = 0; i < size; i++)
    {
        if (i < kMax - 1)
        {
            queue.pop();
            ansMax = queue.top();
        }
        else if (i < size - kMin)
        {
            queue.pop();
            ansMin = queue.top();
        }
    }

    std::cout << kMin << " Smallest value is: "<< ansMin << std::endl;
    std::cout << kMin << " Largest value is: "<< ansMax << std::endl;

    return 0;
}