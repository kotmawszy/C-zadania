#include <bits/stdc++.h>
using namespace std;

enum Kolor {NONE, RED, BLACK};
z
int n,m;
vector<int>* g;
enum Kolor* c;
int a,b;
bool o;

void dfs(int v, enum Kolor k) {
  if(c[v]!=NONE) {
    if(c[v]!=k) o=1;
    return;
  }
  c[v] = k;
  for(int w : g[v]) dfs(w, k==RED ? BLACK : RED);
}

int main() {
  cin>>n>>m;
  g = new vector<int>[n];
  c = new Kolor[n];
  for(int i=0;i<n;i++) c[i] = NONE;
  while(m--) {
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  for(int i=0;i<n;i++) if(c[i]==NONE) dfs(i,BLACK);
  if(o) cout<<"NOT ";
  cout<<"BICOLORABLE";
}
