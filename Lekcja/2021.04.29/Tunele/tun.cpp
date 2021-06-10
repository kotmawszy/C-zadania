#include <bits/stdc++.h>
using namespace std;

int a,b;
int* t;
int s;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>a>>b;
	t = new int[a];

	for(int i=0;i<a;i++) {
		cin>>t[i];
		if(i>0 && t[i-1]<t[i]) t[i]=t[i-1];
	}
	reverse(t,t+a);
	for(int i=0;i<b;i++) {
		cin>>s;
		int x = upper_bound(t,t+a,s)-t;
		cout<<a-x<<" ";
	}
}
