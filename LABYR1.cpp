#include<bits/stdc++.h>
    using namespace std;
    long n,m,cnt,ans,sx,sy;
    char a[1005][1005];int b[1005][1005];
    void dfs(long i,long j,long cnt)
    {
    	if(i<0||i>n-1||j<0||j>m-1||a[i][j]=='#'||b[i][j])
    	return;
    	cnt++;
    	b[i][j]=cnt;
    	if(ans<cnt)
    	{
    		ans=cnt;sx=i;sy=j;
		}
    	dfs(i,j+1,cnt);dfs(i,j-1,cnt);dfs(i+1,j,cnt);dfs(i-1,j,cnt);
    }
    long input()
    {
        long t=0;
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
    	long t,i,j,sol,k;
    	t=input();
    	while(t--)
    	{
    		m=input();n=input();
    		vector<pair<long,long> >v;
    		memset(b,0,sizeof(b));
    		for(i=0;i<n;i++)
    		{
    			for(j=0;j<m;j++)
    			{
    				a[i][j]=getchar();
    			}
    			char ch=getchar();
    		}
    		sol=0;
    		k=0;
    		for(i=0;i<n;i++)
    		{
    			for(j=0;j<m;j++)
    			{
    				if(a[i][j]=='.'&&!b[i][j])
    				{
    					cnt=0;ans=0;sx=i;sy=j;
    					dfs(i,j,0);
    					
    					v.push_back(make_pair(sx,sy));
						k++;
    				}	
    			}
    		}
    		memset(b,0,sizeof(b));
    		sol=0;
    		for(i=0;i<k;i++)
    		{
    			ans=0;
				dfs(v[i].first,v[i].second,0);
    			sol=max(sol,ans);
			}
			sol--;
			if(sol<0)
			sol=0;
			v.clear();
    		printf("Maximum rope length is %ld.\n",sol);
    	}
    }  

