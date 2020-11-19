#include <bits/stdc++.h>
using namespace std;
long long n,a,u;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  for(int i=0;i<n;i++) {
    cin>>a;
    if(a<0) u++;
  }
  cout<<u*(n-1);
}
