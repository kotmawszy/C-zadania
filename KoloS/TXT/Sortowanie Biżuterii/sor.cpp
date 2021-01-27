#include <bits/stdc++.h>
using namespace std;

int n;
string* s;

bool cmp(const string& a, const string& b) {
  return (a.size()!=b.size() ? a.size()<b.size() : a<b);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n;
  s = new string[n];
  for(int i=0;i<n;i++) cin>>s[i];
  sort(s,s+n,cmp);
  for(int i=0;i<n;i++) cout<<s[i]<<"\n";
}
