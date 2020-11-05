#include <bits/stdc++.h>
using namespace std;

struct Node {
  long long a,r;
};

int n,q;
long long d[2'100'000];
Node lazy[2'100'000];
int lv=1;
pair<int,int> nadajniki[1'500'000];

void init() {
  while(lv < n) {
    lv*=2;
  }
}

void push(int v, int p, int q) {
  if(lazy[v].a==0 && lazy[v].r==0) return;

  long long first = lazy[v].a;
  long long last = lazy[v].a + lazy[v].r * (q-p);
  int no = (q-p+1);
  d[v] += (first+last)*no/2;
  if(v<2*lv) {
    lazy[2*v].a += lazy[v].a;
    lazy[2*v].r += lazy[v].r;
    lazy[2*v+1].a += lazy[v].a + lazy[v].r * (q-p+1)/2;
    lazy[2*v+1].r += lazy[v].r;
  }
  lazy[v].a = lazy[v].r = 0;
}

void add(int a, int b, long long a0, long long r, int v, int p, int q) {
  push(v,p,q);
  if(q<a || p>b) return;
  if(p>=a && q<=b) {
    lazy[v].a = a0;
    lazy[v].r = r;
    push(v,p,q);
    return;
  }
  add(a,b,a0,r,2*v,p,(p+q)/2);
  add(a,b,a0+r*(q-p+1)/2,r,2*v+1,(p+q)/2+1,q);
  d[v]=d[2*v]+d[2*v+1];
}

void add(int a, int b, long long a0, long long r) {
  if(a<1) {
    a0+=(1-a)*r;
    a=1;
  }
  if(b>n) b=n;
  add(a,b,a0-(a-1)*r,r,1,1,lv);
}

long long query(int a, int b, int v, int p, int q) {
  push(v,p,q);
  if(q<a || p>b) return 0;
  if(p>=a && q<=b) return d[v];
  return query(a,b,2*v,p,(p+q)/2) + query(a,b,2*v+1,(p+q)/2+1,q);
}
long long query(int a, int b) {
  if(a<1) a=1;
  if(b>n) b=n;
  return query(a,b,1,1,lv);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin>>n>>q;
  char a;
  long long b,c,e;
  init();
  while(q--) {
    cin>>a;
    if(a=='P') {
      cin>>b>>c>>e;
      long long l = ((c-1)/e+1);
      add(b,b+l-1,c,-e);
      add(b-l+1,b-1,c-(l-1)*e,e);
      nadajniki[b] = make_pair(c,e);
    } else if(a=='Z') {
      cin>>b>>c;
      cout<<query(b,c)/(c-b+1)<<"\n";
    } else if(a=='U') {
      cin>>b;
      c = nadajniki[b].first;
      e = nadajniki[b].second;
      long long l = ((c-1)/e+1);
      add(b,b+l-1,-c,e);
      add(b-l+1,b-1,(l-1)*e-c,-e);
      nadajniki[b] = make_pair(0,0);
    }
  }
}
