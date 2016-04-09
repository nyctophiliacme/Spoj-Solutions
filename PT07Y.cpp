#include<bits/stdc++.h>
#define p 1000000007
using namespace std;
typedef long long ll;
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
vector<vector<int> >a;
int b[10005],par[10005],flag;
void dfs(int x)
{
	int i,size;
	size=a[x].size();
	for(i=0;i<size;i++)
	{
		if(b[a[x][i]]) {if(par[x]!=a[x][i]) {flag=1;return;}else continue;}
		b[a[x][i]]=1;par[a[x][i]]=x;dfs(a[x][i]);
	}
}
int main()
{
	int n,m,i,x,y;
	n=input();m=input();
	a.resize(n+1);memset(b,0,n*4+10);memset(par,0,n*4+10);flag=0;
	for(i=0;i<m;i++)
	{
		x=input();y=input();
		a[x].push_back(y);a[y].push_back(x);
	}
	b[1]=1;par[1]=-1;
	dfs(1);
	for(i=1;i<=n;i++)
	{
		if(!b[i]) flag=1;
	}
	if(!flag) printf("YES");else printf("NO");
}
