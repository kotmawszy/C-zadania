#include <bits/stdc++.h>
using namespace std;

bool cmp(const string& a, const string& b) {
  int c = a.size()-b.size();
  if(c==0) return a<b;
  return c<0;
}

int main() {
  int n;
  cin>>n;
  string a[n];
  for(int i=0;i<n;i++) cin>>a[i];
  sort(a,a+n,cmp);
  for(int i=0;i<n;i++) cout<<a[i]<<"\n";
}
