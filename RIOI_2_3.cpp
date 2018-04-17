#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pp pair<int, int>
#define ppp pair<pp, int>
#define mp make_pair
vector<vector<int> >a;
vector<vector<vector<int> > >dp;
int n;
int xcord[] = {-1, 1, 0, 0};
int ycord[] = {0, 0, -1, 1};
int isvalid(pp temp)
{
   if(temp.first >= 0 && temp.first < n && temp.second >=0 && temp.second < n)
      return 1;
   else
      return 0;
}
int calc(int n)
{
   int count = 0;
   while(n)
   {
      if(n & 1)
      {
         count++;
      }
      n /= 2;
   }
   return count;
}
int ans;
void bfs(pp start, pp end)
{
   queue<ppp> q;
   ppp temp;
   pp prev, cur;
   int newMask,mask = 1<<a[start.first][start.second];
   q.push(mp(start, mask));
   dp[start.first][start.second][mask] = 1;
   while(!q.empty())
   {
      temp = q.front();
      q.pop();
      prev = temp.first;
      mask = temp.second;
      for(int i = 0; i < 4; i++)
      {
         cur = mp(prev.first + xcord[i], prev.second + ycord[i]);
         if(isvalid(cur) && !dp[cur.first][cur.second][mask])
         {
            newMask = mask | (1<<a[cur.first][cur.second]);
            if(cur == end)
            {
               ans = min(ans, calc(newMask));
               continue;
            }
            dp[cur.first][cur.second][newMask] = 1;
            q.push(mp(cur, newMask));
         }
      }
   }
}
int main()
{
   ios_base::sync_with_stdio(0);
   int t;
   cin>>t;
   pp start, end;
   while(t--)
   {
      cin>>n;
      a.clear();
      dp.clear();
      a.resize(n,vector<int>(n));
      dp.resize(n, vector<vector<int> >(n, vector<int>(1025)));
      for(int i = 0; i < n; i++)
      {
         for(int j = 0; j < n; j++)
         {
            cin>>a[i][j];
         }
      }
      int x,y;
      cin>>x>>y;
      start = mp(x,y);
      cin>>x>>y;
      end = mp(x,y);
      ans = 999;
      if(start == end)
      {
         cout<<"1\n";
         continue;
      }
      bfs(start, end);
      cout<<ans<<"\n";
   }
} 