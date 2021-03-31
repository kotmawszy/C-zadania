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

  for(int i=1;i<=n;i++) {
    int mn=i;
    for(int j=i+1;j<=n;j++)
        if(tab[j]<tab[mn])
            mn=j;
    swap(tab[mn],tab[i]);
  }

  for(int i=1;i<=n;i++) cout<<tab[i]<<" ";
}
