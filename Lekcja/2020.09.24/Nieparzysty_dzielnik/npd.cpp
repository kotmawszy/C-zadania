#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    for(int i=2;i*i<=2*n;i++) {
        if(n%i!=0) continue;
        int x = n/i;
        if(x%2==1) {
            cout<<x;
            return 0;
        }
    }
    cout<<1;
}
