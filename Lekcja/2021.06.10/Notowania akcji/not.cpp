#include <bits/stdc++.h>
using namespace std;

int ans[500003];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin>>n;
  int tab[n];
  for(int i=0;i<n;i++) cin>>tab[i];

  int p=0;
  int q=0;
  while(p<n) {
    while(q+1<n && tab[q+1]>tab[q]) q++;
    for(int i=1,j=q-p;j>0;i++,j--) ans[i]+=j;
    p=++q;
  }
  ans[0]=n;

  int x;
  cin>>q;
  while(q--) {
    cin>>x;
    cout<<ans[x-1]<<"\n";
  }
}
