#include<bits/stdc++.h>
using namespace std;

int cnt[100000];

int main()
{
    int n,minn=100000,maxx=-100000;
    cin>>n;
    int ar[n+5];
    for(int i=1;i<=n;i++){
        cin>>ar[i];
        minn=min(minn,ar[i]);
        maxx=max(maxx,ar[i]);
    }
    for(int i=1;i<=n;i++)cnt[ar[i]-minn]++;
    for(int i=1;i<maxx-minn+1;i++)
        cnt[i]+=cnt[i-1];
    int output[100000];
    for(int i=n;i>=1;i--){
        output[cnt[ar[i]-minn]]=ar[i];
        cnt[ar[i]-minn]--;
    }
    for(int i=1;i<=n;i++)cout<<output[i]<<" ";
    cout<<endl;
}
