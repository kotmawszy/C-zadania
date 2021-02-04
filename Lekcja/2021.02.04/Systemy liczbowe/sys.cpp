#include <bits/stdc++.h>
using namespace std;

long long n;
string a;
int p;
int q;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>a>>p>>q;
  long long base=1;
  long long x=0;
  for(int i=0;i<a.size();i++) {
    x+=(a[a.size()-i-1]-'0')*base;
    base*=p;
  }

  stack<int> s;
  while(x) {
    s.push(x%q);
    x/=q;
  }
  while(!s.empty()) {
    cout<<s.top();
    s.pop();
  }
}
