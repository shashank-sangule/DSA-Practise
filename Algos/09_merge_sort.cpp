#include <iostream>

void printArray(int arr[], int size)
{
    std::cout << "Sorted array: " << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
}


void merge(int arr[],int left,int right)
{
    int mid = left+(right-left)/2;

    int lengthArrayOne = mid - left + 1;
    int lengthArrayTwo = right - mid;

    int* arrayOne = new int[lengthArrayOne];
    int* arrayTwo = new int[lengthArrayTwo]; 

    int mainArrayIndex = left;
    
    for(int i = 0; i < lengthArrayOne; i++)
    {
        arrayOne[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid + 1;
    
    for(int i = 0; i < lengthArrayTwo; i++)
    {
        arrayTwo[i] = arr[mainArrayIndex++];
    }

    int indexArrayOne = 0;
    int indexArrayTwo = 0;
    mainArrayIndex = left;

    while(indexArrayOne < lengthArrayOne && indexArrayTwo < lengthArrayTwo)
    {
        if(arrayOne[indexArrayOne] < arrayTwo[indexArrayTwo])
        {
            arr[mainArrayIndex++] = arrayOne[indexArrayOne++];
        }
        else
        {
            arr[mainArrayIndex++] = arrayTwo[indexArrayTwo++];
        }
    }

    while(indexArrayOne < lengthArrayOne)
    {
        arr[mainArrayIndex++] = arrayOne[indexArrayOne++];
    }

    while(indexArrayTwo < lengthArrayTwo)
    {
        arr[mainArrayIndex++] = arrayTwo[indexArrayTwo++];
    }

    delete[] arrayOne;
    delete[] arrayTwo;
}


void mergeSort(int arr[], int left,int right)
{
    if(left >= right)
    {
        return;
    }

    int mid = left+(right-left)/2;

    mergeSort(arr,left,mid);
    
    mergeSort(arr,mid+1,right);
    
    merge(arr,left,right);
}

int main()
{
    int arr[100];
    int size;
    std::cout << "Enter the size of array: ";
    std::cin >> size;
    for (int i = 0; i < size; i++)
    {
        std::cout << "Enter the value in Array: ";
        std::cin >> arr[i];
    }

    mergeSort(arr, 0, size - 1);
    std::cout << std::endl;
    printArray(arr, size);
    return 0;
}