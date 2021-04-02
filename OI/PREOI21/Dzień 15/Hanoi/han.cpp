#include <bits/stdc++.h>
using namespace std;

long long MOD = 1e9+7;

long long pot(long long a, long long b) {
	if(b==0) return 1;
	if(b%2) return a*pot(a,b-1)%MOD;
	long long c=pot(a,b/2);
	return c*c%MOD;
}

int n,q,a;
multiset<int> s;
set<int> pomocniczysecik;
long long* dp;
vector<int> tab;
bool podzadanie2 = true;
int* queries;

long long f(int n) {
	if(n==0) return 0;
	int k=1;
	for(int i=n-1;i>=0 && tab[i]==tab[i+1];i--) k++;
	return (2*f(n-k)+k)%MOD;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>q;
	queries = new int[q];
	for(int i=1;i<=n;i++) {
		cin>>a;
		if(pomocniczysecik.find(a)!=pomocniczysecik.end()) podzadanie2=false;
		pomocniczysecik.insert(a);
		s.insert(a);
	}
	for(int i=0;i<q;i++) {
		cin>>queries[i];
		if(queries[i]>0) {
			if(pomocniczysecik.find(queries[i]) != pomocniczysecik.end()) podzadanie2=false;
			pomocniczysecik.insert(queries[i]);
		} else {
			auto x = pomocniczysecik.find(-queries[i]);
			if(x != pomocniczysecik.end()) pomocniczysecik.erase(x);
		}
	}

	if(podzadanie2) {
		for(int i=0;i<q;i++) {
			if(queries[i]>0) n++;
			else n--;
			cout<<pot(2,n)-1<<"\n";
		}
		return 0;
	}

	tab.clear();
	tab.push_back(0);
	for(int i : s) tab.push_back(i);
	
	cout<<f(n)<<"\n";

	for(int i=0;i<q;i++) {
		if(queries[i]>0) {
			s.insert(queries[i]);
			n++;
		} else {
			auto x = s.find(-queries[i]);
			if(x != s.end()) s.erase(x);
			n--;
		}
		tab.clear();
		tab.push_back(0);
		for(int i : s) tab.push_back(i);

		cout<<f(n)<<"\n";
	}

}
