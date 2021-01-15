#include <bits/stdc++.h>
using namespace std;

int t,n,m;
string in;
bool board[303][303];
vector<int> g[91003];
int v;
int vis[91003];
int match[91003];
int nr;
int inz;
int iw;

bool ma(int x) {
  vis[x] = nr;
  for(int w : g[x])
    if(!match[w]) {
      match[w] = x;
      inz++;
      return 1;
    }
  for(int w : g[x])
    if(vis[match[w]] != nr && ma(match[w])) {
      match[w] = x;
      return 1;
    }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>t;
  for(int tt=1;tt<=t;tt++) {
    iw=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
      cin>>in;
      for(int j=1;j<=m;j++) {
        board[i][j]=(in[j-1]=='.');
        if(board[i][j]) {
          iw++;
          if(i>1 && board[i-1][j]) {
            g[i*m+j-1].push_back((i-1)*m+j-1);
            g[(i-1)*m+j-1].push_back(i*m+j-1);
          }
          if(j>1 && board[i][j-1]) {
            g[i*m+j-1].push_back(i*m+j-2);
            g[i*m+j-2].push_back(i*m+j-1);
          }
        }
        vis[i*m+j-1]=0;
        match[i*m+j-1]=0;
      }
    }
    if(iw==n*m) {
      if(n%2 && m%2) cout<<"Piotr\n";
      else cout<<"Krzysztof\n";
      for(int i=m;i<=(n+1)*m-1;i++) g[i].clear();
      continue;
    }
    if(iw==0) {
      cout<<"Krzysztof\n";
      for(int i=m;i<=(n+1)*m-1;i++) g[i].clear();
      continue;
    }
    inz=0;
    nr=1;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(board[i][j] && vis[i*m+j-1]==0) {
      ma(i*m+j-1);
      nr++;
    }
    if(iw==inz) cout<<"Krzysztof\n";
    else cout<<"Piotr\n";

    for(int i=m;i<=(n+1)*m-1;i++) g[i].clear();
  }
}
