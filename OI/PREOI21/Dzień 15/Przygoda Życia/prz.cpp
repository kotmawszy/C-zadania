#include <bits/stdc++.h>
using namespace std;

int n,m;
int* p;
int* q;
vector<int>* g;
int a,b;
int* parent;
int* s;

void dfsRoot(int v) {
	s[v]=1;
	for(int u : g[v]) if(parent[u]==0) {
		parent[u]=v;
		dfsRoot(u);
		s[v]+=s[u];
	}
}

int getCentroid(int v) {
	pair<int,int> maxs={0,0};
	for(int u : g[v]) if(u!=parent[v]) {
		maxs=max(maxs,{s[u],u});
	}
	if(2*maxs.first<n) return v;
	return getCentroid(maxs.second);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>m;

	p = new int[n+1];
	for(int i=1;i<=n;i++) cin>>p[i];
	q = new int[n+1];
	for(int i=1;i<=n;i++) cin>>q[i];

	g = new vector<int>[n+1];
	for(int i=1;i<n;i++) {
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	s = new int[n+1];
	parent = new int[n+1];
	parent[1]=1;
	for(int i=2;i<=n;i++) parent[i]=0;
	dfsRoot(1);
	cout<<getCentroid(1)<<"\n";

}
