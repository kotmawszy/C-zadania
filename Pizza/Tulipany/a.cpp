#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n,q,a,b;
  cin>>n>>q;
  string s;
  cin>>s;
  int pref[n];
  pref[0]=0;
  for(int i=1;i<n;i++) pref[i]=pref[i-1]+(s[i-1]==s[i]);

  while(q--) {
    cin>>a>>b;
    cout<<pref[b-1]-pref[a-1]<<"\n";
  }
}
