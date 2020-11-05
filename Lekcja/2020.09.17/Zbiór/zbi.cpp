#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    int a,b;
    while(n--) {
        cin>>a>>b;
        cout<<(b%a ? "NIE\n" : "TAK\n");
    }
}
