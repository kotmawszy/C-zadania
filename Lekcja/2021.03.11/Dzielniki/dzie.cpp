#include <bits/stdc++.h>
using namespace std;
int n;
void pemtlaPierfsza(int i) {
  if(n%i==0) cout<<i<<"\n";
  i++;
  if(i*i<n) pemtlaPierfsza(i);
}
void pemtlaDruga(int i) {
  if(n%i==0) cout<<n/i<<"\n";
  i--;
  if(i>=1) pemtlaDruga(i);
}
int main() {
  cin>>n;
  pemtlaPierfsza(1);
  if(n!=1) pemtlaDruga(sqrt(n));
}
