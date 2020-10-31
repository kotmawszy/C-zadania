#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,a,b;
  cin>>n;
  if(n==1) {
    cin>>n;
    cout<<n;
    return 0;
  }
  cin>>a>>b;
  int x = __gcd(a,b);
  for(n-=2;n--;) {
    cin>>a;
    x = __gcd(x,a);
  }
  cout<<x;
}
