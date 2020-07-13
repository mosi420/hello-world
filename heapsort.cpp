#include<bits/stdc++.h>
using namespace std;

void heapify(int ar[],int n,int i)
{
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n && ar[l]>ar[largest])
        largest=l;
    if(r<n && ar[r]>ar[largest])
        largest=r;
    if(largest!=i){
        swap(ar[i],ar[largest]);
        heapify(ar,n,largest);
    }
}

void heapSort(int ar[],int n)
{
    for(int i=n/2-1;i>=0;i--)
        heapify(ar,n,i);
    for(int i=n-1;i>=0;i--){
        swap(ar[0],ar[i]);
        heapify(ar,i,0);
    }
}

int main()
{
    int n;
    cin>>n;
    int ar[n+5];
    for(int i=0;i<n;i++)cin>>ar[i];
    heapSort(ar,n);
    for(int i=0;i<n;i++)cout<<ar[i]<<" ";
    cout<<endl;
}
