#include <bits/stdc++.h>
using namespace std;

long long MOD = 1e9+7;

long long pot(long long a, int b) {
	if(b==0) return 1;
	if(b%2) return pot(a,b-1)*a%MOD;
	long long c = pot(a,b/2);
	return c*c%MOD;
}

int n,q;
map<int,int> m;
int* tab;
int* queries;
int t;
int lv=1;
pair<long long,long long>* d;

void updateVertex(int v) {
	d[v]=make_pair(
		(d[2*v].first * pot(2,d[2*v+1].second)%MOD + d[2*v+1].first)%MOD,
		d[2*v].second + d[2*v+1].second
	);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>q;

	tab = new int[n+1];
	for(int i=1;i<=n;i++) {
		cin>>tab[i];
		m[tab[i]]=1;
	}

	queries = new int[q+1];
	for(int i=1;i<=q;i++) {
		cin>>queries[i];
		if(queries[i]>0)m[queries[i]]=1;
	}

	map<int,int>::iterator i = m.begin();
	for(int j=1;i!=m.end();i++,j++) i->second=j;
	t=m.size();

	while(lv<t) lv*=2;
	d = new pair<long long,long long>[2*lv];
	for(int i=1;i<2*lv;i++) d[i]=make_pair(0,0);
	for(int i=1;i<=n;i++) {
		int index = lv+m[tab[i]]-1;
		d[index].first++;
		d[index].second=1;
	}
	for(int i=lv-1;i>=1;i--) {
		updateVertex(i);
	}
	for(int i=1;i<=q;i++) {
		int v = lv+m[abs(queries[i])]-1;
		if(queries[i]>0) d[v].first++;
		else d[v].first--;
		d[v].second=(bool)d[v].first;
		for(v/=2;v;v/=2) updateVertex(v);
		cout<<d[1].first<<"\n";
	}
}
