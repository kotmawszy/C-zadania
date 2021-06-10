#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin>>n;
  int tab[n];
  for(int i=0;i<n;i++) cin>>tab[i];

  sort(tab,tab+n);

  if(n-4<0) cout<<"0\n";
  else cout<<(long long)tab[n-4]*tab[n-4]<<"\n";
}
