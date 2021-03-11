#include <bits/stdc++.h>
using namespace std;

int n;
bitset<100003> tab;

void pemtlaDruga(int i, int j) {
  if(i*j>=100003) return;
  tab[i*j]=1;
  if((++j)*i<=n) pemtlaDruga(i,j+1);
}
void pemtlaPierfsza(int i) {
  if(i>=100003) return;
  if(tab[i]) {
    if(++i<=n) pemtlaPierfsza(i+1);
    return;
  }
  pemtlaDruga(i,2);
  if(++i<=n) pemtlaPierfsza(i+1);
}
void pemtlaTszecia(int i) {
  if(i>=100003) return;
  if(tab[i] || n%i) {
    if(++i<=n) pemtlaTszecia(i);
    return;
  }
  cout<<i<<" ";
  n/=i;
  i--;
  if(n==1) return;
  if(++i<=n) pemtlaTszecia(i);
}

int main() {
  cin>>n;
  pemtlaPierfsza(2);
  pemtlaTszecia(2);
}
