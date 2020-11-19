#include <bits/stdc++.h>
using namespace std;

int n,k,a,b,c,m;
int tab[1000007];
int pfx[1000007];
vector<int> ans;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>n;
  for(int i=1;i<=n;i++) {
    cin>>tab[i];
    pfx[i]=tab[i]+pfx[i-1];
  }
  cin>>k;
  for(int i=1;i<=k;i++) {
    cin>>a>>b;
    c = pfx[b]-pfx[a-1];
    if(m==c) {
      ans.push_back(i);
    } else if(m<c) {
      m = c;
      ans.clear();
      ans.push_back(i);
    }
  }
  for(int v : ans) cout<<v<<" ";
}
