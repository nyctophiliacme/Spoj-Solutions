#include<bits/stdc++.h>
#define p 1000000007
using namespace std;
typedef long long ll;
ll input()
{
    ll t=0;
    char ch=getchar();
    while(ch<33)
    ch=getchar();
    while(ch>33)
    {
        t=(t<<3)+(t<<1)+ch-'0';
        ch=getchar();
    }
    return t;
}
vector<vector<ll> > a;
ll b[10005],dp[10005];
stack<ll> st;
void dfs(ll x)
{
	ll s,i;
	s=a[x].size();
	for(i=0;i<s;i++)
	{
		if(!b[a[x][i]]) {b[a[x][i]]=1;dfs(a[x][i]);}
	}
	st.push(x);
}
int main()
{
	ll t,n,x,y,ans,i,e,index,size,src,dest,j;
	t=input();
	while(t--)
	{
		n=input();e=input();src=input();dest=input();
		a.resize(n+1);memset(b,0,n*8+10);memset(dp,0,n*8+10);
		for(i=0;i<e;i++)
		{
			x=input();y=input();a[x].push_back(y);
		}
      	for(i=1;i<=n;i++)
		{
			if(!b[i])
			{
				b[i]=1;dfs(i);
			}
		}
		dp[src]=1;i=0;ll temp;
		while(!st.empty())
		{
			temp=st.top();st.pop();
			size=a[temp].size();
			for(j=0;j<size;j++)
			{
				dp[a[temp][j]]+=dp[temp]%p;
			}
		}
		printf("%lld\n",dp[dest]%p);
		a.clear();
	}
	return 0;
} 
