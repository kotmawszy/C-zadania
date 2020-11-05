#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    int n,a=0,b=0,c;
    cin>>n;
    while(n--) {
        cin>>c;
        if(c) a++;
        else b++;
    }
    cout<<min(a,b);
}
