#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll input()
{
    ll t=0;
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
ll a[1005],dp[1005][1005];	
ll func(ll l,ll r)
{
	if(dp[l][r]!=INT_MIN) return dp[l][r];
	ll p,q,x,y,temp1,temp2;
	if(r-l==1)
	{
		return fabs(a[l]-a[r]);
	}
	if(a[r]>a[l+1])
	{
		x=0;y=1;temp1=a[l]-a[r];
	}
	else
	{
		x=1;y=0;temp1=a[l]-a[l+1];
	}
	if(a[r-1]>a[l])
	{
		p=0;q=1;temp2=a[r]-a[r-1];
	}
	else 
	{
		p=1;q=0;temp2=a[r]-a[l];
	}
	dp[l][r]= max(temp1+func(l+1+x,r-y),temp2+func(l+p,r-1-q));
	return dp[l][r];
}
int main()
{
	ll n,i,ans,cs=1,j;
	while(1)
	{
		n=input();if(!n) break;
		for(i=0;i<=n;i++) for(j=0;j<=n;j++) dp[i][j]=INT_MIN;
		for(i=0;i<n;i++) a[i]=input();
		ans=func(0,n-1);
		printf("In game %lld, the greedy strategy might lose by as many as %lld points.\n",cs,ans);cs++;
	}
}
