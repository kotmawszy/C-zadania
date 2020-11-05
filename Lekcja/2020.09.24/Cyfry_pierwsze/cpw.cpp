#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  string s;
  cin>>n;
  while(n--) {
      cin>>s;
      int x=0;
      for(int i=0;i<s.size();i++) {
          if(s[i] == '2' || s[i] == '3' || s[i] == '5' || s[i] == '7') x++;
      }
      cout<<x<<"\n";
  }
}
