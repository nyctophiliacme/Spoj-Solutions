#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
typedef long long ll;
#define M 20005
ll par[M],rnk[M],sz[M];
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
void make_set(ll x)
{
	par[x]=x;rnk[x]=0;sz[x]=1;
}
ll find_set(ll x)
{
	if(x!=par[x]) par[x]=find_set(par[x]);
	return par[x];
}
void merge(ll x,ll y)
{
	ll px,py;
	px=find_set(x);py=find_set(y);
	if(rnk[px]>rnk[py]) 
	{
		par[py]=px;sz[px]+=sz[py];
	}
	else 
	{
		par[px]=py;sz[py]+=sz[px];
	}
	if(rnk[px]==rnk[py]) rnk[py]+=1;
}
struct job
{
	ll s,d;
};
int main()
{
	ll t,n,i,q,count,temp,x,y,j,ans;
	char ch;
	t=input();
	while(t--)
	{
		n=input();
		job a[n-1];int rem[n+1];memset(rem,0,sizeof(rem));
		for(i=0;i<n-1;i++)
		{
			a[i].s=input();a[i].d=input();
		}
		for(i=1;i<=n;i++)
		{
			make_set(i);
		}
		q=input();
		stack<ll> st,res;
		while(q--)
		{
			ch=getchar();
			if(ch=='R')
			{
				temp=input();st.push(temp);rem[temp]=1;
			}
			else
			{
				st.push(0);ch=getchar();
			}
		}
		for(i=1;i<n;i++)
		{
			if(!rem[i]) st.push(i);
		}
		count=n*(n-1)/2;
		while(!st.empty())
		{
			temp=st.top();st.pop();
			if(!temp)
			{
				res.push(count);			
			}
			else
			{
				x=find_set(a[temp-1].s);y=find_set(a[temp-1].d);
				count-=sz[x]*sz[y];
				merge(x,y);
			}
		}
		while(!res.empty())
		{
			printf("%lld\n",res.top());res.pop();
		}
		printf("\n");
	}
} 
