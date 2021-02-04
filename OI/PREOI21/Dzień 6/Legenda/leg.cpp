#include <bits/stdc++.h>
using namespace std;

long long INF = numeric_limits<long long>::max();

int T;
int n;
int c[200005],l[200005],r[200005];
long long d[200005];
vector<pair<int,int> > g[200005];
priority_queue<pair<long long,int> > q;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>T;
  while(T--) {
    cin>>n;
    for(int i=1;i<=n;i++) cin>>l[i];
    for(int i=1;i<=n;i++) cin>>r[i];
    for(int i=1;i<=n;i++) cin>>c[i];

    for(int i=1;i<=n;i++) {
      for(int j=l[i];j<=r[i];j++) {
        if(i+j>=1 && i+j<=n) g[i].push_back({i+j,c[i]});
        if(i-j>=1 && i-j<=n) g[i].push_back({i-j,c[i]});
      }
    }

    q = priority_queue<pair<long long,int> >();
    for(int i=1;i<=n;i++) d[i]=INF;
    q.push(make_pair(0,1));
    d[1]=0;
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
    for(int i=1;i<=n;i++) cout<<(d[i]==INF ? -1 : d[i])<<" ";
    cout<<"\n";

    for(int i=1;i<=n;i++) g[i].clear();
  }
}
