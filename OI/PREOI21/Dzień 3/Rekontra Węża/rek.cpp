#include <bits/stdc++.h>
using namespace std;

long long dp[2][20001];
int n,m;
int p;
unsigned short x[20001],y[20001];

bitset<20001> bs[3001];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>m>>p;
  for(int i=1;i<=n;i++) cin>>x[i];
  for(int i=1;i<=m;i++) cin>>y[i];

  if(m>=3001) {
    for(int i=1;i<=m;i++) {
      dp[i%2][0]=0;
      for(int j=1;j<=n;j++) {
        dp[i%2][j] = max(dp[i%2][j-1],dp[1-i%2][j]) + (x[j]+y[i])%p;
      }
    }
    cout<<dp[m%2][n]<<"\n";
    cout<<"nie_wiem_bo_nie_umiem_odtwarzac_sciezki_na_tak_malej_pamieci\n";
    return 0;
  }
  for(int i=1;i<=m;i++) {
    dp[i%2][0]=0;
    for(int j=1;j<=n;j++) {
      dp[i%2][j] = (x[j]+y[i])%p;
      if(dp[i%2][j-1] > dp[1-i%2][j]) {
        dp[i%2][j] += dp[i%2][j-1];
        bs[i][j] = 1;
      } else dp[i%2][j] += dp[1-i%2][j];
    }
  }
  cout<<dp[m%2][n]<<"\n";
  int i=m,j=n;
  string ans="";
  while(i!=1 || j!=1) {
    if(i==1) {
      ans = "P" + ans;
      j--;
      continue;
    }
    if(j==1) {
      ans = "G" + ans;
      i--;
      continue;
    }
    if(bs[i][j]) {
      j--;
      ans = "P" + ans;
    } else {
      i--;
      ans = "G" + ans;
    }
  }
  cout<<ans;
}
