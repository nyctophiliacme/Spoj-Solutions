#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
typedef long long ll;
#define M 100005
int par[M],rnk[M];
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
void make_set(int x)
{
	par[x]=x;rnk[x]=0;
}
int find_set(int x)
{
	if(x!=par[x]) par[x]=find_set(par[x]);
	return par[x];
}
void merge(int x,int y)
{
	int px,py;
	px=find_set(x);py=find_set(y);
	if(rnk[px]>rnk[py]) par[py]=px;
	else par[px]=py;
	if(rnk[px]==rnk[py]) rnk[py]+=1;
}
struct job
{
	int s,d;ll w;
};
bool comp(job a,job b)
{
	return a.w<b.w;
}
int main()
{
	int t,n,e,i,k,x,y,count;
	t=input();
	while(t--)
	{
	n=input();e=input();
	int arr[n];
	count=0;
	for(i=0;i<n;i++)
	{
		arr[i]=input();if(arr[i]) count++;
	}
	job a[e+count],res[n+1];int c[n+1];memset(c,0,sizeof(c));
	for(i=0;i<e;i++)
	{
		a[i].s=input();a[i].d=input();a[i].w=input();
	}
	k=i;
	for(i=0;i<n;i++)
	{
		if(arr[i])
		{
			a[k].s=i+1;a[k].d=0;a[k].w=0;k++;
		}
	}
	sort(a,a+e+count,comp);
	make_set(0);
	for(i=0;i<n;i++)
	{
		make_set(i+1);
	}
	k=0;
	for(i=0;i<e+count;i++)
	{
		x=find_set(a[i].s);y=find_set(a[i].d);
		if(x!=y)
		{
			merge(x,y);
			res[k++]=a[i];
		}
	}
	int flag=0;
	for(i=0;i<k;i++)
	{
		if(arr[res[i].s-1]||arr[res[i].d-1]) flag=1;
		c[res[i].s]=1;c[res[i].d]=1;
	}
	for(i=1;i<=n;i++)
	{
		if(!c[i]) flag=0;
	}
	ll ans=0;
	for(i=0;i<k;i++)
	{
		ans+=(ll)res[i].w;
	}
	if(!flag) printf("impossible\n");
	else printf("%lld\n",ans);
    }
}
