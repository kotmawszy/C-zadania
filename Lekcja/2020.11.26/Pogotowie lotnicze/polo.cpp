#include <bits/stdc++.h>
using namespace std;

int n;
long long pref[1000001];
long long m = numeric_limits<long long>::max();
int p=-1;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>n;
  for(int i=1;i<n;i++) {
    cin>>pref[i];
    pref[i]+=pref[i-1];
  }
  for(int i=1;i<=n;i++) {
    long long x = pref[n-1]-pref[i-1];
    if(pref[i-1] > x) x = pref[i-1];

    if(x<m) {
      m=x;
      p=i;
    }
  }
  cout<<p;
}
