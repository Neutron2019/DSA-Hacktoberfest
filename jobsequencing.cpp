#include<bits/stdc++.h>
using namespace std;
struct Job
{
    char id;
    int deadline;
    int profit;
};

bool comp(struct Job j1, struct Job j2)
{
    return (j1.profit>j2.profit);
}

int min(int a, int b)
{
    return ((a>b)?b:a);
}

void jobcsequencing(struct Job arr[], int n)
{
    sort(arr,arr+n,comp);
    int JobSeq[n];
    bool s[n];
    for(int i=0;i<n;i++)
        s[i] = false;
    for(int i=0;i<n;i++)
    {
        for(int j=min(n,arr[i].deadline)-1;j>=0;j--)
        {
            if(s[j]==false)
            {
                JobSeq[j]=i;
                s[j]=true;
                break;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(s[i])
        {
            cout<<arr[JobSeq[i]].id<<" ";
        }
    }
}

int main()
{
    struct Job arr[] = {{'a',2,100},{'b',1,19},{'c',2,27},{'d',1,25},{'e',3,15}};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"\nFollowing is the maximum profit sequence of Job Sequence: ";
    jobcsequencing(arr,n);
}