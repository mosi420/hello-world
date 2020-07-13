/**
The selection sort algorithm sorts an array by repeatedly finding
the minimum element (considering ascending order) from unsorted part
and putting it at the beginning. The algorithm maintains two subarrays
in a given array.

1) The subarray which is already sorted.
2) Remaining subarray which is unsorted.
**/


#include<bits/stdc++.h>
using namespace std;

int main()
{
     int n;
     cin>>n;
     int ar[n+5];
     for(int i=0;i<n;i++)cin>>ar[i];
     for(int i=0;i<n-1;i++){
        int minn=10000000,pos;
        for(int j=i;j<n;j++){
            if(minn>ar[j]){
                minn=ar[j];
                pos=j;
            }
        }
        swap(ar[i],ar[pos]);
     }
     for(int i=0;i<n;i++)cout<<ar[i]<<" ";
     cout<<endl;
}
