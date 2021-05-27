#include <bits/stdc++.h>
using namespace std;

int n;
int x;
int* y;
stack<int> s;
int sum=1;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n;
	y = new int[n+1];
	for(int i=1;i<=n;i++) cin>>x>>y[i];

	s.push(0);
	s.push(y[1]);
	for(int i=2;i<=n;i++) {
		if(y[i]>y[i-1]) {
			s.push(y[i]);
			sum++;
		} else if(s.top()>y[i]) {
			while(s.top()>y[i]) s.pop();
			if(y[i]!=s.top()) {
				s.push(y[i]);
				sum++;
			}
		}
	}
	cout<<sum<<"\n";
}
