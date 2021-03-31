#include <bits/stdc++.h>
using namespace std;

int z;
long long n;

bool f() {
  int k=0;
  long long i=cbrt(n);
  long long j=0;
  do {
    k++;
    long long r = i*i*i-j*j*j;
    if(r==n) return 1;
    if(r>n) j++;
    else i++;
  } while(k<(n<=1e11 ? 1e6 : 1e8));
  return 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

  cin>>z;
  while(z--) {
    cin>>n;
    cout<<(f() ? "TAK\n" : "NIE\n");
  }
}
