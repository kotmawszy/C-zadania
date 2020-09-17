#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    n++;
    while(true) {
        if((n%5+n%7)%3==0) {
            cout<<n;
            return 0;
        }
        n++;
    }
}
