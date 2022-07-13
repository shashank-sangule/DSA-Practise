/*
Move all negative elements to end

Given an unsorted array arr[] of size N having both negative and positive integers.
The task is place all negative element at the end of array without changing
the order of positive element and negative element.

Example 1:

Input :
N = 8
arr[] = {1, -1, 3, 2, -7, -5, 11, 6 }
Output :
1  3  2  11  6  -1  -7  -5
*/

#include <iostream>
#include <queue>

void usingPq(int arr[], int size)
{
    std::priority_queue<int> pq;
    for (int i = 0; i < size; i++)
    {
        pq.push(arr[i]);
    }
    for (int i = 0; i < size; i++)
    {
        arr[i] = pq.top();
        pq.pop();
    }
}

void negativeElement(int arr[], int size)
{
    int position = (size - 1), temp = 0;
    for (int i = (size - 1); i >= 0; i--)
    {
        if (arr[i] < 0)
        {
            temp = arr[i];
            for (int j = i; j < position; j++)
            {
                arr[j] = arr[j + 1];
            }
            arr[position] = temp;
            position--;
        }
    }
}

void printArr(int arr[], int size)
{
    std::cout << "Arranged Array: " << std::endl;
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

    // negativeElement(arr, size);
    usingPq(arr, size);
    printArr(arr, size);

    return 0;
}