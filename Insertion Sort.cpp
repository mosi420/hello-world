/**Insertion sort is a simple sorting algorithm
that works the way we sort playing cards in our hands.**/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int ar[n+5];
    for(int i=0;i<n;i++)cin>>ar[i];
    for(int i=1;i<n;i++){
        int e=ar[i];
        int j=i-1;
        while(j>=0 && ar[j]>e){
            ar[j+1]=ar[j];
            j--;
        }
        ar[j+1]=e;
    }
    for(int i=0;i<n;i++)cout<<ar[i]<<" ";
    cout<<endl;
}
