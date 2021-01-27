#include <bits/stdc++.h>
using namespace std;

long long pfx[1000001];
int a,b;
int n,q;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  cin>>n;
  for(int i=1;i<=n;i++) {
    cin>>a;
    pfx[i]=pfx[i-1]+a;
  }
  cin>>q;
  while(q--) {
    cin>>a>>b;
    cout<<pfx[b]-pfx[a-1]<<"\n";
  }
}
