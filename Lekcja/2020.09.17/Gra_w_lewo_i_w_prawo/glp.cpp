#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,a,b;
    cin>>n>>a>>b;
    cout<<(a<b xor a%2 == b%2)+1;
}
