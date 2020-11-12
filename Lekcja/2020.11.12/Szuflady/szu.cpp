#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n,s=0;
  cin>>n;
  int tab[n];
  for(int i=0;i<n;i++) cin>>tab[i];
  for(int i=n-2;i>=0;i--) {
    if(tab[i+1]-tab[i]<1) {
      tab[i]=tab[i+1]-1;
      if(tab[i]<1) {
        cout<<-1;
        return 0;
      }
      s++;
    }
  }
  cout<<s;
}
