#include <bits/stdc++.h>
using namespace std;

int n,m,k;
int* c;
vector<int>* g;
int a,b;
int** dp;

int main() {
  cin>>n>>m>>k;

  c = new int[n+1];
  g = new vector<int>[n+1];
  dp = new int*[n+1];
  for(int i=1;i<=n;i++) dp[i] = new int[1<<k];

  for(int i=1;i<=n;i++) cin>>c[i];
  while(m--) {
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  for(int i=1;i<(1<<k);i++) {
    for(int v=1;v<=n;v++) {
      if(i>>(c[v]-1)&1) {
        dp[v][i]=1;
        for(int u : g[v]) {
          dp[v][i] += dp[u][i^(1<<(c[v]-1))];
        }
      }
    }
  }

  long long s = -n;
  for(int v=1;v<=n;v++) s+=dp[v][(1<<k)-1];
  cout<<s;

}
