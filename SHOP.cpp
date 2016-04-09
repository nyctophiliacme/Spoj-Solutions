#include<bits/stdc++.h>
using namespace std;
queue<pair<int,int> >q;
int main()
{
	int i,j,n,m,si,sj,di,dj;
	char ch;
	while(1)
	{
		scanf("%d %d",&m,&n);
		if(!n&&!m) break;
		int a[n][m];int b[n][m];
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				b[i][j]=INT_MAX;	
		ch=getchar();
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				ch=getchar();
				if(ch=='X') a[i][j]=-1;
				else if(ch=='S') { si=i;sj=j;a[i][j]=0;}
				else if(ch=='D') { di=i;dj=j;a[i][j]=0;}
				else
				{
					a[i][j]=ch-48;
				}
			}ch=getchar();
		}
		q.push({si,sj});
		b[si][sj]=0;
		while(!q.empty())
		{
			i=q.front().first;j=q.front().second;
			//cout<<i<<" "<<j<<"\n";
			q.pop();
			if(i>0)
			{
				if(a[i-1][j]!=-1&&b[i-1][j]>b[i][j]+a[i-1][j])
				{
					b[i-1][j]=b[i][j]+a[i-1][j];
					q.push({i-1,j});
				}
			}
			if(i<n-1)
			{
				if(a[i+1][j]!=-1&&b[i+1][j]>b[i][j]+a[i+1][j])
				{
					b[i+1][j]=b[i][j]+a[i+1][j];
					q.push({i+1,j});
				}
			}
			if(j>0)
			{
				if(a[i][j-1]!=-1&&b[i][j-1]>b[i][j]+a[i][j-1])
				{
					b[i][j-1]=b[i][j]+a[i][j-1];
					q.push({i,j-1});
				}
			}
			if(j<m-1)
			{
				if(a[i][j+1]!=-1&&b[i][j+1]>b[i][j]+a[i][j+1])
				{
					b[i][j+1]=b[i][j]+a[i][j+1];
					q.push({i,j+1});
				}
			}
		}
	    printf("%d\n",b[di][dj]);
	}
}
