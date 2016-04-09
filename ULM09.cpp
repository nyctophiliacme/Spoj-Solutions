#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
typedef long long ll;
#define M 1000005
ll par[M],rnk[M];
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
	par[x]=x;rnk[x]=0;
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
	if(rnk[px]>rnk[py]) par[py]=px;
	else par[px]=py;
	if(rnk[px]==rnk[py]) rnk[py]+=1;
}
struct job
{
	ll s,d,w;
};
bool comp(job a,job b)
{
	return a.w<b.w;
}
int main()
{
	ll n,e,i,k,x,y;
	while(1)
	{
	n=input();e=input();
	if(!n&&!e) break;
	job a[e],res[n];k=0;
	ll sum=0;
	for(i=0;i<e;i++)
	{
		a[i].s=input();a[i].d=input();a[i].w=input();sum+=a[i].w;
	}
	sort(a,a+e,comp);
	for(i=0;i<n;i++)
	{
		make_set(i);
	}
	for(i=0;i<e;i++)
	{
		x=find_set(a[i].s);y=find_set(a[i].d);
		if(x!=y)
		{
			merge(x,y);
			res[k++]=a[i];
		}
	}
	ll ans=0;
	for(i=0;i<k;i++)
	{
		ans+=res[i].w;//cout<<res[i].s<<" "<<res[i].d<<" "<<res[i].w<<"\n";
	}
	printf("%lld\n",sum-ans);
    }
}
