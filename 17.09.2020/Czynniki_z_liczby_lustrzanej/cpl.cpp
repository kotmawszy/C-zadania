#include <bits/stdc++.h>
using namespace std;

int main() {
    string a;
    cin>>a;
    string b = a;
    reverse(a.begin(),a.end());
    a+=b;
    int x = atoi(a.c_str());
    while(x>1) {
        for(int i=2;i<=x;i++) {
            if(x%i==0) {
                cout<<i<<" ";
                x/=i;
                break;
            }
        }
    }
}
