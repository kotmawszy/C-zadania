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

  for(int j=0;j<n-1;j++) {
    for(int i=0;i<n-1-j;i++) {
      if(tab[i]>=tab[i+1]) {
        int r=tab[i];
        tab[i]=tab[i+1];
        tab[i+1]=r;
      }
    }
  }

  for(int i=0;i<n;i++) {
    cout<<tab[i]<<" ";
  }
}
