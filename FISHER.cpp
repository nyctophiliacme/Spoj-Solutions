#include<bits/stdc++.h>
using namespace std;
int input()
{
    int t=0;
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
int k,cans,tans,n;
vector<vector<int> >a,tx,adj;
vector<vector<int> >d;
void dfs(int x,int t,int cost)
{
	int i,size;
	if(t>k) return;
	size=a[x].size();
	for(i=0;i<size;i++)
	{
		if(t+tx[x][i]<=k)
		{
		if(d[adj[x][i]][t+tx[x][i]]>d[x][t]+a[x][i])
		{
			d[adj[x][i]][t+tx[x][i]]=d[x][t]+a[x][i];
			dfs(adj[x][i],t+tx[x][i],d[x][t]+a[x][i]);
		}
	    }
	}
}
int main()
{
	int i,j,temp;
	while(1)
	{
		n=input();k=input();
		a.resize(n);adj.resize(n);tx.resize(n);d.resize(n);
		cans=INT_MAX;
		if(!n&&!k)
		{
			break;
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				temp=input();
				if(i!=j)
				{
					tx[i].push_back(temp);
					adj[i].push_back(j);
				}
			}
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				temp=input();
				if(i!=j)
				{
					a[i].push_back(temp);
				}
			}
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<=k;j++)
			{
				d[i].push_back(INT_MAX);
			}
		}
		d[0][0]=0;
		dfs(0,0,0);
		for(i=0;i<=k;i++)
		{
			if(cans>d[n-1][i])
			{
				cans=d[n-1][i];tans=i;
			}
		}
		printf("%d %d\n",cans,tans);
		a.clear();adj.clear();tx.clear();d.clear();
	}
} 
