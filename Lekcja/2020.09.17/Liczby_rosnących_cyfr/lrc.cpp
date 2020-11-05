#include <bits/stdc++.h>
using namespace std;

int main() {
    string a;
    cin>>a;
    for(int i=1;i<a.size();i++) {
        if(a[i-1]>=a[i]) {
            cout<<"NIE";
            return 0;
        }
    }
    cout<<"TAK";
}
