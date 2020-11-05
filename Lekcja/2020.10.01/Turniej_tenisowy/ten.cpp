#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    long long n;
    cin>>n;
    int s=0;
    long long a = 1;
    long long b = 2;
    while(b<=n) {
      s++;
      long long c = a+b;
      a=b;
      b=c;
    }
    cout<<s;
}
