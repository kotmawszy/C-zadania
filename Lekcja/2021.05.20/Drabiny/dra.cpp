#include <bits/stdc++.h>
using namespace std;

int n,m;
int tab[1000007];
long long s;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>m;
  for(int i=0;i<n;i++) cin>>tab[i];
  sort(tab,tab+n);

  for(int i=0;i<n;i++) {
    int* x = upper_bound(tab,tab+n,m-tab[i]);
    int y = tab+n-x;
    if(y>0) s+=y;
  }
  for(int i=0;i<n;i++) if(tab[i]*2>m) s--;
  cout<<s/2<<"\n";
}
