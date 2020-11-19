#include <bits/stdc++.h>
using namespace std;

int n;
int tab[1000003];
int p[1000003];
int q[1000003];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>n;
  for(int i=1;i<=n;i++) {
    cin>>tab[i];
    p[i]=max(p[i-1],tab[i]);
  }
  for(int i=n;i>=1;i--) q[i]=max(q[i+1],tab[i]);

  for(int i=1;i<=n;i++) cout<<p[i]<<" "<<q[i]<<"\n";
}
