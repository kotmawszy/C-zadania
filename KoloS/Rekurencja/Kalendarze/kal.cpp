#include <bits/stdc++.h>
using namespace std;

int n,m,q,c,d;
int* a;
int* b;
char g;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m;
    a = new int[n+1];
    a[0]=0;
    for(int i=1;i<=n;i++) {
      cin>>a[i];
      a[i]+=a[i-1];
    }
    b = new int[m+1];
    b[0]=0;
    for(int i=1;i<=m;i++) {
      cin>>b[i];
      b[i]+=b[i-1];
    }

    cin>>q;

    while(q--) {
      cin>>c>>d>>g;
      if(g=='A') {
        int e = a[d-1]+c;
        int f = lower_bound(b,b+m+1,e)-b;
        cout<<e-b[f-1]<<" "<<f<<"\n";
      } else {
        int e = b[d-1]+c;
        int f = lower_bound(a,a+n+1,e)-a;
        cout<<e-a[f-1]<<" "<<f<<"\n";
      }
    }
}
