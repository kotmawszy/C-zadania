#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    long long n;
    cin>>n;
    while(n>1) {
        if(n%2) {
          cout<<"NIE";
          return 0;
        }
        n/=2;
    }
    cout<<"TAK";
}
