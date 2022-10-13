#include<bits/stdc++.h>
using namespace std;

void Merge(int arr[], int low, int mid, int high)
{
    int i=low, j=mid+1, k=0, temp[100];
    while(i<=mid && j<=high)
    {
        if(arr[i]<=arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else 
        {
            temp[k] = arr[j];
            j++;
        } 
        k++;
    }
    while(i<=mid)
    {
        temp[k]=arr[i];
        i++;
        k++;
    }
    while(j<=high)
    {
        temp[k]=arr[j];
        j++;
        k++;
    }
    for(i=low;i<=high;i++)
       arr[i]=temp[i-low];
}

void mergeSort(int arr[], int low, int high)
{
    if(low<high)
    {
        int mid = (low + high)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        Merge(arr,low,mid,high);
    }
}

int main()
{
    int arr[100], n, i;
    cout<<"\nEnter the Size of the Array: ";
    cin>>n;
    cout<<"Enter the Elements of the Array:\n";
    for(i=0;i<n;i++)
       cin>>arr[i];
    mergeSort(arr,0,n-1);
    cout<<"The Sorted Array ELements are:\n";
    for(i=0;i<n;i++)
       cout<<arr[i]<<" ";
    return 0;
}