#include <bits/stdc++.h>
using namespace std;
int main() {
    long long a,b;
    cin>>a>>b;
    if(b<=(a+1)/2) cout<<2*b-1;
    else cout<<(b-(a+1)/2)*2;
}
