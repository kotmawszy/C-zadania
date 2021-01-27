#include <bits/stdc++.h>
using namespace std;

string mult(string x) {
	bool z=0,p=0,d=0;
	for(int i=x.size()-1;i>=0;i--) {
		int y=x[i]-'0';
		y*=2;
		z=0;
		if(y>9) {
			if(i==0) d=1;
			else z=1;
			y-=10;
		}
		x[i]=y+'0'+p;
		p=z;
	}
	if(d) return '1'+x;
	return x;
}
bool sub(string a,string b) {
	for(int i=0;i<a.size();i++) if(a[i]!=b[i]) return 0;
	return 1;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin>>s;
	string x="1";
	for(int i=0;i<105;i++) {
		if(x.size()>2*s.size() && sub(s,x)) {cout<<i;return 0;}
		x=mult(x);
	}
}
