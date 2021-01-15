#include <bits/stdc++.h>
using namespace std;

long long INF = numeric_limits<long long>::max();
int n,m;
vector<pair<int,int> >* g;
int a,b,c;
long long* d;
priority_queue<pair<int,int> > q;
long long maxx=-1;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>m;

  g = new vector<pair<int,int> >[2*(n+1)];
  d = new long long[2*(n+1)];

  for(int i=1;i<=m;i++) {
    cin>>a>>b>>c;
    if(c%2) {
      g[2*a].push_back(make_pair(2*b+1,c));
      g[2*a+1].push_back(make_pair(2*b,c));
      if(a!=b) {
        g[2*b].push_back(make_pair(2*a+1,c));
        g[2*b+1].push_back(make_pair(2*a,c));
      }
    } else {
      g[2*a].push_back(make_pair(2*b,c));
      g[2*a+1].push_back(make_pair(2*b+1,c));
      if(a!=b) {
        g[2*b].push_back(make_pair(2*a,c));
        g[2*b+1].push_back(make_pair(2*a+1,c));
      }
    }
  }

  for(int i=1;i<=2*n+1;i++) d[i] = INF;

  q.push(make_pair(0,2));
  d[2]=0;
  while(!q.empty()) {
    pair<int,int> t = q.top();
    q.pop();
    int v = t.second;
    for(pair<int,int> i : g[v]) {
      int w = i.first;
      if(d[v]+i.second < d[w]) {
        d[w] = d[v]+i.second;
        q.push(make_pair(-d[w],w));
      }
    }
  }

  for(int i=1;i<=n;i++) {
    if(d[2*i]==INF || d[2*i+1]==INF) continue;
    maxx = max(maxx, d[2*i]+d[2*i+1]);
  }
  if(maxx == -1) {
    cout<<"BRAK\n";
    return 0;
  }
  for(int i=1;i<=n;i++) {
    if(d[2*i]+d[2*i+1]==maxx) {
      cout<<i<<" ";
    }
  }
  cout<<"\n"<<maxx<<"\n";
}
