#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,t,x,y,p,q,a,b;
	scanf("%d %d",&n,&m);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&x,&y);scanf("%d %d",&a,&b);scanf("%d %d",&p,&q);
		if((fabs(x-a)==fabs(y-b))&&(fabs(x-p)==fabs(y-q)))
		{
			if((x>a&&y>b&&x<p&&y<q)||(x<a&&y<b&&x>p&&y>q)||(x>a&&y<b&&x<p&&y>q)||(x>p&&y<q&&x<a&&y>b))
			{
				printf("NO\n");continue;
			}
		}
		printf("YES\n");
	}
} 
