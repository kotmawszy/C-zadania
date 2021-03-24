#include <bits/stdc++.h>
using namespace std;

int h,n,a;
bool m[1100000];

int suma(int v, int hh) {
  if(m[v]==0) return 0;
  if(hh==h) return 1;
  return suma(2*v,hh+1)+suma(2*v+1,hh+1)+1;
}

int main() {
  cin>>h>>n;
  for(int i=0;i<n;i++) {
    cin>>a;
    m[a]=1;
  }

  cout<<suma(1,1);
}
