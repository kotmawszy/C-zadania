#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin>>n;
  while(n--) {
      int c=0;
      long long x;
      cin>>x;
      for(long long i=1;i<=x;i*=2) {
          c++;
      }
      cout<<c<<"\n";
  }
}
