/*
Union of two arrays

Given two arrays a[] and b[] of size n and m respectively. The task is to find union between these two arrays.

Union of the two arrays can be defined as the set containing distinct elements from both the arrays. If there are repetitions, then only one occurrence of element should be printed in the union.

Example 1:

Input:
5 3
1 2 3 4 5
1 2 3
Output:
5
Explanation:
1, 2, 3, 4 and 5 are the
elements which comes in the union set
of both arrays. So count is 5.

*/

#include <iostream>
#include <algorithm>

void printArr(int arr[], int size)
{
    std::cout << "Answer Array: " << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

std::pair<int*, int> unionArr(int arr1[], int arr2[], int size1, int size2)
{
    int *result = new int[size1 + size2];

    int pointerResult = 0;
    int pointerArr1 = 0;
    int pointerArr2 = 0;

    while (pointerArr1 < size1 && pointerArr2 < size2)
    {
        if (arr1[pointerArr1] < arr2[pointerArr2])
        {
            if (pointerResult != 0 && arr1[pointerArr1] == result[pointerResult - 1])
            {
                pointerArr1++;
            }
            else
            {
                result[pointerResult] = arr1[pointerArr1];
                pointerArr1++;
                pointerResult++;
            }
        }
        else
        {
            if (pointerResult != 0 && arr2[pointerArr2] == result[pointerResult - 1])
            {
                pointerArr2++;
            }
            else
            {
                result[pointerResult] = arr2[pointerArr2];
                pointerArr2++;
                pointerResult++;
            }
        }
    }

    while (pointerArr1 < size1)
    {
        if (pointerResult != 0 && arr1[pointerArr1] == result[pointerResult - 1])
        {
            pointerArr1++;
        }
        else
        {
            result[pointerResult] = arr1[pointerArr1];
            pointerArr1++;
            pointerResult++;
        }
    }

    while (pointerArr2 < size2)
    {
        if (pointerResult != 0 && arr2[pointerArr2] == result[pointerResult - 1])
        {
            pointerArr2++;
        }
        else
        {
            result[pointerResult] = arr2[pointerArr2];
            pointerArr2++;
            pointerResult++;
        }
    }

    std::pair<int*, int> ans;
    ans.first = result;
    ans.second = pointerResult;
    // delete[] result;
    return ans;
}

std::pair<int*, int> intersition(int arr1[], int arr2[], int size1, int size2)
{
    int *result = new int[size1 + size2];

    int pointerResult = 0;
    int pointerArr1 = 0;
    int pointerArr2 = 0;

    while (pointerArr1 < size1 && pointerArr2 < size2)
    {
        if(arr1[pointerArr1] < arr2[pointerArr2])
        {
            pointerArr1++;
        }
        else if(arr2[pointerArr2] < arr1[pointerArr1])
        {
            pointerArr2++;
        }
        else
        {
            if(pointerResult != 0 && arr1[pointerArr1] == result[pointerResult - 1])
            {
                pointerArr1++;
                pointerArr2++;
            }
            else
            {
                result[pointerResult] = arr1[pointerArr1];
                pointerArr1++;
                pointerArr2++;
                pointerResult++;
            }
        }
    }
    std::pair<int*, int> ans;
    ans.first = result;
    ans.second = pointerResult;
    // delete[] result;
    return ans;
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
    for (int i = 0; i < size2; i++)
    {
        std::cout << "Enter the value of " << i << " index: ";
        std::cin >> arr2[i];
    }

    std::sort(arr1, arr1+size1);
    std::sort(arr2, arr2+size2);

    std::pair<int*, int> ans = unionArr(arr1, arr2, size1, size2);
    printArr(ans.first, ans.second);
    std::pair<int*, int> ans1 = intersition(arr1, arr2, size1, size2);
    printArr(ans1.first, ans1.second);

    return 0;
}