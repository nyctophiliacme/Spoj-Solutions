#include<bits/stdc++.h>
#define p 1000000007
using namespace std;
typedef long long ll;
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
	int l,i,flag1,flag2,a[1000],temp;
	char b[1000];
	while(cin>>b)
	{
		l=strlen(b);
		for(i=0;i<l;i++)
		{
			a[i]=b[i]-48;
		}
		if(l==1&&a[0]==1)
		{
			printf("1\n");continue;
		}
		if(l==1&&a[0]==0)
		{
			printf("0\n");continue;
		}
		flag1=0;
		for(i=1;i<l;i++)
	    {
	    	if(a[i]) {flag1=1;break;}
		}
		if(a[0]!=1) flag2=1;else flag2=0;
		if(flag1||flag2)
		{
			i=l-1;
			while(!a[i]){a[i]=9;i--;}
			a[i]--;temp=0;
			for(i=l-1;i>=0;i--)
			{
				temp+=a[i]*2;
				a[i]=temp%10;
				temp/=10;
			}
			if(temp) printf("1");
			for(i=0;i<l;i++) printf("%d",a[i]);
		}
		else
		{
			printf("1");
			for(i=1;i<l-1;i++) printf("9");
			printf("8");
		}
		printf("\n");
	}
} 
