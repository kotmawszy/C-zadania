#include <bits/stdc++.h>
using namespace std;

int n,q;
int* g;
vector<int>* gt;
int a,b;
int components;
int* component;
int* cycleElement;
bool* vis;
int* cycleLength;
int* parent[20];
int* depth;

void dfsComponent(int v) {
  if(vis[v]) return;
  vis[v]=1;
  component[v]=components;
  dfsComponent(g[v]);
  for(int u : gt[v]) dfsComponent(u);
}

int dfsCycle(int v) {
  if(vis[v]) {
    cycleElement[v]=1;
    return v;
  }
  vis[v]=1;
  int u = dfsCycle(g[v]);
  if(cycleElement[g[v]] && u && !cycleElement[v]) {
    cycleElement[v]=cycleElement[g[v]]+1;
  }
  if(u==v) {
    cycleLength[component[v]]=cycleElement[g[v]];
    return 0;
  }
  return u;
}

void dfsDepth(int v) {
  if(cycleElement[v]) depth[v]=1;
  else depth[v] = depth[g[v]]+1;
  for(int u : gt[v]) {
    if(cycleElement[u]) continue;
    dfsDepth(u);
  }
}

int lca(int x, int y) {
  if(depth[x] > depth[y]) swap(x,y); // y ma być głębiej
  for(int i=19;i>=0;i--)
    if(depth[parent[i][y]] >= depth[x])
      y = parent[i][y];
  for(int i=19;i>=0;i--)
    if(parent[i][x] != parent[i][y]) {
      x = parent[i][x];
      y = parent[i][y];
    }
  if(x==y) return x;
  return parent[0][x];
}

int dist(int x, int y) {
  int z = cycleElement[x]-cycleElement[y];
  if(z<0) z+=cycleLength[component[x]];
  return z;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>n>>q;
  g = new int[n+1];
  gt = new vector<int>[n+1];
  component = new int[n+1];
  vis = new bool[n+1];
  cycleElement = new int[n+1];
  depth = new int[n+1];
  for(int i=0;i<20;i++) parent[i]=new int[n+1];
  for(int i=1;i<=n;i++) {
    cin>>a;
    g[i]=a;
    gt[a].push_back(i);
    vis[i]=0;
    cycleElement[i]=0;
  }

  for(int i=1;i<=n;i++) if(!vis[i]) {components++;dfsComponent(i);}

  for(int i=1;i<=n;i++) vis[i]=0;
  cycleLength = new int[components+1];
  for(int i=1;i<=components;i++) cycleLength[i]=0;

  for(int i=1;i<=n;i++) {
    if(!cycleLength[component[i]]) {
      dfsCycle(i);
    }
  }

  for(int i=1;i<=n;i++) {
    if(cycleElement[i]) parent[0][i]=i;
    else parent[0][i]=g[i];
  }
  for(int i=1;i<20;i++) for(int j=1;j<=n;j++) parent[i][j] = parent[i-1][parent[i-1][j]];

  for(int i=1;i<=n;i++) if(cycleElement[i]) {
    dfsDepth(i);
  }

  for(int i=1;i<=q;i++) {
    cin>>a>>b;
    if(component[a]!=component[b]) {cout<<"-1 -1\n";continue;}
    if(parent[19][a]==parent[19][b]) {
      int l = lca(a,b);
      cout<<depth[a]-depth[l]<<" "<<depth[b]-depth[l]<<"\n";
      continue;
    }
    int x = depth[a]-1;
    int y = depth[b]-1;
    int px = parent[19][a];
    int py = parent[19][b];
    int dxy = dist(px,py);
    int dyx = dist(py,px);
    //cout<<x<<" "<<y<<" "<<dxy<<" "<<dyx<<"    ";
    int maxx = max(x+dxy,y);
    int maxy = max(x,y+dyx);
    int minx = min(x+dxy,y);
    int miny = min(x,y+dyx);

    if(maxx != maxy) {
      if(maxx<maxy) {
        cout<<x+dxy<<" "<<y<<"\n";
      } else {
        cout<<x<<" "<<y+dyx<<"\n";
      }
    } else if(minx != miny) {
      if(minx<miny) {
        cout<<x+dxy<<" "<<y<<"\n";
      } else {
        cout<<x<<" "<<y+dyx<<"\n";
      }
    } else {
      if(x+dxy<=y+dyx) {
        cout<<x+dxy<<" "<<y<<"\n";
      } else {
        cout<<x<<" "<<y+dyx<<"\n";
      }
    }
  }
}
