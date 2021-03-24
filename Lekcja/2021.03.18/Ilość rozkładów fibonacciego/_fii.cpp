#include <bits/stdc++.h>
using namespace std;

int fib[46];
int dp[1000007];
int n;

int main() {
  cin>>n;
  fib[0]=1;
  fib[1]=1;
  for(int i=2;i<46;i++) fib[i]=fib[i-2]+fib[i-1];
  dp[0]=1;
  for(int i=1;i<=n;i++) {
    cout<<i<<": ";
    for(int j=1;j<46 && fib[j]<=i;j++) {
      dp[i]+=dp[i-fib[j]];
      cout<<j<<" ";
    }
    cout<<dp[i]<<"\n";
  }
  cout<<dp[n];
}
