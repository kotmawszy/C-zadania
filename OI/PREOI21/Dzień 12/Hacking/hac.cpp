#include <bits/stdc++.h>
using namespace std;

long long n;
vector<pair<int,int> > factors;
int last;
vector<int> ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n;

	for(int i=2;n>1;i++) {
		if(n%i==0) {
			last=factors.size();
			factors.push_back({i,0});
		}
		while(n%i==0) {
			factors[last].second++;
			n/=i;
		}
	}
	int c=1;
	int s=0;
	int m=0;
	for(pair<int,int> i : factors) {
		for(int j=0;j<i.second;j++) {
			m+=c;
			for(int k=0;k<i.first;k++) {
				ans.push_back(c);
				s+=c;
			}
			c=s;
		}
	}
	cout<<ans.size()<<" "<<m<<"\n";
	for(int i : ans) cout<<i<<" ";
}
