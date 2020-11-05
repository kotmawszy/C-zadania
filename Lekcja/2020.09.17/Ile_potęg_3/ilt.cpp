#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a,b;
    long long x = 1;
    int c=0;
    cin>>a>>b;
    while(x<=b) {
        if(x>=a) c++;
        x*=3;
    }
    cout<<c;
}
