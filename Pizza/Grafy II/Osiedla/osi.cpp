#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int>* g;
pair<int,int>* e;
int a,b;
int* order;
int corder;
int* low;
int s;
bool* visk;
int* dir;

void dfs(int v) {
  order[v]=++corder;

  int clow = order[v];
  int ckdp = 0;

  for(int k : g[v]) {
    if(visk[k]) continue;
    visk[k]=1;
    int u = e[k].first==v ? e[k].second : e[k].first;
    dir[k] = (e[k].first==v);
    if(order[u]==0) {
      dfs(u);
      clow = min(clow, low[u]);
    } else {
      clow = min(clow, order[u]);
    }
  }

  low[v]=clow;

  if(low[v]==order[v]) s++;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>n>>m;

  g = new vector<int>[n+1];
  e = new pair<int,int>[m+1];
  order = new int[n+1];
  low = new int[n+1];
  visk = new bool[m+1];
  dir = new int[m+1];

  for(int i=1;i<=n;i++) order[i]=0;

  for(int i=1;i<=m;i++) {
    cin>>a>>b;
    g[a].push_back(i);
    g[b].push_back(i);
    visk[i]=0;
    dir[i]=0;
    e[i]={a,b};
  }
  for(int i=1;i<=n;i++) if(order[i]==0) {
    corder=0;
    dfs(i);
  }

  cout<<s<<"\n";

  for(int i=1;i<=m;i++) cout<<(dir[i] ? ">" : "<");
}
