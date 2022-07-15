/*
Next Permutation

Implement the next permutation, 
which rearranges the list of numbers into Lexicographically next greater permutation of list of numbers. 
If such arrangement is not possible, it must be rearranged to the lowest possible order i.e. sorted in an ascending order. 
You are given an list of numbers arr[ ] of size N.

Example 1:

Input: N = 6
arr = {1, 2, 3, 6, 5, 4}
Output: {1, 2, 4, 3, 5, 6}
Explaination: The next permutation of the
given array is {1, 2, 4, 3, 5, 6}.
Example 2:

Input: N = 3
arr = {3, 2, 1}
Output: {1, 2, 3}
Explaination: As arr[] is the last
permutation. So, the next permutation
is the lowest one.

*/

#include <iostream>

void rev(int arr[], int size, int i)
{
    int start = i;
    int end = size - 1;
    while (start < end)
    {
        std::swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void nextPermutation(int arr[], int size)
{
    int i,j;
    for(i = size - 1; i> 0; i-- )
    {
        if(arr[i-1]<arr[i]) 
        break;
    }
    if(i < 0)
    {
        rev(arr,size,0);
    }
    else
    {
        for(j=size-1;j > i;j--)
        {
            if(arr[i-1]<arr[j])
            break;
        }
        std::swap(arr[i-1],arr[j]);
        rev(arr,size,i);
    }
}

void printArr(int arr[], int size)
{
    std::cout << "Next permutation of Array: " << std::endl;
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

    for (int i = 0; i < 24; i++)
    {
        nextPermutation(arr, size);
        printArr(arr,size);
    }
    

    

    return 0;
}