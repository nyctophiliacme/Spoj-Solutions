#include<bits/stdc++.h>
using namespace std;
vector<vector<int> >a;
int b[10000],flag;
void dfs(int x)
{
	int i,size;
	size=a[x].size();
	for(i=0;i<size;i++)
	{
	//	cout<<x<<"->"<<a[x][i]<<" "<<b[x]<<" "<<b[a[x][i]]<<"\n";
		if(b[a[x][i]]==b[x])
		{
	//		cout<<"\nflag\n";
			flag=1;return;
		}
		else if(b[a[x][i]]==-1)
		{
			b[a[x][i]]=!b[x];
			dfs(a[x][i]);
		}
	}
}
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
int main()
{
	int k,t,n,e,x,y,i;
	t=input();
	for(k=1;k<=t;k++)
	{
		n=input();e=input();
		a.resize(n+1);
		for(i=0;i<e;i++)
		{
			x=input();y=input();
			a[x].push_back(y);
			a[y].push_back(x);
		}
		flag=0;
		memset(b,-1,sizeof(b));
		for(i=1;i<=n;i++)
		{
			if(b[i]==-1)
			{
				b[i]=0;dfs(i);
			}
			//cout<<"\n";
		}
     	printf("Scenario #%d:\n",k);
		if(flag)
		{
			printf("Suspicious bugs found!\n");
		}
		else
		{
			printf("No suspicious bugs found!\n");
		}
		a.clear();
	}
} 
