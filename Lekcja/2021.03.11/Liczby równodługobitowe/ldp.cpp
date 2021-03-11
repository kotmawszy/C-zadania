#include <bits/stdc++.h>
using namespace std;
int f(long long x) {
  if(x==0) return 0;
  return f(x/2)+1;
}
int main() {
  long long x,y,a,b,da,db;
  cin>>x>>y;
  a=x,b=y;
  for(da=0;a;da++) a/=2;
  for(db=0;b;db++) b/=2;
  cout<<(da==db ? "TAK\n" : "NIE\n");
  cout<<(f(x)==f(y) ? "TAK\n" : "NIE\n");
}
