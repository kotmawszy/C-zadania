#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin>>s;
    int c=0;
    for(char i : s) {
      c+=i-'0';
      c%=3;
    }
    if(s[0]=='x') cout<<3-c;
    else cout<<(3-c)%3;
}
