#include <bits/stdc++.h>
using namespace std;

int n,m,a,b,c;
vector<int>* g;
bool ans;

int getDist(int x, int y) {
  queue<int> q;
  int d[n];
  for(int i=1;i<=n;i++) d[i]=0;
  q.push(x);
  d[x]=1;
  while(!q.empty()) {
    int v = q.front();
    q.pop();
    if(d[v]==0) continue;
    for(int w : g[v]) {
      if(d[w]!=0) continue;
      d[w]=d[v]+1;
      q.push(w);
    }
  }
  return d[y]-1;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>m;
  g = new vector<int>[n+1];
  for(int i=0;i<m;i++) {
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  cin>>a>>b>>c;

  cout<<(getDist(a,b) == getDist(a,c) + getDist(c,b) ? "TAK" : "NIE");
}
