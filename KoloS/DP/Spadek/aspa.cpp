#include <bits/stdc++.h>
using namespace std;

int n;
bitset<1500003> s;
int a;
int su;
int mv=numeric_limits<int>::max();

int main() {
  cin>>n;
  s[0]=1;
  for(int i=1;i<=n;i++) {
    cin>>a;
    su+=a;
    if(i==1) s[a]=1;
    else s|=s<<a;
  }

  for(int i=0;i<1500003;i++) {
    if(!s[i]) continue;
    int c = max(i,su-i);
    if(c<mv || c==mv && i<su-i) {
      mv = c;
    }
  }
  cout<<mv<<" "<<su-mv;
}
