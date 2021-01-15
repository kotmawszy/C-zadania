#include<bits/stdc++.h>
using namespace std;

long long P = 127;
long long MOD = 2147483647;

long long* powers;

int n;
string t;
long long* hp;
long long* hq;

long long modulo(long long x) {
  return (x&MOD) + (x>>31);
}

long long subHP(int a, int b) {
	if(a == 0) return hp[b+1];
	return modulo(hp[b+1] + MOD - modulo(hp[a]*powers[b-a+1]));
}
long long subHQ(int a, int b) {
	if(b == n-1) return hq[a];
	return modulo(hq[a] + MOD - modulo(hq[b+1]*powers[b-a+1]));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>t;

	powers = new long long [n+5];
	powers[0] = 1;
	for(int i=1;i<n+5;i++) powers[i] = modulo(powers[i-1]*P);

	hp = new long long[n+1];
	hp[0] = 0;
	for(int i=0;i<n;i++) hp[i+1] = modulo(hp[i] * P + t[i]);
	hq = new long long[n+1];
	hq[n] = 0;
	for(int i=n-1;i>=0;i--) hq[i] = modulo(hq[i+1] * P + t[i]);

	for(int i=0;i<n;i++) {
		int p=0,q=i,s=0;
		if(t[0] == t[i]) {
			while(q>p+1) {
				s=(p+q)/2;
				if(subHP(0,s) == subHQ(i-s,i)) {
					p=s;
				} else {
					q=s-1;
				}
			}
			if(subHP(0,q) == subHQ(i-q,i)) cout<<q+1<<" ";
			else if(subHP(0,p) == subHQ(i-p,i)) cout<<p+1<<" ";
			else cout<<"0 ";
		} else cout<<"0 ";
	}
}
