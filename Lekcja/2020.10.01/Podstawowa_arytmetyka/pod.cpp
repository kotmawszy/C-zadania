#include <bits/stdc++.h>
using namespace std;
int main() {
    long long a,b,s;
    for(;;) {
        cin>>a>>b;
        if(!a && !b) return 0;
        bool x = s = 0;
        while(a||b) {
            s += x = (a%10+b%10+x)/10;
            a/=10, b/=10;
        }
        cout<<s<<"\n";
    }
}
