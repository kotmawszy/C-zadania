#include <bits/stdc++.h>
using namespace std;

//long long arr[33][33];

long long k;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>k;
  if(k==0) {
    cout<<"1\n#\n";
    return 0;
  }
  if(k<=50) {
    int n = 2*k-1;
    cout<<n<<"\n";
    for(int i=1;i<=n;i++) {
      for(int j=1;j<=n;j++) {
        if(i==1 || i==n) cout<<".";
        else cout<<(j%2 ? "." : "#");
      }
      cout<<"\n";
    }
  }
}
