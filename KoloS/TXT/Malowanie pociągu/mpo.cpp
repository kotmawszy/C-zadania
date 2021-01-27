#include<bits/stdc++.h>
using namespace std;

int n;
int np[128];
int p[128];
int cnp,cp;
int c2np,c2p;
int inp=0,ip=0;
string s;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>s;
	for(int i=0;i<n;i++) {
		if(i%2) p[s[i]]++;
		else np[s[i]]++;
	}
	for(int i=0;i<128;i++) {
		if(p[i]>ip) {
			ip=p[i];
			cp=i;
		}
		if(np[i]>inp) {
			inp=np[i];
			cnp=i;
		}
	}
	inp=ip=0;
	for(int i=0;i<128;i++) {
		if(p[i]>ip && i!=cp) {
			ip=p[i];
			c2p=i;
		}
		if(np[i]>inp && i!=cnp) {
			inp=np[i];
			c2np=i;
		}
	}
	if(cnp!=cp) cout<<n-np[cnp]-p[cp];
	else cout<<min(n-np[c2np]-p[cp], n-np[cnp]-p[c2p]);
}
