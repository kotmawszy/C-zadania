#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin>>n;
  int tab[n+1];
  for(int i=1;i<=n;i++) cin>>tab[i];

  for(int i=2;i<=n;i++) {
    int j=i-1;
    int k=tab[i];
    while(j>0 && tab[j]>k) {
      tab[j+1]=tab[j];
      j--;
    }
    tab[j+1]=k;
  }

  for(int i=1;i<=n;i++) cout<<tab[i]<<" ";
}
