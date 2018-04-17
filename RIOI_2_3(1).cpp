#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pp pair<int, int>
#define mp make_pair
vector<vector<int> >a, b;
vector<int> key;
int n, ans;
int xcord[] = {-1, 1, 0, 0};
int ycord[] = {0, 0, -1, 1};
int isvalid(pp temp)
{
   if(temp.first >= 0 && temp.first < n && temp.second >=0 && temp.second < n)
      return 1;
   else
      return 0;
}
int bfs(pp start, pp end)
{
   if(!key[a[start.first][start.second]] || !key[a[end.first][end.second]])
   {
      return 0;
   }
   queue<pp> q;
   pp prev, cur;
   q.push(start);
   b[start.first][start.second] = 1;
   while(!q.empty())
   {
      prev = q.front();
      q.pop();
      for(int i = 0; i < 4; i++)
      {
         cur = mp(prev.first + xcord[i], prev.second + ycord[i]);
         if((isvalid(cur) && key[a[cur.first][cur.second]]) && !b[cur.first][cur.second])
         {
            if(cur == end)
            {
               return 1;
            }
            b[cur.first][cur.second] = 1;
            q.push(cur);
         }
      }
   }
   return 0;
}
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int t;
   cin>>t;
   pp start, end;
   while(t--)
   {
      cin>>n;
      a.clear();
      a.resize(n,vector<int>(n));
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
      for(int i = 1; i < 1024; i++)
      {
         key.clear();
         key.resize(10);
         int count = 0;
         for(int j = 0; j < 10; j++)
         {
            if(1<<j & i)
            {
               key[j] = 1;
               count++;
            }
         }
         if(ans > count)
         {
            b.clear();
            b.resize(n, vector<int>(n));
            if(bfs(start, end))
            {
               ans = count;
            }
         }
      }
      cout<<ans<<"\n";
   }
} 