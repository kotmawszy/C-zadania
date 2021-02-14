#include <bits/stdc++.h>
using namespace std;

class TwoSAT {
  int n;
  vector<vector<int> > g, gt;
  vector<bool> used;
  vector<int> order, comp;
  vector<bool> assignment;

  void dfs1(int v) {
      used[v] = true;
      for(int u : g[v]) if(!used[u]) dfs1(u);
      order.push_back(v);
  }
  void dfs2(int v, int cl) {
      comp[v] = cl;
      for(int u : gt[v]) if(comp[u] == -1) dfs2(u, cl);
  }
public:
  bool solve_2SAT() {
      used.assign(n, false);
      for(int i=0;i<n;i++) if(!used[i]) dfs1(i);
      comp.assign(n, -1);
      for(int i=0,j=0;i<n;i++) {
          int v = order[n-i-1];
          if(comp[v]==-1) dfs2(v, j++);
      }
      assignment.assign(n/2, false);
      for(int i=0;i<n;i+=2) {
          if(comp[i]==comp[i + 1]) return false;
          assignment[i/2]=comp[i]>comp[i+1];
      }
      return true;
  }

  void createGraph(int _n) {
    n=2*_n;
    g.resize(n);
    gt.resize(n);
  }
  void addOr(bool notA, int a, bool notB, int b) {
    a--;
    b--;
    g[2*a+(1-notA)].push_back(2*b+notB); gt[2*b].push_back(2*a+(1-notA));
    g[2*b+(1-notB)].push_back(2*a+notA); gt[2*a].push_back(2*b+(1-notB));
  }
  void addOr(int a, int b) {
    addOr(0,a,0,b);
  }
};

int n;
bool ds[2003][2003];
vector<pair<int,int> > g[2003];
pair<int,int> e[4006];
int a,b;
int cv;

void dfs(int v) {
  ds[cv][v]=1;
  for(pair<int,int> u : g[v]) if(ds[cv][u.first]==0) dfs(u.first);
}

bool dasie(int ea, int eb) {
  return ds[ea.second][eb.first] || ds[eb.second][ea.first];
}

int main() {
  cin>>n;
  for(int i=0;i<2*n;i++) {
    cin>>a>>b;
    g[a].push_back({b,i});
    e[i]={a,b};
  }
  for(cv=1;cv<=n;cv++) dfs(cv);

  for(int i=1;i<=n;i++) {
    cout<<i<<": ";
    for(int j=1;j<=n;j++) cout<<ds[i][j]<<" ";
    cout<<"\n";
  }

  for(int i=1;i<=n;i++) {
    cout<<"patrze czy da sie uzyskac "<<i<<"\n";
    TwoSAT ts;
    ts.createGraph(2*i);
    for(int j=0;j<i;j++) ts.addOr(2*j,2*j+1);

  }
}
