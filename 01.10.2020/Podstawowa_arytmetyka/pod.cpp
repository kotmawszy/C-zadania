#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    long long a,b,s;
    for(;;) {
        s=0;
        cin>>a>>b;
        if(!a && !b) return 0;
        bool x = false;
        while(a||b) {
            s += x = (a%10+b%10+x)/10;
            a/=10, b/=10;
        }
        cout<<s<<"\n";
    }
}
