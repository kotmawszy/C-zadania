#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	long long n;
	cin>>n;
	for(int i = 1; i <= sqrt(n); i++){
		if(n % i == 0){
			cout<<i<<endl;			
		}		
	}
	for(int i=sqrt(n); i>=1; i--){
		if(n % i == 0 and n/i != i){
			cout<<n/i<<endl;
		}
	}
}
 
