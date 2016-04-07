/*Solution to Prime Path-PPATH on Spoj*/
#include<bits/stdc++.h>
using namespace std;
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
int gen(int n,int pos,int var)
{
	int temp,i,save,ans;
	temp=0;
	for(i=0;i<pos;i++)
	{
		save=n%10;
		temp+=pow(10,i)*save;
		n/=10;
	}
	ans=pow(10,pos)*n+temp-save*pow(10,pos-1)+var*pow(10,pos-1);
	return ans;
}
queue<int> q;
int a[10005],b[10005];
int main()
{
	int t,x,y;
	int l,n,i,j,k,temp;
	n=10000;
	l=sqrt(n)+1;
	memset(b,0,sizeof(b));
	for(i=2;i<=l;i++)
	{
		if(!b[i])
		{
			k=2;j=k*i;
			while(j<n)
			{
				b[j]=1;k++;j=k*i;
			}
		}
	}
	t=input();
	while(t--)
	{
		x=input();y=input();
		memset(a,-1,sizeof(a));
		q.push(x);
		a[x]=0;
		while(!q.empty())
		{
			temp=q.front();
			//cout<<temp<<"\n";
			q.pop();
			for(i=1;i<5;i++)
			{
				for(j=(i==4?1:0);j<10;j++)
				{
					n=gen(temp,i,j);
					if(!b[n])
					{
						if(a[n]==-1||a[n]>a[temp]+1)
						{
							a[n]=a[temp]+1;q.push(n);
						}
					}
				}
			}
		}
		if(a[y]==-1)
		{
			printf("impossible\n");
		}
		else printf("%d\n",a[y]);
	}
}
