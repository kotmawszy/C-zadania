#include <bits/stdc++.h>
using namespace std;

int main() {
    string a;
    cin>>a;

    string b = a;
    reverse(a.begin(),a.end()); //odwrócenie stringa

    a+=b;
    int x = atoi(a.c_str()); //zamiana stringa na inta

    while(x>1) { //rozkład na czynniki pierwsze
        for(int i=2;i<=x;i++) {
            if(x%i==0) {
                cout<<i<<" ";
                x/=i;
                break;
            }
        }
    }
}
