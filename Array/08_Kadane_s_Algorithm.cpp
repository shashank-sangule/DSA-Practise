/*
Kadane's Algorithm

Given an array Arr[] of N integers. Find the contiguous sub-array(containing at least one number)
which has the maximum sum and return its sum.


Example 1:

Input:
N = 5
Arr[] = {1,2,3,-2,5}
Output:
9
Explanation:
Max subarray sum is 9
of elements (1, 2, 3, -2, 5) which
is a contiguous subarray.

Example 2:

Input:
N = 4
Arr[] = {-1,-2,-3,-4}
Output:
-1
Explanation:
Max subarray sum is -1
of element (-1)

*/

#include <iostream>

void kadaneAlgo(int arr[], int size, int ans[])
{
    int maxSum = INT_MIN;
    int currSum = 0;
    int start = 0, end = 0, pointer = 0;
    for (int i = 0; i < size; i++)
    {
        currSum += arr[i];
        if (maxSum < currSum)
        {
            maxSum = currSum;
            start = pointer;
            end = i;
        }
        if (currSum < 0)
        {
            currSum = 0;
            pointer = i + 1;
        }
    }
    ans[0] = maxSum;
    ans[1] = start;
    ans[2] = end;
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

    int ans[3];

    kadaneAlgo(arr, size, ans);

    std::cout << "Maximum sum of sub array is: " << ans[0] << std::endl;
    std::cout << "Sub array is: " << std::endl;
    for (int i = ans[1]; i <= ans[2]; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}