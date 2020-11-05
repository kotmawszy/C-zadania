#include <bits/stdc++.h>
using namespace std;

bool prime(int x) {
    if(x<2) return 0;
    for(int i=2;i*i<=x;i++) if(!(x % i)) return 0;
    return 1;
}
int main() {
    int n,a;
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a;
        for(;;) {
            if(prime(a+1) && prime(a+3)){
                cout<<a+1<<" "<<a+3<<"\n";
                break;
            }
            a++;
        }
    }
}
