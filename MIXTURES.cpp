#include<bits/stdc++.h>
using namespace std;
typedef long long ll;	
int main()
{
	ll a[105][105],dp[105][105];
	ll n,i,j,k,l,temp;
	while(scanf("%lld",&n)!=-1)
	{
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i][i]);
			dp[i][i]=0;
		}
		for(k=2;k<=n;k++)
		{
			for(i=0;i<n-k+1;i++)
			{
				j=i+k-1;dp[i][j]=INT_MAX;a[i][j]=INT_MAX;
				for(l=i;l<i+k;l++)
				{
					temp=dp[i][l]+dp[l+1][j]+a[i][l]*a[l+1][j];
					if(temp==dp[i][j])
					{
						a[i][j]=min(a[i][j],(a[i][l]+a[l+1][j])%100);
					}
					else if(temp<dp[i][j])
					{
						dp[i][j]=temp;a[i][j]=(a[i][l]+a[l+1][j])%100;
					}
				}
			}
		}
		printf("%lld\n",dp[0][n-1]);
	}
}
