#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, a, n0=0, n1=0;
	cin>>n;
	while(n--) {
		cin>>a;
		if(a == 1) n1++;
		else n0++;
	}
	cout<<(n1 > n0 ? n0 : n1);
}
