#include <bits/stdc++.h>
using namespace std;

int n,m;
int* p;
int* q;
vector<int>* g;
bool* allowed;
int a,b;
bool* vis;
vector<vector<int> > components;
bool podzadanie2 = true;
bool podzadanie3 = true;

void dfs1(int v) {
	if(vis[v]) return;
	vis[v]=1;
	components[components.size()-1].push_back(v);
	for(int u : g[v]) if(allowed[u]) dfs1(u);
}

pair<int,int> dfs2(int v) {
	if(vis[v]) return {0,0};
	vis[v]=1;
	pair<int,int> best = {0,0};
	for(int u : g[v]) if(allowed[u]) best=max(best,dfs2(u));
	if(best.first==0) best.second=v;
	best.first++;
	return best;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>m;

	p = new int[n+1];
	for(int i=1;i<=n;i++) cin>>p[i];
	q = new int[n+1];
	for(int i=1;i<=n;i++) {
		cin>>q[i];
		if(q[i]>500) podzadanie3 = false;
		if(q[i]!=p[i]) podzadanie2 = false;
	}

	g = new vector<int>[n+1];
	for(int i=1;i<n;i++) {
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	// if(podzadanie2) {
	// 	components
	// 	return 0;
	// }

	if(podzadanie3) {
		allowed = new bool[n+1];
		vis = new bool[n+1];
		int answers[501];
		for(int a=0;a<=500;a++) {
			for(int i=1;i<=n;i++) {
				allowed[i]=(a<=q[i] && a>=p[i]);
				vis[i]=!allowed[i];
			}
			components.clear();
			for(int i=1;i<=n;i++) if(!vis[i]) {
				components.push_back(vector<int>());
				dfs1(i);
			}
			if(components.size()==0) {
				answers[a]=0;
				continue;
			}
			int maxx=1;
			for(vector<int> i : components) if(i.size()) {
				for(int j : i) vis[j]=0;
				int najd = dfs2(i[0]).second;
				for(int j : i) vis[j]=0;
				maxx=max(maxx, dfs2(najd).first);
			}
			answers[a]=maxx-1;
		}
		while(m--) {
			cin>>a;
			if(a>500) cout<<"0\n";
			else cout<<answers[a]<<"\n";
		}
		return 0;
	}

	allowed = new bool[n+1];
	vis = new bool[n+1];
	while(m--) {
		cin>>a;
		for(int i=1;i<=n;i++) {
			allowed[i]=(a<=q[i] && a>=p[i]);
			vis[i]=!allowed[i];
		}
		components.clear();
		for(int i=1;i<=n;i++) if(!vis[i]) {
			components.push_back(vector<int>());
			dfs1(i);
		}
		if(components.size()==0) {
			cout<<"0\n";
			continue;
		}
		int maxx=1;
		for(vector<int> i : components) if(i.size()) {
			for(int j : i) vis[j]=0;
			int najd = dfs2(i[0]).second;
			for(int j : i) vis[j]=0;
			maxx=max(maxx, dfs2(najd).first);
		}
		cout<<maxx-1<<"\n";
	}
}
