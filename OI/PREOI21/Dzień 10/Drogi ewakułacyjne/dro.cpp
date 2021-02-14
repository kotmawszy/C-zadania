#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int>* g;
vector<int>* gt;
set<int>* gm;
set<int>* gmt;
int a,b;
vector<int> t;
int* c;
int cc;
bool* vis;
int* h;
int* fh;
int INF = numeric_limits<int>::max();

void dfs1(int v) {
  if(vis[v]) return;
  vis[v]=1;
  for(int u : g[v]) dfs1(u);
  t.push_back(v);
}
void dfs2(int v) {
  if(c[v]) return;
  c[v]=cc;
  for(int u : gt[v]) dfs2(u);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>m;
  g = new vector<int>[n+1];
  gt = new vector<int>[n+1];
  gm = new set<int>[n+1];
  gmt = new set<int>[n+1];
  vis = new bool[n+1];
  c = new int[n+1];
  h = new int[n+1];
  fh = new int[n+1];
  for(int i=0;i<m;i++) {
    cin>>a>>b;
    g[a].push_back(b);
    gt[b].push_back(a);
  }
  for(int i=1;i<=n;i++) vis[i]=0,c[i]=0,h[i]=0;
  for(int i=1;i<=n;i++) if(!vis[i]) dfs1(i);
  for(int i=n-1;i>=0;i--) if(c[t[i]]==0) {
    cc++;
    dfs2(t[i]);
  }

  for(int i=1;i<=n;i++) {
    for(int u : g[i]) {
      if(c[i]!=c[u]) gm[c[i]].insert(c[u]);
      gmt[c[u]].insert(c[i]);
    }
  }

  list<pair<int,int> > l;
  for(int i=1;i<=cc;i++) {
    vis[i]=0;
    if(gm[i].size()==0) {
      l.push_front({i,1});
    }
  }
  while(!l.empty()) {
    int v = l.front().first;
    int d = l.front().second;
    l.pop_front();
    if(vis[v]) continue;
    h[v]=d;
    vis[v]=1;
    for(int u : gm[v]) l.push_front({u,d});
    for(int u : gmt[v]) l.push_back({u,d+1});
  }


  for(int i=1;i<=n;i++) fh[i]=h[c[i]];
  int mx = 0;
  for(int i=1;i<=n;i++) mx = max(mx,fh[i]);
  cout<<mx<<"\n";
  for(int i=1;i<=n;i++) cout<<fh[i]-1<<" "; cout<<"\n";
}
