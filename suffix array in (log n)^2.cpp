#include<bits/stdc++.h>
using namespace std;

#define MAX 100000
struct entry{
    int tup[2],index;
}ar[MAX];

int Rank[18][MAX],n,step,cnt;
vector<int>suffArray;
long long lcp[MAX];
string str;

int cmp(struct entry a,struct entry b)
{
    return a.tup[0]==b.tup[0]?(a.tup[1]<b.tup[1]?1:0):(a.tup[0]<b.tup[0]?1:0);
}

void build_suff_array(string str)
{
    n=str.size();
    step=0;
    cnt=0;
    for(int i=0;i<n;i++){
        Rank[0][i]=str[i]-'A';
        memset(ar[i].tup,0,sizeof(ar[i].tup));
    }
    for(step=1,cnt=1;cnt>>1<n;step++,cnt<<=1){
        for(int i=0;i<n;i++){
            ar[i].tup[0]=Rank[step-1][i];
            ar[i].tup[1]=i+cnt<n?Rank[step-1][i+cnt]:-1;
            ar[i].index=i;
        }
        sort(ar,ar+n,cmp);
        for(int i=0;i<n;i++)
            Rank[step][ar[i].index]=i>0 && ar[i].tup[0]==ar[i-1].tup[0] && ar[i].tup[1]==ar[i-1].tup[1]?
            Rank[step][ar[i-1].index]:i;
    }
    suffArray.clear();
    for(int i=0;i<n;i++)
        suffArray.push_back(ar[i].index);
}

long long build_LCP_array()
{
    memset(lcp,0,sizeof(lcp));
    int invSuff[n+5];
    for(int i=0;i<n;i++)
        invSuff[suffArray[i]]=i;
    int k=0;
    for(int i=0;i<n;i++){
        if(invSuff[i]==n-1){
            k=0;
            continue;
        }
        int j=suffArray[invSuff[i]+1];
        while(i+k<n && j+k<n && str[i+k]==str[j+k])
            k++;
        lcp[invSuff[i]]=k;
        if(k>0)k--;
    }
    long long sum=0;
    for(int i=0;i<n;i++)
        sum+=lcp[i];
    return sum;
}

int main()
{
    int t;
    cin>>t;
    getchar();
    while(t--){
        cin>>str;
        build_suff_array(str);
        long long sz=str.size();
        long long p=build_LCP_array();
        long long ans=((sz*(sz+1))/2)-p;
        cout<<ans<<endl;
    }
}
