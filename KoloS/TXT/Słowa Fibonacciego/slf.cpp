#include <bits/stdc++.h>
using namespace std;
vector<string> v;
int f(string x) {
    if(x.size()==0) return 0;
    if(x.size()==1) return 1;
    if(x.size()==2) {
        if(x[0]==x[1]) return 0;
        return 3;
    }
    char a,b;
    for(int i=0;i<v.size();i++) {
        if(v[i].size()==x.size()) {
            a=x[0];
            b=x[1];
            if(a==b) return 0;
            for(int j=0;j<v[i].size();j++) {
                if(v[i][j]=='a' && x[j]!=a) return 0;
                if(v[i][j]=='b' && x[j]!=b) return 0;
            }
            return i;
        }
    }
    return 0;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    char a,b;
    v.push_back("");
    v.push_back("b");
    v.push_back("a");
    for(int i=3;i<32;i++) {
        v.push_back(v[i-1]+v[i-2]);
    }
    int n,y;
    cin>>n;
    string x;
    while(n>0) {
        n--;
        cin>>x;
        y=f(x);
        if(y==0) cout<<"NIE\n";
        else cout<<y<<"\n";
    }
}
