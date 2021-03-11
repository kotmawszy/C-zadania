#include <bits/stdc++.h>
using namespace std;
void pemtla(int n) {
  double a;
  cin>>a;
  long long l = round(a*1000000);
  long long m = 1000000;
  long long gcd = __gcd(l,m);
  l/=gcd;
  m/=gcd;
  if(l==0) cout<<0<<"\n";
  else cout<<l<<"/"<<m<<"\n";
  if(n>1) pemtla(n-1);
}
int main() {
  int n;
  cin>>n;
  pemtla(n);
}
