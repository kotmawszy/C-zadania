#include <bits/stdc++.h>
using namespace std;

int n;
int* p;
int* d;
int s;

int main() {
  ios_base::sync_with_stdio(0);

  cin>>n;
  if(n==1) {
    cout<<0;
    return 0;
  }

  p = new int[n+1];
  d = new int[n+1];
  for(int i=1;i<=n;i++) d[i]=0;
  p[1]=1;
  for(int i=2;i<=n;i++) cin>>p[i];

  for(int i=n;i>=2;i--) {
    if(d[i]==0) d[p[i]]++;
    else d[p[i]]+=d[i]-1;
  }
  for(int i=n;i>=1;i--) if(d[i]>0) s++;
  cout<<s;
}
