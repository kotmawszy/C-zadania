#include <bits/stdc++.h>
using namespace std;

int arr[1007][1007];
int pfx[1007][1007];
int n,m;

int main() {
  cin>>n>>m;
  for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) {
    cin>>arr[i][j];
  }
  pfx[1][1]=arr[1][1];
  for(int i=2;i<=n;i++) pfx[i][1]=pfx[i-1][1]+arr[i][1];
  for(int i=2;i<=n;i++) pfx[1][i]=pfx[1][i-1]+arr[1][i];
  for(int i=2;i<=n;i++) {
    for(int j=2;j<=m;j++) {
      pfx[i][j]=max(pfx[i-1][j],pfx[i][j-1])+arr[i][j];
    }
  }
  cout<<pfx[n][m];
}
