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
vector<vector<int> > a;
int b[100005],m,ind;
void dfs(int x,int cnt)
{
	int s,i;
	s=a[x].size();
	if(cnt>m) {ind=x;m=cnt;}
	for(i=0;i<s;i++)
	{
		if(!b[a[x][i]]) {
			b[a[x][i]]=1;dfs(a[x][i],cnt+1);
		}
	}
}
int main()
{
	int t,n,x,y,ans,i;
	t=input();
	while(t--)
	{
		n=input();
		a.resize(n);memset(b,0,n*4+10);
		for(i=0;i<n-1;i++)
		{
			x=input();y=input();a[x].push_back(y);a[y].push_back(x);
		}
		m=0;ind=0;
		for(i=0;i<n;i++)
		{
			if(!b[i])
			{
				b[i]=1;dfs(i,0);
			}
		}
        memset(b,0,n*4+10);
		m=0;b[ind]=1;
		dfs(ind,0);
		if(m&1) ans=(m+1)/2;else ans=m/2;
		printf("%d\n",ans);
		a.clear();
	}
} 
