#include <bits/stdc++.h>
using namespace std;

string s;
int n;
int c=1,p,mx;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>s;
  n = s.size();
  for(int i=0;i<n;i++) {
    if(i+1<n && s[i]==s[i+1]) c++;
    else {
      if(s[i]=='+') p+=c;
      else {
        p+=c/2;
        if(c%2) {
          mx=max(mx,p);
          p=c/2;
        }
      }
      c=1;
    }
  }
  p+=c/2;
  cout<<max(mx,p);
}
