#include <bits/stdc++.h>
using namespace std;

long long n;
stack<char> s;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n;
  while(n) {
    s.push(2*(n%5)+48);
    n/=5;
  }
  while(!s.empty()) {
    cout<<s.top();
    s.pop();
  }
}
