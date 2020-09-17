#include <bits/stdc++.h>
using namespace std;
int main() {
	long long n;
	cin>>n;
	for(int i=1; i*i<=n; i++) if(!n%i) cout<<i<<"\n";
	for(int i=sqrt(n); i>=1; i--) if(!n%i && n/i != i) cout<<n/i<<"\n";
}
