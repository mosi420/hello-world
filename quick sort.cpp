#include<bits/stdc++.h>
using namespace std;

int partion(int ar[],int s,int e)
{
    int i=s-1;
    int j=s;
    int pivot=ar[e];
    for(;j<=e-1;j++){
        if(ar[j]<=pivot){
            i+=1;
            swap(ar[i],ar[j]);
        }
    }
    swap(ar[i+1],ar[e]);
    return i+1;
}

void quicksort(int ar[],int s,int e)
{
    if(s>=e)return;
    int p=partion(ar,s,e);
    quicksort(ar,s,p-1);
    quicksort(ar,p+1,e);
}

int main()
{
    int n;
    cin>>n;
    int ar[n+5];
    for(int i=0;i<n;i++)cin>>ar[i];
    quicksort(ar,0,n-1);
    for(int i=0;i<n;i++)cout<<ar[i]<<" ";
    cout<<endl;
}
