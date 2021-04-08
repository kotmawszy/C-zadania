#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
int n;
pii* p;
vector<int> v;

long long getProduct(pii a, pii b, pii c) {
	b.first-=a.first;
	b.second-=a.second;
	c.first-=a.first;
	c.second-=a.second;
	return (long long)b.first * (long long)c.second - (long long)b.second * (long long)c.first;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n;
	p = new pii[n];
	for(int i=0;i<n;i++) cin>>p[i].first>>p[i].second;
	sort(p,p+n);

	v.push_back(0);
	v.push_back(1);
	for(int i=2;i<n;i++) {
		while(v.size()>=2 && getProduct(p[v[v.size()-2]],p[v[v.size()-1]],p[i])>0) v.pop_back();
		v.push_back(i);
	}
	int o=v.size();
	v.clear();
	v.push_back(0);
	v.push_back(1);
	for(int i=2;i<n;i++) {
		while(v.size()>=2 && getProduct(p[v[v.size()-2]],p[v[v.size()-1]],p[i])<0) v.pop_back();
		v.push_back(i);
	}
	o+=v.size()-2;
	cout<<2*n-o-3<<"\n";
}
