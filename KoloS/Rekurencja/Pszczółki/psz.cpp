#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    long long a=0,b=1,c,n;
    cin>>n;
    while(n--) {
      c=a+b;
      a=b;
      b=c;
    }
    cout<<a;
}
