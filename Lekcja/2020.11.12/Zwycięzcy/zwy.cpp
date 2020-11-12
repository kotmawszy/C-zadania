#include <bits/stdc++.h>
using namespace std;

vector<char> v;

int main() {
  int n,a,m=0;
  cin>>n;

  for(int i=0;i<n;i++) {
    cin>>a;
    if(a>m) {
      v.clear();
      m = a;
      v.push_back('A'+i);
    } else if(a==m) v.push_back('A'+i);
  }
  for(int i=0;i<v.size();i++) cout<<v[i];
}
