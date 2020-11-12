#include <bits/stdc++.h>
using namespace std;

int n,q,a,b,r;
int arr[2009][2009];
long long pfx[2009][2009];

long long getPFX(int i, int j) {
  if(j>2*n-1) j=2*n-1;
  if(j<1) return 0;
  if(i>2*n-1) i=2*n-1;
  if(i<1) return 0;
  return pfx[i][j];
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin>>n>>q;
  for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) {
    cin>>arr[i+j-1][j-i+n];
  }

  for(int i=1;i<2*n;i++) pfx[i][1]=arr[i][1]+pfx[i-1][1];
  for(int i=1;i<2*n;i++) pfx[1][i]=arr[1][i]+pfx[1][i-1];
  for(int i=2;i<2*n;i++) for(int j=2;j<2*n;j++) pfx[i][j]=pfx[i-1][j]+pfx[i][j-1]-pfx[i-1][j-1]+arr[i][j];

  int i,j;
  while(q--) {
    cin>>a>>b>>r;
    i=a+b-1;
    j=b-a+n;
    cout << getPFX(i+r,j+r) - getPFX(i-r-1,j+r) - getPFX(i+r,j-r-1) + getPFX(i-r-1,j-r-1) << "\n";
  }
}
