#include <bits/stdc++.h>
using namespace std;

int n;
vector<int>* g;
int a,b;
int* p;
int* w;
long long s;

int Find(int v) {
  if(p[v] != v) p[v]=Find(p[v]);
  return p[v];
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n;
  g = new vector<int>[n+1];
  p = new int[n+1];
  w = new int[n+1];
  for(int i=1;i<n;i++) {
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  for(int i=0;i<=n;i++) p[i]=i, w[i]=1;

  for(int i=1;i<=n;i++) {
    for(int v : g[i]) {
      if(v<i && p[v]!=p[i]) {
        //union
        a = Find(v);
        b = Find(i);
        if(w[a]>w[b]) swap(a,b);
        p[a]=b;
        w[b]+=w[a];
      }
    }
    s+=w[Find(i)];
  }
  cout<<s;
}
