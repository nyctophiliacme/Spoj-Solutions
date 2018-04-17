#include<bits/stdc++.h>
using namespace std;
struct node
{
	int p,q,r;
};
int a[55][55][55];
int b[150000];
queue<node> q;
int main()
{
	int n,x,y,z,i,j,ans;
	node temp;
	char s[55][55],ch;
	cin>>n;
	while(n)
	{
		memset(a,-1,sizeof(a));
		cin>>x>>y>>z;
		for(i=1;i<=n;i++) for(j=1;j<=n;j++) cin>>s[i][j];
		q.push({x,y,z});
		a[x][y][z]=0;ans=-1;
		while(!q.empty())
		{
			temp=q.front();q.pop();x=temp.p;y=temp.q;z=temp.r;
			if(x==y&&y==z)
			{
				ans=a[x][y][z];break;
			}
			for(i=1;i<=n;i++)
			{
				if(s[x][i]==s[y][z])
				{
					if(a[i][y][z]==-1||a[i][y][z]>a[x][y][z]+1)
					{
						a[i][y][z]=a[x][y][z]+1;q.push({i,y,z});
					}
				}
				if(s[z][i]==s[x][y])
				{
					if(a[x][y][i]==-1||a[x][y][i]>a[x][y][z]+1)
					{
						a[x][y][i]=a[x][y][z]+1;q.push({x,y,i});
					}
				}
				if(s[y][i]==s[x][z])
				{
					if(a[x][i][z]==-1||a[x][i][z]>a[x][y][z]+1)
					{
						a[x][i][z]=a[x][y][z]+1;q.push({x,i,z});
					}
				}
			}
		}
		if(ans==-1) printf("impossible\n");
		else printf("%d\n",ans);
		cin>>n;
		while(!q.empty()) q.pop();
	}
}
