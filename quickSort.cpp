#include<iostream>
using namespace std;

void printArray(int *arr , int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int partition(int *arr , int s , int e)
{
    int pivot = arr[0];
    int count = 0;
    for(int i=s+1;i<e;i++)
    {
        if(arr[i] < pivot)
        {
            count++;
        }
    }

    // Find the right index of the pivot
    int pivotIndex = s + count;

    // Putting pivot's value at the right index
    swap(arr[pivotIndex] , arr[s]);

    // Now put the small vales at left side of pivot and large value at the right part of the array
    int i = s, j = e;
    while(pivotIndex > i && pivotIndex < e)
    {
        while(arr[i] <= pivot)
        {
            i++;
        }
        while(arr[j] > pivot)
        {
            j--;
        }
        if (pivotIndex > i && pivotIndex < e)
        {
            swap(arr[i++] , arr[j--]);
        }
    }
    return pivotIndex;
}

void quickSort(int *arr , int s , int e)
{
    // Base Case
    if(s >= e)
    {
        return ;
    }
    // put partition in a variable
    int p = partition(arr , s , e);

    // Apply quick sort on left part
    quickSort(arr , s , p-1);

    // Apply quick sort on right part
    quickSort(arr , p+1 , e);
}

int main()
{
    int len;
    cout<<"Enter the size of the array: "<<endl;
    cin>>len;
    int *arr = new int[len];
    cout<<"Enter the array elements: "<<endl;
    for(int i=0;i<len;i++)
    {
        cin>>arr[i];
    }
    quickSort(arr , 0 , len - 1);
    printArray(arr , len);
    return 0;
}