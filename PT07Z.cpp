#include<bits/stdc++.h>
using namespace std;
int cnt,b[10005],fin,id,n;
vector<vector<int> >a(10005);
void dfs(int x,int cnt)
{
	int size,i;
	if(b[x]) return;
	cnt++;
	b[x]=1;
	if(fin<cnt)
	{
		fin=cnt;id=x;
	}
	size=a[x].size();
	for(i=0;i<size;i++)
	{
		dfs(a[x][i],cnt);
	}
}
int main()
{
	scanf("%d",&n);
	int x,y,i;
	memset(b,0,sizeof(b));
	for(i=0;i<n-1;i++)
	{
		scanf("%d %d",&x,&y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	fin=0;id=0;
	dfs(1,-1);
	memset(b,0,sizeof(b));
	dfs(id,-1);
	printf("%d",fin);
} 
