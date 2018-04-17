#include<bits/stdc++.h>
#define p 1000000007
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
vector<vector<ll> >b(10);
ll a[100005][10];
int main()
{
	b[0].push_back(7);b[1].push_back(2);b[1].push_back(4);b[2].push_back(1);b[2].push_back(3);b[2].push_back(5);b[9].push_back(8);
	b[3].push_back(2);b[3].push_back(6);b[4].push_back(1);b[4].push_back(5);b[4].push_back(7);b[6].push_back(9);b[9].push_back(6);
	b[5].push_back(2);b[5].push_back(4);b[5].push_back(6);b[5].push_back(8);b[6].push_back(3);b[6].push_back(5);
	b[7].push_back(4);b[7].push_back(8);b[7].push_back(0);b[8].push_back(7);b[8].push_back(5);b[8].push_back(9);
	ll n,t,i,j,k,ans,size;
	for(i=0;i<10;i++)
	{
		a[0][i]=0;a[1][i]=1;
	}
	for(i=2;i<100001;i++)
	{
		for(j=0;j<10;j++)
		{
			size=b[j].size();ans=0;
			for(k=0;k<size;k++)
			{
				ans+=a[i-1][b[j][k]]%p;
			}
			a[i][j]=ans%p;
		}
	}
	t=input();
	while(t--)
	{
		n=input();ans=0;
		for(i=0;i<10;i++)
		{
			ans+=a[n][i]%p;
		}
		printf("%lld\n",ans%p);
	}
}
