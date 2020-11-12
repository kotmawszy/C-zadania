#include <bits/stdc++.h>
using namespace std;

int l0,p0,l1,p1;
int n,a;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>n;
  for(int i=1;i<=n;i++) {
    cin>>a;
    if(a==0) {
      if(l0==0) l0=i;
      p0=i;
    } else {
      if(l1==0) l1=i;
      p1=i;
    }
  }
  cout<<max(p0-l1,p1-l0);
}
