#include <bits/stdc++.h>
using namespace std;
bool f(long long x) {
  if(!x) return 1;
  if(x%2) return 0;
  return f(x/10);
}
int main() {
  long long x;
  cin>>x;
  cout<<(f(x) ? "TAK" : "NIE")<<"\n";
  bool out=1;
  for(;x;x/=10) if(x%2) out=0;
  cout<<(out ? "TAK" : "NIE")<<"\n";
}
