#include <bits/stdc++.h>
using namespace std;

int n;
stack<pair<int,int> > s;
set<int>* g;
vector<int>* gk;
set<int>* gt;
int a,b;
int* c;
bool ans=1;

void dfs(int v) {
  for(int u : g[v]) {
    if(c[u]==0) {
      c[u]=3-c[v];
      dfs(u);
    } else if(c[u]==c[v]) ans=0;
  }
  for(int u : gt[v]) {
    if(c[u]==0) {
      c[u]=3-c[v];
      dfs(u);
    } else if(c[u]==c[v]) ans=0;
  }
}

void f(int a, int b) {
  if(gk[a].empty()) return;
  if(gk[a][gk[a].size()-1]==b) gk[a].pop_back();
  if(gk[a].empty()) return;
  int d = gk[a][gk[a].size()-1];

  if(c[a]==1) {
    if(c[b]==2) c[d]=3;
    else c[d]=2;
  } else if(c[a]==2) {
    if(c[b]==1) c[d]=3;
    else c[d]=1;
  } else {
    if(c[b]==1) c[d]=2;
    else c[d]=1;
  }

  f(a,d);
  f(d,b);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n;
  g = new set<int>[n+1];
  gt = new set<int>[n+1];
  gk = new vector<int>[n+1];
  c = new int[n+1];
  int ik=0;
  for(int i=1;i<=n;i++) {
    c[i]=0;
    cin>>a>>b;
    while(a>0) {
      pair<int,int> p = s.top();
      s.pop();
      if(p.second-a>0) s.push({p.first,p.second-a});
      a-=p.second;
      g[p.first].insert(i);
      gt[i].insert(p.first);
      ik++;
    }
    if(b) s.push({i,b});
  }

  if(ik==0) {
    cout<<"1\n";
    for(int i=1;i<=n;i++) cout<<"1 ";
    return 0;
  }

  for(int i=1;i<=n;i++) if(c[i]==0) {c[i]=1;dfs(i);}

  if(ans) {
    cout<<"2\n";
    for(int i=1;i<=n;i++) cout<<c[i]<<" ";
    return 0;
  }
  for(int i=1;i<=n;i++) c[i]=0;
  for(int i=1;i<n;i++) g[i].insert(i+1);
  for(int i=1;i<=n;i++) {
    for(set<int>::iterator j = g[i].begin(); j != g[i].end(); j++) {
      gk[i].push_back(*j);
    }
  }

  c[1]=1;
  c[n]=2;
  f(1,n);

  cout<<"3\n";
  for(int i=1;i<=n;i++) cout<<(c[i])<<" ";
}
