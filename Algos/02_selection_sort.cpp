#include<iostream>

void selectionSort(int arr[],int size)
{
    int minIndex;
    for (int i = 0; i < size; i++)
    {
        minIndex = i;
        for (int j = i+1; j < size; j++)
        {
            if (arr[j]<arr[minIndex])
            {
                minIndex = j;
            }
        }
        std::swap(arr[minIndex],arr[i]);
    }
}

void printArray(int arr[], int size) {
    std::cout<<"Sorted array: "<<std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i]<<" ";
    }
    
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

    selectionSort(arr, size);
    printArray(arr,size);
    return 0;   
}