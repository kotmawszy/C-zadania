#include <bits/stdc++.h>
using namespace std;

long long* k; // koszt metalu
vector<pair<int,long long> >* g; // graf koszów zamian {wierzchołek,krawędź}
long long* d; // dystans do wierzchołka
vector<pair<int,long long> >* gt; // graf kosztów zamian z powrotem {wierzchołek,krawędź}
long long* dt; // dystans do wierzchołka
int n;long long m; // ilość wierzchołków, krawędzi
int a,b; long long c; // wczytywanie: wierzchołek wychodzący, wierzchołek wchodzący, długość krawędzi
set<pair<long long,int> > s; // {krawędź,wierzchołek}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>n;
  k = new long long[n+1];
  d = new long long[n+1];
  dt = new long long[n+1];
  g = new vector<pair<int,long long> >[n+1];
  gt = new vector<pair<int,long long> >[n+1];
  for(int i=0;i<=n;i++) d[i]=dt[i]=LONG_MAX;
  for(int i=1;i<=n;i++) cin>>k[i];
  cin>>m;
  while(m--) {
    cin>>a>>b>>c;
    g[a].push_back({b,c});
    gt[b].push_back({a,c});
  }

  d[1]=0;
  s.insert({0,1});
  while(!s.empty()) {
    int v = s.begin() -> second;
    s.erase(s.begin());
    for(pair<int,long long> p : g[v]) {
      int u = p.first;
      long long x = p.second;

      if(d[v] + x < d[u]) {
        s.erase({d[u], u});
        d[u] = d[v] + x;
        s.insert({d[u],u});
      }
    }
  }

  dt[1]=0;
  s.insert({0,1});
  while(!s.empty()) {
    int v = s.begin() -> second;
    s.erase(s.begin());
    for(pair<int,long long> p : gt[v]) {
      int u = p.first;
      long long x = p.second;

      if(dt[v] + x < dt[u]) {
        s.erase({dt[u], u});
        dt[u] = dt[v] + x;
        s.insert({dt[u],u});
      }
    }
  }
  //for(int i=1;i<=n;i++) cout<<d[i]<<" "; cout<<"\n";
  //for(int i=1;i<=n;i++) cout<<dt[i]<<" "; cout<<"\n";
  m = LONG_MAX;
  for(int i=1;i<=n;i++) m = min(m, d[i]+k[i]/2+dt[i]);
  cout<<m;
}
