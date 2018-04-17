#include<bits/stdc++.h>
using namespace std;
char s[105][105];int a[105][105];
int r,c,flag;
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
char k[11];
void dfs(int x,int y,int cnt)
{
	if(x<0||x>r-1||y<0||y>c-1) return;
	if(s[x][y]!=k[cnt]||a[x][y]) return;
	if(cnt==9) {flag=1;return;}
	a[x][y]=1;
	for(int i=-1;i<2;i++) for(int j=-1;j<2;j++) dfs(x+i,y+j,cnt+1);
	a[x][y]=0;
}
int main()
{
	strcpy(k,"ALLIZZWELL");
	int t,i,j;
	t=input();
	while(t--)
	{
		r=input();c=input();
		memset(a,0,sizeof(a));
		for(i=0;i<r;i++)
		{
			scanf("%s",s[i]);
		}
		flag=0;
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				dfs(i,j,0);
			}
		}
		if(flag) printf("YES\n");else printf("NO\n");
	}
} 
