#include <bits/stdc++.h>
using namespace std;
int main() {
    int X,Y,x,y;
    cin>>X>>Y>>x>>y;
    for(int i=1;i<=Y;i++) {
        for(int j=1;j<=X;j++) {
            cout<<(i==y && j==x ? "*" : ".");
        }
        cout<<"\n";
    }
}
