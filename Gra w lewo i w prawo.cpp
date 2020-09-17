#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,a,b;
    cin>>n>>a>>b;
    if(a<b) cout<<(a%2 == b%2 ? 1 : 2);
    else cout<<(a%2 == b%2 ? 2 : 1);
}
