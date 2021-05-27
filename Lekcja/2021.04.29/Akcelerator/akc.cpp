#include <bits/stdc++.h>
using namespace std;

int n,m;
int* tab;
int a;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n;
  tab = new int[n];
  for(int i=0;i<n;i++) cin>>tab[i];

  cin>>m;
  while(m--) {
    cin>>a;
    cout<<(upper_bound(tab,tab+n,a)-lower_bound(tab,tab+n,a))<<"\n";
  }
}
