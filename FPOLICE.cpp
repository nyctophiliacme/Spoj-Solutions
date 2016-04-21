#include<bits/stdc++.h>
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
int n,T,ans1,ans2,a[105][105],b[105][105],dp[105][255];
void dfs(int x,int risk,int tm)
{
	ll i;
	for(i=0;i<n;i++)
	{
		if(i!=x&&tm+a[x][i]<=T)
		{
		if(dp[i][tm+a[x][i]]>risk+b[x][i])
		{
			dp[i][tm+a[x][i]]=risk+b[x][i];
			dfs(i,risk+b[x][i],tm+a[x][i]);
		}
	    }
	}
}
int main()
{
	int t,i,j;
	t=input();
	while(t--)
	{
		n=input();T=input();
		ans1=INT_MAX;ans2=INT_MAX;
		for(i=0;i<n;i++) for(j=0;j<n;j++) a[i][j]=input();
		for(i=0;i<n;i++) for(j=0;j<n;j++) b[i][j]=input();
		for(i=0;i<n;i++) for(j=0;j<=T;j++) dp[i][j]=INT_MAX;
		dp[0][0]=0;
		dfs(0,0,0);
		for(i=0;i<=T;i++)
		{
			if(ans1>dp[n-1][i]) 
			{
				ans1=dp[n-1][i];ans2=i;
			}
		}
		if(ans2>T)printf("-1\n");
		else printf("%d %d\n",ans1,ans2);
	}
}
