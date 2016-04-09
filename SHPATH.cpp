#include<bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
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
struct pri
{
    int operator() (const pp&p1,const pp&p2)
    {
        return p1.second>p2.second;
    }
};
int main()
{
	vector<vector< pp > >a;
	priority_queue< pp,vector<pp >,pri >pq;
	map<string,int> m;
	char temp1[15],temp2[15];
	int t,n,e,x,w,u,v,i,s,dest,dist[10005],size;
	t=input();
	while(t--)
	{
		n=input();
		a.resize(n+1);
		for(i=1;i<=n;i++)
		{
			scanf("%s",temp1);
			m[temp1]=i;
			e=input();
			while(e--)
			{
				x=input();w=input();
				a[i].push_back(make_pair(x,w));
			}
		}
		e=input();
		while(e--)
		{
			scanf("%s",temp1);scanf("%s",temp2);
			s=m[temp1];dest=m[temp2];
			//cout<<s<<" "<<dest<<"\n";
			for(i=0;i<=n;i++)
			dist[i]=INT_MAX;
			dist[s]=0;
			pq.push(make_pair(s,0));
			while(!pq.empty())
			{
				u=pq.top().first;pq.pop();
				size=a[u].size();
				for(i=0;i<size;i++)
				{
					v=a[u][i].first;w=a[u][i].second;
					if(dist[v]>dist[u]+w)
					{
						dist[v]=dist[u]+w;
						pq.push(make_pair(v,dist[v]));
					}
				}
			}
			printf("%d\n",dist[dest]);
		}
		m.clear();a.clear();
    }
} 
