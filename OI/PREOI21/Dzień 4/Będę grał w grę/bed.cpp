#include <bits/stdc++.h>
using namespace std;

int t,n,m;
string in;
bool board[303][303];
vector<pair<int,int> > g[303][303];
int v;
int vis[303][303];
pair<int,int> match[303][303];
int nr;
int l,r;
pair<int,int> z;

bool ma(int i, int j) {
  vis[i][j] = nr;
  for(pair<int,int> w : g[i][j])
    if(match[w.first][w.second] == z) {
      match[i][j] = {w.first,w.second};
      match[w.first][w.second] = {i,j};
      return 1;
    }
  for(pair<int,int> w : g[i][j])
    if(vis[match[w.first][w.second].first][match[w.first][w.second].second] != nr && ma(match[w.first][w.second].first, match[w.first][w.second].second)) {
      match[w.first][w.second] = {i,j};
      match[i][j] = {w.first,w.second};
      return 1;
    }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  z = {0,0};

  cin>>t;
  for(int tt=1;tt<=t;tt++) {
    cin>>n>>m;
    l=r=0;
    for(int i=1;i<=n;i++) {
      cin>>in;
      for(int j=1;j<=m;j++) {
        board[i][j]=(in[j-1]=='.');
        if(board[i][j]) {
          if((i+j)%2) l++;
          else r++;
        }
        g[i][j].clear();
        vis[i][j]=0;
        match[i][j]={0,0};
      }
    }
    if(l!=r) {
      cout<<"Piotr\n";
      continue;
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) {
      if(board[i][j]) {
        if(i<n && board[i+1][j]) g[i][j].push_back({i+1,j});
        if(i>1 && board[i-1][j]) g[i][j].push_back({i-1,j});
        if(j<m && board[i][j+1]) g[i][j].push_back({i,j+1});
        if(j>1 && board[i][j-1]) g[i][j].push_back({i,j-1});
      }
    }

    /*for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++) {
        cout<<"("<<i<<","<<j<<"): ";
        for(pair<int,int> w : g[i][j]) cout<<"("<<w.first<<","<<w.second<<") ";
        cout<<"\n";
      }*/

    nr=0;
    bool p=0;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) {
      nr++;
      if(board[i][j] && match[i][j]==z && !ma(i,j)) p=1;
    }
    if(p) cout<<"Piotr\n";
    else cout<<"Krzysztof\n";
  }
}
