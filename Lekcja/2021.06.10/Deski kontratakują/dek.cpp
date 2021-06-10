#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin>>n;
  long long tab[n];
  for(int i=0;i<n;i++) cin>>tab[i];

  sort(tab,tab+n);

  long long ans=0;
  if(n>=1) ans=max(ans, tab[n-1]/4); // 4
  if(n>=2) {
    ans = max(ans, min(tab[n-1]/3,tab[n-2])); // 3 1
    ans = max(ans, tab[n-2]/2); // 2 2
  }
  if(n>=3) {
    ans = max(ans, min(tab[n-1]/2,tab[n-3])); // 2 1 1
  }
  if(n>=4) {
    ans = max(ans, tab[n-4]);
  }
  cout<<ans*ans<<"\n";

}
