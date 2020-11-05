#include <bits/stdc++.h>
using namespace std;

map<int,bool> m;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  
  int n,a;
  cin>>n;
  while(n--) {
    cin>>a;
    cout<<(m[a] ? "N\n" : "T\n");
    m[a]=1;
  }
}
