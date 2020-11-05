#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
  long long n,a;
  cin>>n;
  for(;n--;) {
  	cin>>a;
  	bool x=0;
  	while(a>0) {
  		if(a%16>9) {
		  cout<<"TAK\n";
		  x=1;
		  break;
		}
		a/=16;
	}
	if(x==0) cout<<"NIE\n";
  }
}
