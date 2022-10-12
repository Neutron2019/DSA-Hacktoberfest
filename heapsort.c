#include<bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    if(left<n && arr[left]>arr[largest])
        largest = left;
    if(right<n && arr[right]>arr[largest])
        largest = right;
    if(largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr,n,largest);
    }
}

void heapSort(int arr[], int n)
{
    int i = (n/2)-1;
    while(i>=0)
    {
        heapify(arr,n,i);
        i--;
    }
    i=n-1;
    while(i>=0)
    {
        int temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;
        heapify(arr,i,0);
        i--;
    }
}

int main()
{
    int arr[100], n, i;
    cout<<"\nEnter the Number of Elements in the Array: ";
    cin>>n;
    cout<<"\nEnter the Elements of the Array:\n";
    for(i=0;i<n;i++)
        cin>>arr[i];
    heapSort(arr,n);
    cout<<"\nThe Sorted Elements of the Array are:\n";
    for(i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}
