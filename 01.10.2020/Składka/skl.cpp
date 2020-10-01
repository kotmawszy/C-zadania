#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,k;
    long long a,s;
    cin>>n;
    while(n--) {
      s=0;
      cin>>k;
      while(k--) {
        cin>>a;
        s+=a;
        s%=1000;
      }
      cout<<s<<"\n";
    }
}
