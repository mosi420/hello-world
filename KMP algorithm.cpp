#include<bits/stdc++.h>
using namespace std;

int lps[1000005];

void lps_array(string pattern)
{
    int n=pattern.length();
    memset(lps,0,sizeof(lps));
    int index=0;
    for(int i=1; i<n; ){
        if(pattern[index] == pattern[i]){
            lps[i]=index+1;
            index++;i++;
        }
        else{
            if(index!=0)index=lps[index-1];
            else{
                lps[i]=0;
                i++;
            }
        }
    }
}

int kmp(string text,string pattern)
{
    lps_array(pattern);
    int i=0,j=0,cnt=0;
    ///i->text,j->pattern
    while(i<text.length()){
        if(text[i]==pattern[j]){
            i++;j++;
        }
        else{
            if(j!=0)j=lps[j-1];
            else{
                i++;
            }
        }
        if(j==pattern.length())cnt++;
    }
    return cnt;
}

int main()
{
    string text,pattern;
    cin>>text>>pattern;
    cout<<kmp(text,pattern)<<endl;
}
/**int kmp(string s,string t)
{
	f[0]=0;
	int m=t.size(),cnt=0;
	for (int i=1,k=0;i<m;i++)
	{
		while(k>0&&t[k]!=t[i])k=f[k-1];
		if(t[i]==t[k])k++;
		f[i]=k;
	}
	for (int i=0,k=0;i<n;i++)
	{
		while (k>0 && t[k]!=s[i])k=f[k-1];
		if (s[i]==t[k])k++;
		//d[i]=k;
		if (k==m){
            cnt++;
            k=f[k-1];
		}
	}
	return cnt;
}**/
