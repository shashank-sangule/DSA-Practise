/*
Minimize the Heights

Given an array arr[] denoting heights of N towers and a positive integer K.

For each tower, you must perform exactly one of the following operations exactly once.

Increase the height of the tower by K.
Decrease the height of the tower by K ( you can do this operation only if the height of the tower is greater than or equal to K)
Find out the minimum possible difference between the height of the shortest and tallest towers after you have modified each tower.

You can find a slight modification of the problem here.
Note: It is compulsory to increase or decrease the height by K for each tower.


Example 1:

Input:
K = 2, N = 4
Arr[] = {1, 5, 8, 10}
Output:
5
Explanation:
The array can be modified as
{3, 3, 6, 8}. The difference between
the largest and the smallest is 8-3 = 5.
Example 2:

Input:
K = 3, N = 5
Arr[] = {3, 9, 12, 16, 20}
Output:
11
Explanation:
The array can be modified as
{6, 12, 9, 13, 17}. The difference between
the largest and the smallest is 17-6 = 11.

*/

#include <iostream>
#include <algorithm>

int minHeight(int arr[], int size, int key)
{
    std::sort(arr, arr + size);
    int ans = arr[size - 1] - arr[0];

    int tempMin = arr[0];
    int tempMax = arr[size - 1];

    for (int i = 1; i < size; i++)
    {
        if (arr[i] - key < 0)
        {
            continue;
        }

        tempMin = std::min(arr[0] + key, arr[i] - key);
        tempMax = std::max(arr[i - 1] + key, arr[size - 1] - key);

        ans = std::min(ans, tempMax - tempMin);
    }
    return ans;
}

int main()
{
    int arr[100];
    int size, key;
    std::cout << "Enter the size of array: ";
    std::cin >> size;
    for (int i = 0; i < size; i++)
    {
        std::cout << "Enter the value of " << i << " index: ";
        std::cin >> arr[i];
    }

    std::cout << "Enter the value of Key: ";
    std::cin >> key;

    int ans = minHeight(arr, size, key);
    std::cout << "Minimum possible height of towers is: " << ans << std::endl;

    return 0;
}