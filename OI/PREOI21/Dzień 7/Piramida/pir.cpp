#include <bits/stdc++.h>
using namespace std;

int n;
int* arr;
int* l;
int* r;
int mx = 0;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n;
  arr= new int[n+1];
  r = new int[n+1];
  l = new int[n+1];
  for(int i=1;i<=n;i++) cin>>arr[i];

  l[1]=1;
  for(int i=2;i<=n;i++) l[i]=min(l[i-1]+1,arr[i]);
  r[n]=1;
  for(int i=n-1;i>=1;i--) r[i]=min(r[i+1]+1,arr[i]);

  for(int i=1;i<=n;i++) mx=max(mx, min(l[i],r[i]) );
  cout<<mx;
}
