#include <bits/stdc++.h>
using namespace std;

int n;
int* cost;
int* p;
vector<pair<int,int> >* gp;
int a,b,c;
vector<pair<double,pair<int,int> > >* kd;
int* d;
long long currd;
double sum;
int* iw;

void dfs0(int v) {
  iw[v]=1;
  for(pair<int,int> u : gp[v]) if(p[u.first]==0) {
    p[u.first]=v;
    dfs0(u.first);
    iw[v]+=iw[u.first];
  }
}

void dfs(int v) {
  for(pair<int,int> u : gp[v]) if(p[u.first]==0) {
    p[u.first]=v;
    cost[u.first]+=u.second;
    dfs(u.first);
    cost[v]+=cost[u.first];
    double jdjd = cost[u.first];
    jdjd /= iw[u.first];
    kd[v].push_back({jdjd,{u.first,u.second}});
  }
  sort(kd[v].begin(),kd[v].end());
}

void dfs2(int v) {
  d[v]=currd;
  int _size = kd[v].size();
  for(int i=0;i<_size;i++) {
    currd+=kd[v][i].second.second;
    dfs2(kd[v][i].second.first);
    currd+=kd[v][i].second.second;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n;
  gp = new vector<pair<int,int> >[n+1];
  kd = new vector<pair<double,pair<int,int> > >[n+1];
  p = new int[n+1];
  d = new int[n+1];
  iw = new int[n+1];
  cost = new int[n+1];
  for(int i=1;i<n;i++) {
    cin>>a>>b>>c;
    gp[a].push_back({b,c});
    gp[b].push_back({a,c});
  }
  for(int i=1;i<=n;i++) p[i]=0;
  p[1]=1;
  dfs0(1);
  for(int i=1;i<=n;i++) p[i]=0;
  cost[1]=0;
  p[1]=1;
  dfs(1);
  dfs2(1);


  for(int i=1;i<=n;i++) sum+=d[i];
  sum/=(n-1);
  cout<<fixed<<setprecision(6)<<sum<<"\n";
}
