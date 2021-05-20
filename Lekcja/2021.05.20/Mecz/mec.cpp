#include <bits/stdc++.h>
using namespace std;

int n;
int d;
int tab[1000007];
int m,s;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>m>>s;
  d=m*60+s;
  cin>>n;
  for(int i=1;i<=n;i++) {
    cin>>m>>s;
    tab[i]=m*60+s;
  }
  sort(tab+1,tab+n+1);

  int p=1;
  int q=1;
  m=0;
  for(;p<=n;p++) {
    while(q<=n && tab[p]+d>tab[q]) q++;
    m=max(m, q-p);
  }
  cout<<m<<"\n";
}
