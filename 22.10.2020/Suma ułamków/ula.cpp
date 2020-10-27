#include <bits/stdc++.h>
using namespace std;

int main() {
  long long a,b,c,d;
  cin>>a>>b>>c>>d;
  long long m = b/__gcd(b,d)*d;
  a*=m/b;
  c*=m/d;
  long long l = a+c;
  long long g = __gcd(l,m);
  cout<<l/g<<"/"<<m/g;
}
