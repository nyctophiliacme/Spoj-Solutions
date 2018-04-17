#include<bits/stdc++.h>
using namespace std;
long a[105][105];long dist[10005];
#define pp pair<long,long>
#define mp make_pair
long input()
{
    long t=0;
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
struct pri
{
    int operator() (const pp&p1,const pp&p2)
    {
        return p1.second>p2.second;
    }
};
priority_queue<pp,vector<pp>,pri> pq;
int main()
{
	long t,n,m,x,y,k,i,j,u,v,size,s,w;
	t=input();
	while(t--)
	{
		m=input();n=input();
		vector<vector < pp > > adj(10005);
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				a[i][j]=input();
			}
		}
		x=input();y=input();k=input();
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				u=n*i+j+1;
				if(i<m-1)
				{
					v=n*(i+1)+j+1;adj[u].push_back(mp(v,a[i+1][j]));
				}
				if(i>0)
				{
					v=n*(i-1)+j+1;adj[u].push_back(mp(v,a[i-1][j]));
				}
				if(j<n-1)
				{
					v=n*(i)+j+2;adj[u].push_back(mp(v,a[i][j+1]));
				}
				if(j>0)
				{
					v=n*(i)+j;adj[u].push_back(mp(v,a[i][j-1]));
				}
			}
		}
    	for(i=0;i<=(n*m);i++)
    	dist[i]=LONG_MAX;
    	s=1;
    	dist[s]=a[0][0];
    	pq.push(mp(s,dist[s]));
		while(!pq.empty())
		{
			u=pq.top().first;
			pq.pop();
			size=adj[u].size();
			for(i=0;i<size;i++)
			{
				v=adj[u][i].first;w=adj[u][i].second;
				if(dist[v]>dist[u]+w&&dist[u]!=LONG_MAX)
				{
					dist[v]=dist[u]+w;
					pq.push(mp(v,dist[v]));
				}	
			}	
		}
		if(dist[n*(x-1)+y]<=k)
		{
			printf("YES\n");printf("%ld\n",k-dist[n*(x-1)+y]);
		}
		else
		{
			printf("NO\n");
		}
		adj.clear();
	}
} 
