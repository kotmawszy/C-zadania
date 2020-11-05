#include <iostream>
using namespace std;
int n = 300000;
int main() {
	cout<<n<<" "<<n+1<<"\n";
	for(int i=1;i<=n;i++) {
		cout<<"P "<<i<<" 1000 1\n";
	}
	cout<<"Z 1 "<<n;
}
