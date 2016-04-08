#include<bits/stdc++.h>
using namespace std;
int a[1000005];
queue<int> q;
int main()
{
	int f,s,g,d,u,t;
	scanf("%d %d %d %d %d",&f,&s,&g,&u,&d);
	memset(a,-1,sizeof(a));
	a[s]=0;
	q.push(s);
	while(!q.empty())
	{
		t=q.front();q.pop();
		if(t+u<=f)
		{
			if(a[t+u]==-1||a[t]+1<a[t+u])
			{
				q.push(t+u);a[t+u]=a[t]+1;
			}
		}
		if(t-d>0)
		{
			if(a[t-d]==-1||a[t]+1<a[t-d])
			{
				q.push(t-d);a[t-d]=a[t]+1;
			}
		}
	}
	if(a[g]==-1) 
		printf("use the stairs");
	else
	    printf("%d",a[g]);
} 
