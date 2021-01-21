#include <bits/stdc++.h>
using namespace std;

int n;
int a[1000001],b[1000001],c[1000001];
int d,s;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>n;
  for(int i=1;i<=n;i++) cin>>a[i];
  for(int i=1;i<=n;i++) {
    cin>>d;
    b[d]=i;
  }
  for(int i=1;i<=n;i++) c[i]=b[a[i]];

  for(int i=n;i>1;i--) if(c[i]>c[i-1]) s++;
  if(c[1]!=1) s++;
  cout<<s;
}
