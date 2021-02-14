#include <bits/stdc++.h>
using namespace std;

int n,h,q;

struct Point {
  int x,y;
};
struct Platform {
  Point p;
  int l;
  Platform() {
    cin>>p.x>>p.y>>l;
  }
};
bool overlap(const Platform& a, const Platform& b) {
  if(a.p.x+a.l<=b.p.x || a.p.x>=b.p.x+b.l) return 0;
  if(a.p.y>b.p.y+h || a.p.y<b.p.y-h) return 0;
  return 1;
}

Platform* r;

int* p;
int* s;
int a,b;

int Find(int v) {
  if(p[v] != v) p[v]=Find(p[v]);
  return p[v];
}
void Union(int a, int b) {
  a = Find(a);
  b = Find(b);
  if(a==b) return;
  if(s[a]<s[b]) swap(a,b);
  p[a]=b;
  s[b]+=s[a];
}

int main() {
  cin>>n>>q>>h;
  r = new Platform[n];
  s = new int[n];
  p = new int[n];
  for(int i=0;i<n;i++) s[i]=1, p[i]=i;
  for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++) {
      if(overlap(r[i],r[j])) Union(i,j);
    }
  }
  while(q--) {
    cin>>a>>b;
    cout<<(Find(a-1)==Find(b-1) ? "YES\n" : "NO\n");
  }
}
