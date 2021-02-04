#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;
int n;
int r,k,b,m;

long long pot(int a, int b) {
  if(b==0) return 1;
  if(b%2) return (pot(a,b-1)*a)%MOD;
  long long c = pot(a,b/2);
  return (c*c)%MOD;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n;
  while(n--) {
    cin>>r>>k>>b>>m;
    cout<<(pot(r,k)*pot(b,m))%MOD<<"\n";
  }
}
