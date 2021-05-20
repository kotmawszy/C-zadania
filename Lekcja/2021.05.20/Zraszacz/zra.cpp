#include <bits/stdc++.h>
using namespace std;

int n,k;
int tab[1000007];
int a;
int m;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>k;
  for(int i=1;i<=n;i++) cin>>tab[i];
  sort(tab+1,tab+n+1);

  int p=1;
  int q=1;
  for(;p<=n;p++) {
    while(q<=n && tab[p]+k>=tab[q]) q++;
    m=max(m, q-p);
  }
  cout<<m<<"\n";
}
