#include<bits/stdc++.h>
using namespace std;
#define M 1000005
vector<vector<int> >a;
queue<int> q;
int b[M],flag,k[M],s[M],cnt;
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
void dfs(int x,int y,int z)
{
	int i,size;
	if(y>z) return;
	if(b[x]&&b[x]!=cnt) {flag=1;return;}
	b[x]=cnt;
	size=a[x].size();
	for(i=0;i<size;i++)
	{
		dfs(a[x][i],y+1,z);
	}
}
int main()
{
	int n,r,m,x,y,i,t;
	t=input();
	while(t--)
	{
		n=input();r=input();m=input();
		memset(b,0,sizeof(b));
		a.resize(n+1);flag=0;
	    for(i=0;i<r;i++)
	    {
	    	x=input();y=input();
	    	a[x].push_back(y);a[y].push_back(x);
		}
		for(i=0;i<m;i++)
		{
			k[i]=input();s[i]=input();
		}
		cnt=1;
		for(i=0;i<m;i++)
		{
			dfs(k[i],0,s[i]);cnt++;
		}
		for(i=1;i<=n;i++)
		{
			if(!b[i]) flag=1;
		}
	    if(flag) printf("No\n");
	    else printf("Yes\n");
	    a.clear();
	}
} 