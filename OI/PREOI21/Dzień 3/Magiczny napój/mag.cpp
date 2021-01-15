#include <bits/stdc++.h>
using namespace std;

int v,n,m;
vector<int>* g;
int a,b;
int* vis;
int currsubset;
bool hasCycle;
pair<int,int>* dg;
int maxS;
stack<int> st;

void dfs(int v) {
  if(vis[v]) return;
  vis[v]=1;
  for(int w : g[v]) {
    if(vis[w]==1) hasCycle = 1;
    dfs(w);
  }
  vis[v]=2;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>v>>n>>m;
  g = new vector<int>[v+1];
  vis = new int[v+1];
  dg = new pair<int,int>[m];

  while(n--) {
    cin>>a>>b;
    g[a].push_back(b);
  }
  for(int i=0;i<m;i++) {
    cin>>dg[i].first>>dg[i].second;
  }

  for(currsubset=1;currsubset<(1<<m);currsubset++) {
    int s=0;
    for(int i=1;i<=v;i++) vis[i]=0;
    int i=0;
    for(int j=currsubset;j;j>>=1) {
      if(j&1) {
        st.push(dg[i].first);
        g[dg[i].first].push_back(dg[i].second);
        s++;
      }
      i++;
    }

    hasCycle = 0;
    for(int u=1;u<=v;u++) if(vis[u]==0) dfs(u);
    if(!hasCycle) maxS = max(maxS, s);

    while(!st.empty()) {
      g[st.top()].pop_back();
      st.pop();
    }
  }

  cout<<maxS;
}
