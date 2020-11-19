#include <bits/stdc++.h>
using namespace std;

long long n,m,s,a,b;
long long pfx[1000007];

int main() {
  cin>>n>>m;
  for(int i=1;i<=n;i++) {
    cin>>pfx[i];
    pfx[i]+=pfx[i-1];
  }
  while(m--) {
    cin>>a>>b;
    if(pfx[b]-pfx[a-1]>0) s+=pfx[b]-pfx[a-1];
  }
  cout<<s;
}
