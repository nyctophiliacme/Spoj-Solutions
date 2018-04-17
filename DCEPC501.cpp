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
ll dp[1000010],a[1000010],n;
ll func(ll i)
{
	if(i>=n) return 0;
	if(n-i<=3)
	{
		ll sum=0;
		for(;i<n;i++) sum+=a[i];
		return sum;
	}
	if(dp[i]!=-1) return dp[i];
	else dp[i]=max(max(a[i]+func(i+2),a[i]+a[i+1]+func(i+4)),a[i]+a[i+1]+a[i+2]+func(i+6));
	return dp[i];
}
int main()
{
	ll t,i;
	t=input();
	while(t--)
	{
		n=input();
		for(i=0;i<n;i++) a[i]=input();
		memset(dp,-1,8*n+20);
		printf("%lld\n",func(0));	
	}
}
