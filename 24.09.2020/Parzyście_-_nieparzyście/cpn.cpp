#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  bool a=0,b=0;
  cin>>s;
  for(int i=0;i<s.size();i++) {
      if(s[i]%2) a=1;
      else b=1;
  }
  cout<<(a&&b ? "TAK" : "NIE");
}
