#include <bits/stdc++.h>
using namespace std;

int n,m,k;
bool tab[1000007];
int a;
int mn;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>m>>k;
  for(int i=0;i<m;i++) {
    cin>>a;
    tab[a]=1;
  }

  int s=0;
  mn=n;
  for(int i=1;i<=k;i++) s+=tab[i];
  for(int i=1;i+k-1<=n;i++) {
    mn=min(mn, s);
    s-=tab[i];
    s+=tab[i+k];
  }
  cout<<mn<<"\n";
}
