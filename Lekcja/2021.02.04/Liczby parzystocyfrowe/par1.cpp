#include <bits/stdc++.h>
using namespace std;

long long n;
string a;
int p=10;
int q=5;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>a;
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
    cout<<s.top()*2;
    s.pop();
  }
}
