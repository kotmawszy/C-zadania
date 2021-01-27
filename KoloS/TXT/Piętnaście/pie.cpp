#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie();
    int n,x;
    string s;
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>s;
        x=0;
        for(int j=0;j<s.size();j++) {
            x+=(s[j]-48);
            x%=3;
        }
        cout<<((s[s.size()-1]=='0' || s[s.size()-1]=='5')&&(x==0) ? "TAK\n" : "NIE\n");
    }
}
