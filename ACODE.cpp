#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char a[5005];
int main()
{
	ll i,l,x,y,cur,prev,temp;
	while(1)
	{
		scanf("%s",a);
		if(strlen(a)==1&&a[0]=='0')
		{
			break;
		}
		l=strlen(a);
		x=1;y=1;
		if(l==1)
		{
			printf("1\n");continue;
		}
		prev=a[0]-'0';
		for(i=1;i<l;i++)
		{
			cur=a[i]-'0';
			//cout<<"cur "<<cur<<"\n";
			if(!cur)
			{
				y=x;x=0;
			}
			else
			{
				if(prev<2||(prev==2&&cur<7))
				{
					temp=y;y=x+y;x=temp;
				}
				else
				{
					x=y;
				}
			}
			//cout<<"x "<<x<<"y "<<y<<"\n";
			prev=cur;
		}
		printf("%lld\n",y);
		
	}
}
 
