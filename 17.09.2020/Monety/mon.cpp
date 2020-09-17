#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	int n,a,ilosc1=0,ilosc0=0;
	cin>>n;
	for(int i;i<n;i++){
		cin>>a;
		if(a==1){
			ilosc1++;
		}
		else{
			ilosc0++;
		}
	}
	if(ilosc1>ilosc0){
		cout<<ilosc0;
	}
	else{
		cout<<ilosc1;
	}
}
