#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,i,j;
int a[1005][1005];
char b[1005][1005];
void dfs(int x,int y,int cnt)
{
	if(a[x][y]) return;
	a[x][y]=cnt;
	if(x>0)
	{
		if(b[x-1][y]=='S') dfs(x-1,y,cnt);
	}
	if(x<n-1)
	{
		if(b[x+1][y]=='N') dfs(x+1,y,cnt);
	}
	if(y>0)
	{
		if(b[x][y-1]=='E') dfs(x,y-1,cnt);
	}
	if(y<m-1)
	{
		if(b[x][y+1]=='W') dfs(x,y+1,cnt);
	}
	if(b[x][y]=='S') dfs(x+1,y,cnt);
	if(b[x][y]=='N') dfs(x-1,y,cnt);
	if(b[x][y]=='E') dfs(x,y+1,cnt);
	if(b[x][y]=='W') dfs(x,y-1,cnt);
}
int main()
{
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%s",b[i]);
	}
	memset(a,0,sizeof(a));
	cnt=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(!a[i][j])
			{
				cnt++;
				dfs(i,j,cnt);
			}
		}
	}
	printf("%d",cnt);
} 
