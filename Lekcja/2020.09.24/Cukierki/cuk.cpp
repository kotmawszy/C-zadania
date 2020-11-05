#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,a,p=1,v=0;
  cin>>n;
  for(int i=1;i<=n;i++) {
      cin>>a;
      if(a%2==0 && a>v) {
          v=a;
          p=i;
      }
  }
  cout<<p;
}
