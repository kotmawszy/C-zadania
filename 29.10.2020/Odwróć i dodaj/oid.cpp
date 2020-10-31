#include <bits/stdc++.h>
using namespace std;

long long odw(long long x) {
  long long y=0;
  while(x) {
    y*=10;
    y+=x%10;
    x/=10;
  }
  return y;
}

bool czyPalindrom(long long x) {
  return x==odw(x);
}

int main() {
  int n;
  cin>>n;
  while(n--) {
    long long a,i;
    cin>>a;
    for(i=0;!czyPalindrom(a);i++) {
      a+=odw(a);
    }
    cout<<i<<" "<<a<<"\n";
  }
}
