/*
Largest Sum Contiguous Subarray

Write an efficient program to find the sum of the contiguous subarray within a one-dimensional array of numbers 
that has the largest sum.

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

#include<iostream>

int main()
{
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int size = 8;
    int maxSum = INT_MIN, currMax = 0;

    for (int i = 0; i < size; i++)
    {
        currMax += arr[i];
        if (maxSum < currMax)
        {
            maxSum = currMax;
        }
        if (currMax < 0)
        {
            currMax = 0;
        }
    }

    std::cout << "Largest Sum of Contiguous sub-array is: " << maxSum << std::endl;
    
}