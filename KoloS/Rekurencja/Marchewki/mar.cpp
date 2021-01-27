#include <bits/stdc++.h>
using namespace std;

long long f(int r) {
  long long s=0;
  for(int p=0,q=r; p<=r; p++) {
    while(p*p + q*q > r*r) q--;
    s += q;
  }
  return 4*s+1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n;
    cin>>n;
    int p = 0, q = 2000000;
    while(p<q) {
      int r = (p+q)/2;
      long long s = f(r);
      if(s<n) p=r+1;
      else q=r;
    }
    cout<<p;
}
