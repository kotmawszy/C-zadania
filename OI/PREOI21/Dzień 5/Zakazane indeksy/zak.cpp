#include <bits/stdc++.h>
using namespace std;

int n;
string s;
string c;
int* p;
int mx=0;

int kmp(string& x, int f) {
  p[1]=0;
  int sum=0;
  for(int i=2;i<=x.length();i++) {
    int t = p[i-1];
    while(t && x[t]!=x[i-1]) t=p[t];
    if(x[t]==x[i-1]) p[i]=t+1;
    else p[i]=0;
    if(p[i]==f && c[i-f-2]=='0') sum++;
  }
  return sum;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>s>>c;

  p = new int[2*(n+1)];

  for(int i=1;i<=n;i++) {
    for(int j=0;j<=n-i;j++) {
      string sb = s.substr(j,i);
      string kk = sb+"#"+s;

      int w = kmp(kk,i) * i;
      mx = max(mx,w);
    }
  }
  cout<<mx;
}
