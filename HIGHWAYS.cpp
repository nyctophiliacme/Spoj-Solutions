#include<bits/stdc++.h>
using namespace std;
#define pp pair<ll,ll>
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
	ll t,n,e,i,u,v,w,s,size,d;
	t=input();
	while(t--)
	{
	n=input();e=input();s=input();d=input();
	vector<vector < pp > > adj(n+1);
	for(i=0;i<e;i++)
    {
        u=input();v=input();w=input();
        adj[u].push_back(mp(v,w));
        adj[v].push_back(mp(u,w));
    }
    ll dist[n+1],mark[n+1];
    memset(mark,0,sizeof(mark));
    for(i=0;i<=n;i++) dist[i]=INT_MAX;
    dist[s]=0;
    pq.push(mp(s,dist[s]));
	while(!pq.empty())
	{
		u=pq.top().first;
		mark[u]=1;
		pq.pop();
		size=adj[u].size();
		for(i=0;i<size;i++)
		{
			v=adj[u][i].first;w=adj[u][i].second;
			if(dist[v]>dist[u]+w&&dist[u]!=INT_MAX&&!mark[v])
			{
				dist[v]=dist[u]+w;
				pq.push(mp(v,dist[v]));
			}
		}	
	}	
//	cout<<"Vertex\tDistance\n";
//	for(i=1;i<=n;i++)
//	{
//		cout<<i<<"\t"<<dist[i]<<"\n";
//	}
    if(dist[d]==INT_MAX) printf("NONE\n");
    else printf("%lld\n",dist[d]);
    }
}
