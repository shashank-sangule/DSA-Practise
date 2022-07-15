#include<iostream>

void bubbleSort(int arr[],int size)
{
    //base case 
    if(size == 0 || size == 1)
    {
        return;
    }

    for (int i = 0; i < size-1; i++)
    {
        std::swap(arr[i],arr[i+1]);
    }
    bubbleSort(arr,size-1);
    
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

    bubbleSort(arr, size);
    printArray(arr,size);
    return 0;   
}