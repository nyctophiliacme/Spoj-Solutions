/*This is a classical bfs problem.
I have used two arrays par[] and val[].
par[] is for storing how the modulus state got reached. val[] stores the value (0 or 1) at each modulus state.
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
queue <ll> q;
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
ll par[20005];
ll val[20005];
stack <ll> s;
int main()
{
	ll t,l,i,n,x,count,temp;
	t=input();
	while(t--)
	{
		memset(par,-1,sizeof(par));
		memset(val,0,sizeof(val));
		n=input();
		if(n==1) {printf("1\n");continue;}
		q.push(1);
		val[1]=1;par[1]=0;
		while(!q.empty())
		{
			x=q.front();
			q.pop();
			if(!(x)) break;
			temp=(x*10)%n;
			if(par[temp]==-1)
			{
				q.push(temp);
				par[temp]=x;
				val[temp]=0;
			}
			temp=(x*10+1)%n;
			if(par[temp]==-1)
			{
				q.push(temp);
				par[temp]=x;
				val[temp]=1;
			}
		}
		while(par[x])
		{
			s.push(val[x]);
			x=par[x];
		}
		s.push(1);
	    while(!s.empty())
	    {
	    	printf("%lld",s.top());
	    	s.pop();
		}
		printf("\n");
		while(!q.empty())
		{
			q.pop();
		}
	}
}