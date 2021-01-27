#include <bits/stdc++.h>
using namespace std;

int pfx[1007][1007];
int a;
int n,m;

int main() {
  cin>>n>>m;

  for(int i=1;i<=n;i++) {
    for(int j=1;j<=m;j++) {
      cin>>a;
      pfx[i][j]=max(pfx[i-1][j],pfx[i][j-1])+a;
    }
  }
  cout<<pfx[n][m]<<"\n";

  int p=n,q=m;
  stack<pair<int,int> > s;
  while(p!=1 || q!=1) {
    s.push({p,q});
    if(pfx[p-1][q]>pfx[p][q-1]) p--;
    else q--;
  }
  for(s.push({1,1});!s.empty();s.pop())
    cout<<s.top().first<<" "<<s.top().second<<"\n";
}
