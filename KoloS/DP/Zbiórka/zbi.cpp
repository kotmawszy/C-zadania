#include <bits/stdc++.h>
using namespace std;

int n,c,w,m;
int dp[10001];
int INF = numeric_limits<int>::max();

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>c>>n;
  for(int i=1;i<10001;i++) dp[i]=INF;
  while(n--) {
    cin>>m>>w;
    for(int i=0;i<=c;i++) {
      if(dp[i]!=INF && i+w<10001) dp[i+w]=min(dp[i+w],dp[i]+m);
    }
  }
  if(dp[c]==INF) cout<<"NIEMOZLIWE";
  else cout<<dp[c];
}
