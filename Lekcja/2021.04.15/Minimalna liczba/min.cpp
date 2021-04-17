#include <bits/stdc++.h>
using namespace std;

int n;
long long* a;
long long k;
long long s;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>k;
  a = new long long[n];
  for(int i=0;i<n;i++) cin>>a[i];
  sort(a,a+n);
  s=k;
  for(int i=0;i<n;i++) {
    if(a[i]==s) s+=k;
    else if(a[i]>s) {
      cout<<s<<"\n";
      return 0;
    }
  }
  cout<<s<<"\n";
}
