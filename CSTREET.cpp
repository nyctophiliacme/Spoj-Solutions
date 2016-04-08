#include<bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
#define mp make_pair
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
struct cmp
{
    bool operator()(pp const& a,pp const& b) const
    {
        return a.second>b.second;
    }
};
priority_queue<pp,vector<pp>,cmp> pq;
int main()
{
ll t,ans,p,n,e,i,u,v,w,s,size;
t=input();
while(t--)
{
	p=input();n=input();e=input();
	vector<vector < pp > > adj(n+1);
	for(i=0;i<e;i++)
    {
        u=input();v=input();w=input();
        adj[u].push_back(mp(v,w));
        adj[v].push_back(mp(u,w));
    }
    ll key[n+1],mark[n+1],par[n+1];
    memset(mark,0,sizeof(mark));
    for(i=0;i<=n;i++) key[i]=INT_MAX;
    s=1;
    key[s]=0;par[s]=-1;
    pq.push(mp(s,key[s]));
	while(!pq.empty())
	{
		u=pq.top().first;
		mark[u]=1;
		pq.pop();
		size=adj[u].size();
		for(i=0;i<size;i++)
		{
			v=adj[u][i].first;w=adj[u][i].second;
			if(key[v]>w&&key[u]!=INT_MAX&&!mark[v])
			{
				key[v]=w;par[v]=u;
				pq.push(mp(v,key[v]));
			}
		}	
	}	
	ans=0;
	for(i=1;i<=n;i++)
	{
		ans+=key[i];//cout<<i<<"\t"<<par[i]<<"\t"<<key[i]<<"\n";
	}
	ans*=p;
	printf("%lld\n",ans);
}
} 
