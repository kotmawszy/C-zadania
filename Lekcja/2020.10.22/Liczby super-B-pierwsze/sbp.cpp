#include <bits/stdc++.h>
using namespace std;

bool prime(int n) {
  if(n<=1) return 0;
  if(n<=3) return 1;
  for(int i=2;i*i<=n;i++) {
    if(n%i==0) return 0;
  }
  return 1;
}

bool f(int n) {
  if(!prime(n)) return 0;

  int x = n;
  int s = 0;
  while(x) {
    s+=x%10;
    x/=10;
  }
  if(!prime(s)) return 0;

  s = 0;
  while(n) {
    s+=n%2;
    n/=2;
  }
  return prime(s);
}

int main() {
  int a,b,s=0;
  cin>>a>>b;
  for(int i=a;i<=b;i++) {
    if(f(i)) s++;
  }
  cout<<s;
}
