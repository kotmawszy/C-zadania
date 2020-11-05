#include <bits/stdc++.h>
using namespace std;

int main() {
    double n,m;
    cin>>n>>m;
    cout<<setprecision(100)<<ceil(n+n/(m-1))-1;
}
