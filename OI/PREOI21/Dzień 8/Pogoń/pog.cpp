#include <bits/stdc++.h>
using namespace std;

const int INF = numeric_limits<int>::max();
int n;
vector<int> g[200005];
int p[20][200005];
int d[200005];
int a,b,x,y;
int q;
int t[200005];
int rt[200005];
int titerator;
int maxd[200005];
int lv=1;
int nochild[200005];
int jd[20005];

int lca(int a, int b) {
  if(d[a]<d[b]) swap(a,b);
  for(int i=19;i>=0;i--) if(d[p[i][a]]>=d[b]) a=p[i][a];
  if(a==b) return a;
  for(int i=19;i>=0;i--) if(p[i][a]!=p[i][b]) a=p[i][a],b=p[i][b];
  return p[0][a];
}

void dfs(int v) {
  t[++titerator]=v;
  maxd[v]=d[v];
  nochild[v]=1;
  for(int u : g[v]) if(p[0][u]==0) {
    p[0][u]=v;
    d[u]=d[v]+1;
    dfs(u);
    maxd[v]=max(maxd[v],maxd[u]);
    nochild[v]+=nochild[u];
  }
}
void dfs2(int v) {
  if(v==1) jd[v]=0;
  else jd[v]=max(jd[v],jd[p[0][v]]+1);

  multiset<int> s;
  for(int u : g[v]) if(u!=p[0][v]) s.insert(maxd[u]-d[v]+1);
  for(int u : g[v]) if(u!=p[0][v]) {
    auto xd = s.find(maxd[u]-d[v]+1);
    if(xd==s.end()) continue;
    s.erase(xd);
    if(!s.empty()) jd[u]=max(jd[u],*--s.end());
    s.insert(maxd[u]-d[v]+1);
  }
  for(int u : g[v]) if(u!=p[0][v]) dfs2(u);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n;

  for(int i=1;i<n;i++) {
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  d[1]=1;
  p[0][1]=1;
  dfs(1);
  for(int i=1;i<20;i++) for(int j=1;j<=n;j++) p[i][j]=p[i-1][p[i-1][j]];

  for(int i=1;i<=n;i++) rt[t[i]]=i;

  dfs2(1);

  cin>>q;
  while(q--) {
    cin>>x>>y;
    if(x==y) {
      cout<<"0\n";
      continue;
    }
    int l = lca(x,y);
    int o = d[x]+d[y]-2*d[l];
    if(d[y]>=d[x]) {
      int irs = (o-1)/2;// ile razy skoczyc do gory uciekajacym
      int irsd = o-irs;// ile razy skacze drugi (wynik to bedzie to + maxd[dks])
      int dks = y;//do ktorego skoczyl
      for(int i=19;i>=0;i--) {
        int z = pow(2,i);
        if(z<=irs) {
          irs-=z;
          dks=p[i][dks];
        }
      }
      cout<<irsd+maxd[dks]-d[dks]<<"\n";
    } else {
      int irs = (o)/2;// ile razy skoczyc do gory goniącym
      int dks = x;//do ktorego skoczyl
      int mx = irs;
      for(int i=19;i>=0;i--) {
        int z = pow(2,i);
        if(z<=irs) {
          irs-=z;
          dks=p[i][dks];
        }
      }
      mx += jd[dks];
      cout<<mx<<"\n";
    }
  }
}
