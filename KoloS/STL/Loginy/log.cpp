#include <bits/stdc++.h>
using namespace std;

map<string,int> m;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  string a;
  cin>>n;
  while(n--) {
    cin>>a;
    if(m[a]==0) cout<<"OK\n";
    else cout<<a<<m[a]<<"\n";
    m[a]++;
  }
}
