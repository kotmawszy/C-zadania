#include <bits/stdc++.h>
using namespace std;

int n,a,s,x=1;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>n;
  for(int i=0;i<n;i++) {
    cin>>a;
    if(a==x) x++;
    else s++;
  }
  cout<<s;
}
