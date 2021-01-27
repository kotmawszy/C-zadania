#include <bits/stdc++.h>
using namespace std;

int pfx[1007][1007];
int a;
int n,m;

int main() {
  cin>>n>>m;

  for(int i=1;i<=n;i++) {
    for(int j=1;j<=m;j++) {
      cin>>a;
      pfx[i][j]=max(pfx[i-1][j],pfx[i][j-1])+a;
    }
  }
  cout<<pfx[n][m]<<"\n";
}
