#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
typedef long long ll;
ll ans,ind,b[60000];
vector<vector<pair<ll,ll> > >a;
void dfs(ll x,ll w)
{
	ll size,i;
	if(w>ans)
	{
		ans=w;ind=x;
	}
	size=a[x].size();
	for(i=0;i<size;i++)
	{
		if(!b[a[x][i].first]) {b[a[x][i].first]=1;dfs(a[x][i].first,a[x][i].second+w);}
	}
}
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
int main()
{
	ll t,n,i,u,v,w;
	t=input();
	while(t--)
	{
		n=input();
		a.resize(n+1);
		for(i=0;i<n-1;i++)
		{
			u=input();v=input();w=input();
			a[u].push_back(mp(v,w));a[v].push_back(mp(u,w));
		}
		memset(b,0,sizeof(b));ans=0;ind=0;
		for(i=1;i<=n;i++)
		{
			if(!b[i]) {b[i]=1;dfs(i,0);}
		}
		memset(b,0,sizeof(b));
		dfs(ind,0);
		printf("%lld\n",ans);
		a.clear();
	}
} 
