#include <bits/stdc++.h>
using namespace std;

struct Query {
  int a,b,c;
  bool operator<(const Query& other) {
    return this->c < other.c;
  }
  Query() {
    cin>>a>>b>>c;
  }
};

int n,m;
vector<int>* g;
int a,b,c;
int* p; // parent
int* d; // głębokość
int* fau; // parent w find and union
long long* cost; // koszt dołączenie danego wierzchołka

int Find(int v) {
  if(fau[v] != v) fau[v]=Find(fau[v]);
  return fau[v];
}
void Union(int a, int b, long long c) {
  a = Find(a);
  b = Find(b);
  if(a==b) return;
  if(d[a]<d[b]) swap(a,b);
  fau[a]=b;
  cost[b] += cost[a] + c;
}

void connect(int a, int b, long long c) {
  while(a!=b) {
    if(d[a]<d[b]) swap(a,b);
    Union(a,p[a],c);
    a = Find(a);
  }
}

void dfs(int v) {
  for(int u : g[v]) if(p[u]==0) {
    p[u]=v;
    d[u]=d[v]+1;
    dfs(u);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>m;
  g = new vector<int>[n+1];
  p = new int[n+1];
  d = new int[n+1];
  cost = new long long[n+1];
  fau = new int[n+1];
  for(int i=1;i<n;i++) {
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  for(int i=1;i<=n;i++) p[i]=0,fau[i]=i,cost[i]=0;
  p[1]=d[1]=1;
  dfs(1);

  Query q[m];
  sort(q,q+m);
  for(int i=0;i<m;i++) {
    connect(q[i].a,q[i].b,q[i].c);
  }
  int s=0;
  for(int i=1;i<=n;i++) if(Find(i)==1) s++;
  cout<<s<<" "<<cost[1]<<"\n";
}
