#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,q;
  cin>>q;
  while(q--) {
      cin>>n;
      int tab[n];
      for(int j=0;j<n;j++) cin>>tab[j];
      for(int j=1;j<n;j+=2) cout<<tab[j]<<" ";
      for(int j=0;j<n;j+=2) cout<<tab[j]<<" ";
      cout<<"\n";
  }
}
