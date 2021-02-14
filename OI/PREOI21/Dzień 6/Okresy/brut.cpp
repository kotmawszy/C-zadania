#include <bits/stdc++.h>
using namespace std;

int f(string s) {
  int n = s.size();
  int p[n+1];
  p[1]=0;
  for(int i=2;i<=n;i++) {
    int t = p[i-1];
    while(t>0 && s[t]!=s[i-1]) t=p[t];
    if(s[t]==s[i-1]) p[i]=t+1;
    else p[i]=0;
  }
  int i=0;
  for(int t=p[n];t;i++) {
    t=p[t];
  }
  return i;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  string s="";
  int a;
  char b;
  cin>>n;
  while(n--) {
    cin>>a>>b;
    if(a==1) s = s+b;
    else s = b+s;
    cout<<f(s)+1<<"\n";
  }
}
