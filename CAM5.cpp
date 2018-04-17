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
vector<vector<int> > a;
int b[100005];
stack<int> st;
int main()
{
	int t,n,x,y,e,i,count;
	t=input();
	while(t--)
	{
		n=input();e=input();
		a.resize(n);count=0;memset(b,0,n*4+10);
		for(i=0;i<e;i++)
		{
			x=input();y=input();a[x].push_back(y);a[y].push_back(x);
		}
		for(i=0;i<n;i++)
		{
			if(!b[i])
			{
				b[i]=1;count++;
				st.push(i);
				while(!st.empty())
				{
					x=st.top();st.pop();
					int s=a[x].size();
					for(int i=0;i<s;i++)
					{
						if(!b[a[x][i]]) {b[a[x][i]]=1;st.push(a[x][i]);}
					}
				}
			}
		}
		printf("%d\n",count);
		a.clear();
	}
} 
