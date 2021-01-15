#include <bits/stdc++.h>
using namespace std;

int n,m;
int a;
int root;
vector<int>g[1000007];
int gt[1000007];
int depth[1000007];
int sre[1000007];
int maxdist;
int najdalszy;
bool vis[1000007];

void depthDFS(int v, int o=0) {
  if(o>maxdist) {
    maxdist = o;
    najdalszy = v;
  }
  for(int w : g[v]) depthDFS(w,o+1);
}

void dfs(int v, int o=0) {
  if(vis[v]) return;
  vis[v]=1;
  if(o>maxdist) {
    maxdist = o;
    najdalszy = v;
  }
  for(int w : g[v]) dfs(w,o+1);
  if(gt[v]!=0) dfs(gt[v],o+1);
}


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  int q;
  cin>>q;
  while(q--) {
      cin>>n;
      for(int i=1;i<=n;i++) {
          cin>>m;

          if(m==1) {
            cin>>a;
            i--;
            n--;
            continue;
          }

          for(int j=1;j<=m;j++) {
            g[j].clear();
            gt[j]=0;
            vis[j]=0;
          }
          for(int j=1;j<=m;j++) {
            cin>>a;
            gt[j]=a;
            if(a==0) root = j;
            else g[a].push_back(j);
          }

          maxdist=0;
          najdalszy=0;
          depthDFS(root);
          depth[i]=maxdist;

          maxdist=0;
          dfs(najdalszy);
          sre[i]=maxdist;
      }
      long long sumadepth = 0;
      for(int i=1;i<=n;i++) sumadepth += 2*depth[i];

      long long maxxx=0;
      long long minnn=numeric_limits<long long>::max();

      for(int i=1;i<=n;i++) {
        long long curr = sumadepth - 2*depth[i] + sre[i];
        maxxx = max(maxxx,curr);
        minnn = min(minnn,curr);
      }
      if(minnn==numeric_limits<long long>::max()) minnn=0;
      cout<<maxxx<<" "<<minnn<<"\n";
  }
}
