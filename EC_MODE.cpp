#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define M 1000005
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
	int s,d;double w;
};
bool comp(job a,job b)
{
	return a.w<b.w;
}
double func(int a,int b,int c,int d)
{
	return (double)sqrt((a-c)*(a-c)+(b-d)*(b-d));
}
int main()
{
	int t,tc,n,e,i,k,x,y,r,w,u,v,j,temp;
	double temp2,ans;
	t=input();
	for(tc=1;tc<=t;tc++)
	{
	n=input();r=input();w=input();u=input();v=input();
	e=n*(n-1)/2;
	vector<pair<int,int> >b(n+1);
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&b[i].first,&b[i].second);
	}
	job a[e],res[n];
	k=0;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			temp2=func(b[i].first,b[i].second,b[j].first,b[j].second);
			a[k].s=i;a[k].d=j;a[k].w=temp2;k++;
		}
	}
	sort(a,a+e,comp);
	for(i=0;i<n;i++)
	{
		make_set(i);
	}
	k=0;temp=n;
	for(i=0;i<e;i++)
	{
		x=find_set(a[i].s);y=find_set(a[i].d);
		if(x!=y)
		{
			merge(x,y);temp--;
			res[k++]=a[i];
			if(temp==w) break;
		}
	}
	double a1=0,a2=0;
	for(i=0;i<k;i++)
	{
		ans=(double)res[i].w;
		if(ans>r) a2+=(double)ans*v;
		else a1+=(double)ans*u;
		//cout<<res[i].s<<" "<<res[i].d<<" "<<res[i].w<<"\n";
	}
	printf("Caso #%d: %.3f %.3f\n",tc,a1,a2);
    }
} 
