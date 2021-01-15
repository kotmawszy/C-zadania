#include <bits/stdc++.h>
using namespace std;

int dp[101][101];

int f(int n, int m) {
  if(n==m) return 1;
  if(dp[n][m]) return dp[n][m];

  int minn = numeric_limits<int>::max();
  if(m<n) swap(n,m);
  for(int i=1;i<=n/2;i++) minn=min(minn, f(m,i)+f(m,n-i));
  for(int i=1;i<=m/2;i++) minn=min(minn, f(i,n)+f(m-i,n));
  dp[n][m]=minn;
  return minn;
}

int main() {
  int n,m;
  cin>>n>>m;
  for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) f(i,j);
  cout<<f(n,m);
}
