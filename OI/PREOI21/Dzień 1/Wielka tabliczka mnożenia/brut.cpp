#include <bits/stdc++.h>
using namespace std;

int n,m;
int* x;
int* y;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>m;

  x = new int[m];
  y = new int[n];

  for(int i=0;i<n;i++) cin>>x[i];
  for(int i=0;i<m;i++) cin>>y[i];

  tab = new long long*[n];
  len = new int*[n];
  rlen = new int[n];
  for(int i=0;i<n;i++) {
    tab[i] = new long long[m];
    len[i] = new int[m];
    for(int j=0;j<m;j++) {
      tab[i][j] = (long long)x[i] * (long long)y[j];
      int x=0;
      long long y=tab[i][j];
      for(;y;x++) y/=10;
      len[i][j]=x;
      if(j) len[i][j]+=len[i][j-1];
    }
    rlen[i] = len[i][m-1];
    if(i) rlen[i]+=rlen[i-1];
  }


  int q;
  cin>>q;
  while(q--) {
    cin>>a;
    int b = (lower_bound(rlen,rlen+n,a)-rlen);
    if(b>=n) {
      cout<<"x";
      continue;
    }
    int c = (b>0 ? a-rlen[b-1] : a);
    int d = (lower_bound(len[b],len[b]+m,c)-len[b]);
    int e = len[b][d]-c;
    long long w = tab[b][d];
    for(int i=0;i<e;i++) w/=10;
    cout<<w%10;
  }

}
