#include<bits/stdc++.h>
using namespace std;

int swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    return 0;
}

int quickSort(int arr[], int low, int high)
{
    int pivot, i, j, temp;
    if(low<high)
    {
        pivot = low;
        i = low;
        j = high;
        while(i<j)
        {
            while(arr[i]<=arr[pivot] && i<high)
                i++;
            while(arr[j]>arr[pivot])
                j--;
            if(i<j)
                swap(&arr[i],&arr[j]);
        }
        swap(&arr[j],&arr[pivot]);
        quickSort(arr,low,j-1);
        quickSort(arr,j+1,high);
    }
    return 0;
}

int main()
{
    int arr[100],n,i;
    cout<<"Enter the Number of Elements in the Array: ";
    cin>>n;
    cout<<"\nEnter the ELements of the Array:\n";
    for(i=0;i<n;i++)
        cin>>arr[i];
    quickSort(arr,0,n-1);
    cout<<"\nThe ELements of the Array After Sorting:\n";
    for(i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}