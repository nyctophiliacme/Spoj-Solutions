#include<bits/stdc++.h>
using namespace std;
typedef long long ll;	
ll a[100005][3],b[100005][3];
int main()
{
	ll n,i,j,x,y,z;
	ll cs=1;
	while(1)
	{
		scanf("%lld",&n);
		if(!n) break;
		for(i=0;i<n;i++)
		{
			for(j=0;j<3;j++)
			{
				scanf("%lld",&a[i][j]);
			}
		}
		for(j=0;j<3;j++) b[0][j]=a[0][j];
		i=0;j=2;
		b[i][j]=a[i][j]+b[i][j-1];
		i=1;
		b[i][0]=b[i-1][1]+a[i][0];
		y=min(b[i-1][1],b[i-1][2]);
		j=1;
		z=min(y,b[i][j-1]);
		b[i][j]=a[i][j]+z;
		j=2;
		z=min(y,b[i][j-1]);
		b[i][j]=a[i][j]+z;
		for(i=2;i<n;i++)
		{
			x=min(b[i-1][0],b[i-1][1]);y=min(b[i-1][1],b[i-1][2]);
			j=0;
			b[i][j]=x+a[i][j];
			j=1;
			z=min(min(x,b[i-1][2]),b[i][j-1]);
			b[i][j]=z+a[i][j];
			j=2;
			z=min(y,b[i][j-1]);
			b[i][j]=z+a[i][j];
		}
		printf("%lld. %lld\n",cs,b[n-1][1]);cs++;
	}
}
