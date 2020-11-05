#include <bits/stdc++.h>
using namespace std;

stack<int> s;
queue<int> q;
int n,a;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n;

  for(int i=0;i<n;i++) {
    cin>>a;
    s.push(a);
    q.push(a);
  }

  while(!s.empty()) {
    cout<<s.top()<<" ";
    s.pop();
  }
  cout<<"\n";
  while(!q.empty()) {
    cout<<q.front()<<" ";
    q.pop();
  }
}
