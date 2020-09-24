#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    if(n>=40) {
        cout<<0;
        return 0;
    }
    long long s=1;
    for(int i=2;i<=n;i++) {
        s*=i;
        s%=1000000000;
    }
    cout<<s;
}
