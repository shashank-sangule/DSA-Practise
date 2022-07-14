/*
Find duplicates in O(n) time and O(1) extra space

Given an array of n elements that contains elements from 0 to n-1, 
with any of these numbers appearing any number of times. 
Find these repeating numbers in O(n) and using only constant memory space.

Example: 

Input : n = 7 and array[] = {1, 2, 3, 6, 3, 6, 1}
Output: 1, 3, 6

Explanation: The numbers 1 , 3 and 6 appears more
than once in the array.

Input : n = 5 and array[] = {1, 2, 3, 4 ,3}
Output: 3

Explanation: The number 3 appears more than once
in the array.

*/

#include <iostream>

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


    for (int i = 0; i < size; i++)
    {
        arr[arr[i]%size] = arr[arr[i]%size] + size;
    }
    
    std::cout << "Duplicate elements are: ";
    for (int i = 0; i < size; i++)
    {
        if(arr[i] >= size *2)
        {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;    

    return 0;
}