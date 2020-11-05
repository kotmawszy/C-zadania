#include <bits/stdc++.h>
using namespace std;

int n,q;
int d[2'100'000];
int lazy[2'100'000];
int lv=1;

void init() {
  while(lv < n) {
    lv*=2;
  }
}

void push(int v) {
  if(!lazy[v]) return;

  d[v]=lazy[v];
  if(v<2*lv)
    lazy[2*v]=lazy[2*v+1]=lazy[v];
  lazy[v]=0;
}

void sett(int a, int b, int x, int v=1, int p=0, int q=lv-1) {
  push(v);
  if(q<a || p>b) return;
  if(p>=a && q<=b) {
    lazy[v]=x;
    push(v);
    return;
  }
  sett(a,b,x,2*v,p,(p+q)/2);
  sett(a,b,x,2*v+1,(p+q)/2+1,q);
  d[v]=max(d[2*v],d[2*v+1]);
}

int query(int a, int b, int v=1, int p=0, int q=lv-1) {
  push(v);
  if(q<a || p>b) return 0;
  if(p>=a && q<=b) {
    return d[v];
  }
  return max(query(a,b,2*v,p,(p+q)/2), query(a,b,2*v+1,(p+q)/2+1,q));
}

int main() {
  cin>>n>>q;
  int a,b;
  init();
  while(q--) {
    cin>>a>>b;
    int p = b;
    int q = a+b-1;
    int x = query(p,q);
    sett(p,q,x+1);
  }
  cout<<d[1];
}
