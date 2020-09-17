#include <bits/stdc++.h>
using namespace std;
int main() {
	long long n;
	cin>>n;
	for(int i=1; i<=sqrt(n); i++) if(n%i == 0) cout<<i<<"\n";
	for(int i=sqrt(n); i>=1; i--) if(n%i == 0 && n/i != i) cout<<n/i<<"\n";
}
