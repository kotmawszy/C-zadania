#include <bits/stdc++.h>
using namespace std;

string s;
bool w[127];
int n[127];
int mv;
char mi;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>s;
    for(char i : s) mv=max(mv,++n[i]);
    for(char i : s) if(n[i]==mv) mi=max(mi,i);
    for(char i : s) if(i!=mi) w[i]=1;
    for(char i='a';i<='z';i++) if(w[i]) cout<<i;
}
