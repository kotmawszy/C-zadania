#include <bits/stdc++.h>
using namespace std;

int n;
int* arr;
int a,va;
bool* dp[3];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n;
  arr = new int[n+1];
  for(int i=1;i<=n;i++) cin>>arr[i];
  for(int i=0;i<3;i++) dp[i]=new bool[n+1];


  for(int i=1;i<=n;i++) if(arr[i]>=va) va=arr[i],a=i;

  int mi = INT_MAX;
  for(int b=1;b<=n;b++) {
    for(int c=1;c<=n;c++) {
      if(b==a || c==a) continue;

      dp[0][1]=dp[1][1]=dp[2][1]=1;
      for(int i=2;i<=n;i++) {
        dp[0][i] = (arr[a]>=arr[i] && (dp[1][i-1]||dp[2][i-1]));
        dp[1][i] = (arr[b]>=arr[i] && (dp[0][i-1]||dp[2][i-1]));
        dp[2][i] = (arr[c]>=arr[i] && (dp[0][i-1]||dp[1][i-1]));
      }
      if(dp[0][n]||dp[1][n]||dp[2][n]) {
        int x = arr[a]+arr[b]+arr[c];
        if(x<mi) {
          mi=x;
        }
      }
    }
  }
  if(a%2) {
    int mx = 0;
    for(int i=2;i<=n;i+=2) mx=max(mx,arr[i]);
    mi=min(mi,arr[a]+mx);
  } else {
    int mx = 0;
    for(int i=1;i<=n;i+=2) mx=max(mx,arr[i]);
    mi=min(mi,arr[a]+mx);
  }
  cout<<mi;
}
