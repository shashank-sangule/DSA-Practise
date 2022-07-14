/*
Minimum number of jumps to reach end

Given an array of integers where each element represents the max number of steps that can be made forward from that element.
Write a function to return the minimum number of jumps to reach the end of the array (starting from the first element).
If an element is 0, then we cannot move through that element. If we can’t reach the end, return -1.

Examples:

Input:  arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9}
Output: 3 (1-> 3 -> 8 -> 9)
Explanation: Jump from 1st element to
2nd element as there is only 1 step,
now there are three options 5, 8 or 9.
If 8 or 9 is chosen then the end node 9
can be reached. So 3 jumps are made.

Input:  arr[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
Output: 10
Explanation: In every step a jump is
needed so the count of jumps is 10.

*/

#include <iostream>

int minJump(int arr[], int size)
{
    if (size <= 1)
    {
        return 0;
    }
    if (arr[0] == 0)
    {
        return -1;
    }

    int maxReach = arr[0];
    int step = arr[0];
    int jump = 1;

    for (int i = 1; i < size; i++)
    {
        if (i == size-1)
        {
            return jump;
        }

        maxReach = std::max(maxReach, i + arr[i]);
        step--;

        if (step == 0)
        {
            jump++;

            if (i >= maxReach)
            {
                return -1;
            }

            step = maxReach - i;
        }
    }
    return -1;
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

    int jump = minJump(arr, size);
    std::cout << "JUMP: " << jump << std::endl;
    return 0;
}