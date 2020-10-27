#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c,d;
  cin>>a>>b>>c>>d;
  int m = b/__gcd(b,d)*d;
  a*=m/b;
  c*=m/d;
  cout<<a+b<<"/"<<m;
}
