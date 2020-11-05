#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  int n,m,a,b;
  cin>>n>>m;
  vector<int> v[n+1];
  while(m--) {
    cin>>a>>b;
    v[a].push_back(b);
    v[b].push_back(a);
  }

  int idx=0, val=0;
  for(int i=1;i<=n;i++) {
    if(v[i].size()>val) {
      val = v[i].size();
      idx = i;
    }
  }
  cout<<idx<<"\n";
  sort(v[idx].begin(), v[idx].end());
  for(int i=0;i<v[idx].size();i++) cout<<v[idx][i]<<" ";
}
