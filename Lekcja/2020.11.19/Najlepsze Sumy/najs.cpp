#include <bits/stdc++.h>
using namespace std;

int tab[500003];
int n,a,c,m;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  do cin>>tab[n];
  while(tab[n++]);
  --n;
  for(int i=0;i<n;i++) {
    c+=tab[i];
    if(c<0) c=0;
    m=max(m,c);
  }
  cout<<m;
}
