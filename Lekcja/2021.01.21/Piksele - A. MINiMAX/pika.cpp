#include <bits/stdc++.h>
using namespace std;

int R = 200;
int C = 320;

int a;
int mn = numeric_limits<int>::max();
int mx = 0;

int main() {
  for(int i=1;i<=R;i++) {
    for(int j=1;j<=C;j++) {
      cin>>a;
      mn = min(mn, a);
      mx = max(mx, a);
    }
  }
  cout<<mx<<" "<<mn;
}
