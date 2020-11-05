#include <bits/stdc++.h>
using namespace std;

long long col(long long x) {
  int i;
  for(i=1;x!=1;i++) {
    if(x%2) x=x*3+1;
    else x=x/2;
  }
  return i;
}

int main() {
  long long a,b,m=0;
  cin>>a>>b;
  for(int i=a;i<=b;i++) {
    m = max(m, col(i));
  }
  cout<<m;
}
