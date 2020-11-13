#include <bits/stdc++.h>
using namespace std;

int n,m;
int a,b;
set<int> g[1000007];
pair<int,int> deg[1000007];
long long s;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>n>>m;
  while(m--) {
    cin>>a>>b;
    g[a].insert(b);
    g[b].insert(a);
  }
  for(int i=1;i<=n;i++) deg[i] = make_pair(g[i].size(),i);
  sort(deg+1,deg+n+1);

  for(int i=1;i<=n;i++) {
    int v = deg[i].second;
    for(set<int>::iterator j = g[v].begin(); j != g[v].end(); j++) {
      for(set<int>::iterator k = g[v].begin(); k != g[v].end(); k++) {
        if(g[*j].find(*k)==g[*j].end()) continue;
        s++;
      }
    }
    for(set<int>::iterator j = g[v].begin(); j != g[v].end(); j++) {
      g[*j].erase(v);
    }
    g[v].clear();
  }
  cout<<s/2;
}
