#include<bits/stdc++.h>
using namespace std;
void binarySearch(int arr[],int lb,int ub,int val)
{
    int pos = -1,i,mid;
    for(i=0;lb<=ub;i++)
    {
        mid = (lb + ub)/2;
        if(val<arr[mid])
            ub = mid - 1;
        else if(val>arr[mid])
            lb = mid + 1;
        else
        {
            pos = mid;
            break;
        }
    }
    if(pos==-1)
        cout<<"\nThe Element is Not Found!";
    else
        cout<<"\nThe Element is Found At Position = "<<pos; 
}

int main()
{
    int arr[100],n,i,val;
    cout<<"\nEnter The Number Of ELements in the Array: ";
    cin>>n;
    cout<<"\nEnter The Elements of the Array:\n";
    for(i=0;i<n;i++)
       cin>>arr[i];
    sort(arr,arr+n);
    cout<<"ELements Before Searching:\n";
    for(i=0;i<n;i++)
       cout<<arr[i]<<" ";
    cout<<"\nEnter The ELement To Be Searched: ";
    cin>>val;
    binarySearch(arr,0,n-1,val);
    return 0;
}