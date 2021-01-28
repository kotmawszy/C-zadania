#include<bits/stdc++.h>
using namespace std;
void f(int a,int b, int c,int d, int n) {
	if(n==0) cout<<a<<"/"<<b<<" ";
	else {
		f(a,b,a+c,b+d,n-1);
		f(a+c,b+d,c,d,n-1);
	}
}
int main() {
	int n;
	cin>>n;
	f(0,1,1,0,n);
	cout<<"1/0";
}
