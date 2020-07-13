#include<bits/stdc++.h>
using namespace std;

void merge(int ar[],int s,int e)
{
    int mid=(s+e)/2;
    int i=s;
    int j=mid+1;
    int k=s;
    int temp[100005];
    while(i<=mid && j<=e){
        if(ar[i]<ar[j]){
            temp[k]=ar[i];
            i++;k++;
        }
        else{
            temp[k]=ar[j];
            j++;
            k++;
        }
    }
    while(i<=mid){
        temp[k]=ar[i];
        i++;
        k++;
    }
    while(j<=e){
        temp[k]=ar[j];
        k++;
        j++;
    }
    for(int i=s;i<=e;i++)
        ar[i]=temp[i];
}

void merge_sort(int ar[],int s,int e)
{
    if(s>=e)return;
    int mid=(s+e)/2;
    merge_sort(ar,s,mid);
    merge_sort(ar,mid+1,e);
    merge(ar,s,e);
}

int main()
{
    int n;
    cin>>n;
    int ar[n+5];
    for(int i=0;i<n;i++)cin>>ar[i];
    merge_sort(ar,0,n-1);
    for(int i=0;i<n;i++)cout<<ar[i]<<" ";
    cout<<endl;
}
