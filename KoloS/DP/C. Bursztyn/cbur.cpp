#include <bits/stdc++.h>
using namespace std;

int n,m,k;
long long pref[1001][1001];
int a;
long long mx = 0;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>m>>k;
  for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) {
      cin>>a;
      pref[i][j]=a+pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1];
  }
  for(int i=k;i<=n;i++) for(int j=k;j<=m;j++)
      mx = max(mx,pref[i][j]-pref[i-k][j]-pref[i][j-k]+pref[i-k][j-k]);
  cout<<mx;
}
