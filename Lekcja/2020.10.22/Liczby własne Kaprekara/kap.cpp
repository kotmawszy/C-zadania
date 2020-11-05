#include <bits/stdc++.h>
using namespace std;

long long f(long long x) {
    long long w=0;
    while(x>0) {
        w+=x%10;
        x/=10;
    }
    return w;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    long long a;
    cin>>n;
    while(n--) {
        cin>>a;

        long long b=a;
        int l=0;
        while(b) {
            l++;
            b/=10;
        }

        long long z=l*9;
        long long i=a-z;
        for(l=0;i<a;i++) {
            if(i+f(i)==a) {
                cout<<i<<" ";
                l=1;
            }
        }
        cout<<(l==0 ? "NIE" : "")<<"\n";
    }
}
