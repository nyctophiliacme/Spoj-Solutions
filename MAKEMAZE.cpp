#include<bits/stdc++.h>
using namespace std;
queue<pair<int,int> >q;
int main()
{
	int t,n,m,i,j,count;
	int x,y,sx,sy,dx,dy,flag;
	char ch;
	scanf("%d",&t);
	while(t--)
	{
		count=0;
		scanf("%d %d",&n,&m);
		char a[n][m];
		int b[n][m];
		memset(b,0,sizeof(b));
		flag=1;
		ch=getchar();
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				a[i][j]=getchar();
				if((i==0||i==n-1||j==0||j==m-1)&&a[i][j]=='.')
				{
					count++;
					if(flag)
					{
						sx=i;sy=j;flag=0;
					}
					else
					{
						dx=i;dy=j;
					}
				}
			}
			ch=getchar();
		}
		if(count!=2)
		{
			printf("invalid\n");continue;
		}
		q.push(make_pair(sx,sy));
		b[sx][sy]=1;
		while(!q.empty())
		{
			x=q.front().first;y=q.front().second;
			q.pop();
			if(x>0)
			{
				if(a[x-1][y]=='.'&&!b[x-1][y])
			    {
			    	q.push(make_pair(x-1,y));b[x-1][y]=1;
				}
			}
			if(x<n-1)
			{
				if(a[x+1][y]=='.'&&!b[x+1][y])
			    {
			    	q.push(make_pair(x+1,y));b[x+1][y]=1;
				}
			}
			if(y>0)
			{
				if(a[x][y-1]=='.'&&!b[x][y-1])
			    {
			    	q.push(make_pair(x,y-1));b[x][y-1]=1;
				}
			}
			if(y<m-1)
			{
				if(a[x][y+1]=='.'&&!b[x][y+1])
			    {
			    	q.push(make_pair(x,y+1));b[x][y+1]=1;
				}
			}
		}
		if(b[dx][dy])
		{
			printf("valid\n");
		}		
		else
		{
			printf("invalid\n");
		}
	}
} 
