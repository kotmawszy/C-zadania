#include <bits/stdc++.h>
using namespace std;

string a,b;
int c,d;

int main() {
  cin>>a>>b;
  while(a.size()<b.size()) a="0"+a;
  for(int i=0;i<b.size();i++) d+=b[i]-'0';
  int i=0;
  for(;i<a.size() && a[i]==b[i];i++) c+=b[i]-'0';
  c+=b[i++]-'1'+9*(b.size()-i);
  cout<<max(c,d);
}
