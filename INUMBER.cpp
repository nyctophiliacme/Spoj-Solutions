#include<bits/stdc++.h>
using namespace std;
#define mp make_pair 
queue <pair<int,int> > q;
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
int par[1005][1005],val[1005][1005],_par[1005][1005],seen[1005][1005];
void func(int temp,int x,int y,int i)
{
	q.push(mp(temp,y+i));
	seen[temp][y+i]=1;
	par[temp][y+i]=x;
	val[temp][y+i]=i;
	_par[temp][y+i]=y;
}
stack <int> s;
int main()
{
	int t,l,i,n,x,count,temp,y,save;
	t=input();
	while(t--)
	{
		memset(seen,0,sizeof(seen));
		n=input();
		if(n==1) {printf("1\n");continue;}
		q.push(mp(0,0));
		par[0][0]=0;_par[0][0]=0;
		while(!q.empty())
		{
			x=q.front().first;y=q.front().second;
			q.pop();
			if(x==0&&y==n) break;
			for(i=(x?0:1);i<10;i++)
			{
				temp=(x*10+i)%n;
				if(y+i>n||seen[temp][y+i]) continue;
				func(temp,x,y,i);
			}
		}
		while(x||y)
		{
			s.push(val[x][y]);
			int s1=par[x][y],s2=_par[x][y];
			x=s1;y=s2;
		}
	    while(!s.empty())
	    {
	    	printf("%d",s.top());
	    	s.pop();
		}
		printf("\n");
		while(!q.empty())
		{
			q.pop();
		}
	}
} 
